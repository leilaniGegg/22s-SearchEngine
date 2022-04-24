//
// Created by leila on 4/12/2022.
//

#include "QueryProcessor.h"
#include "porter2_stemmer/porter2_stemmer.h"

void QueryProcessor::findWord(const string& request, IndexHandler& indexer){
    string tempRequest = request;
    Porter2Stemmer::trim(tempRequest);
    Porter2Stemmer::stem(tempRequest);
    Word temp(tempRequest);
    indexer.getWordIndex().insert(temp)->displayArticles();
}

void QueryProcessor::query(const string& request, IndexHandler& indexer){
    //Request looks like: "AND social network"
    set<Article> matches; //data type may change when hash table is made
    //string currOperator;  //could be AND, OR, NOT
    stringstream inSS(request);
    string tempWord;
    while(getline(inSS, tempWord, ' ')){
        if(tempWord == "AND"){
            string w1, w2;
            getline(inSS, w1, ' ');
            getline(inSS, w2, ' ');
            addArticles(tempWord, w1, w2, matches, indexer);
        }
        else if(tempWord == "OR"){
            string w1, w2;
            getline(inSS, w1, ' ');
            getline(inSS, w2, ' ');
            addArticles(tempWord, w1, w2, matches, indexer);
        }
        else if(tempWord == "NOT"){
            string w1;
            getline(inSS, w1, ' ');
            removeArticles(w1, matches, indexer);
        }
        else{ //normal word
            string w1;
            getline(inSS, w1, ' ');
            addArticle(w1, matches, indexer);
        }
    }

}

void QueryProcessor::addArticles(const string& op, const string& word1, const string& word2,
                                 set<Article>& matches, IndexHandler& indexer){
    if(op == "AND") {
        vector<Article> *word1Articles = &(indexer.getWordIndex().insert(Word(word1))->getArticles());
        vector<Article> *word2Articles = &(indexer.getWordIndex().insert(Word(word2))->getArticles());
        set_intersection(word1Articles->begin(), word1Articles->end(), word2Articles->begin(), word2Articles->end(), matches.begin());
    }
    else if(op == "OR"){
        vector<Article> *word1Articles = &(indexer.getWordIndex().insert(Word(word1))->getArticles());
        vector<Article> *word2Articles = &(indexer.getWordIndex().insert(Word(word2))->getArticles());
        set_union(word1Articles->begin(), word1Articles->end(), word2Articles->begin(), word2Articles->end(), matches.begin());
    }
}

void QueryProcessor::addArticle(const string& word1, set<Article>& matches, IndexHandler& indexer){
    //if single word query just add all the words articles to matches set
     vector<Article>* temp = &(indexer.getWordIndex().insert(Word(word1))->getArticles());
     for(int i = 0; i < temp->size(); i++){
         matches.insert(temp->at(i));
     }
}

void QueryProcessor::removeArticles(const string& word1, set<Article>& matches, IndexHandler& indexer){
    //I think this will work, will find the difference and result in set with elements in matches but not in word1Articles
    vector<Article> *word1Articles = &(indexer.getWordIndex().insert(Word(word1))->getArticles());
    set_difference(matches.begin(), matches.end(), word1Articles->begin(), word1Articles->end(), matches.begin());
}