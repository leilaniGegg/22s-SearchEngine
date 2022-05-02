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
    matches.clear(); // clear matches from the previous query
    string currOperator;  //could be AND, OR, NOT
    stringstream inSS(request);
    string tempWord;
    vector<string> tempList;
    while(getline(inSS, tempWord, ' ')){
        Porter2Stemmer::trim(tempWord);
        Porter2Stemmer::stem(tempWord);
        if(tempWord == "and"){
            if(currOperator != tempWord && currOperator != ""){
                addArticles(currOperator, tempList, indexer);
            }
            currOperator = tempWord;
            tempList.clear();
        }
        else if(tempWord == "or"){
            if(currOperator != tempWord && currOperator != ""){
                addArticles(currOperator, tempList, indexer);
            }
            currOperator = tempWord;
            tempList.clear();
        }
        else if(tempWord == "not"){
            if(currOperator != tempWord){
                //removeArticles(tempList, indexer);
                //the only operator between
                if(tempList.size() == 1){
                    addArticle(tempList.at(0), indexer);
                }
                else{
                    addArticles(currOperator, tempList, indexer);
                }
            }
            else if(currOperator == ""){
                addArticle(tempList.at(0), indexer);
            }
            currOperator = tempWord;
            tempList.clear();
        }
        else if(tempWord == "person"){
               //only have one word after, no need to add to templist
               cout << "here" << endl;
                getline(inSS, tempWord, ' ');
                addPersonArticles(tempWord, indexer);
        }
        else if(tempWord == "org"){
            //only have one word after, no need to add to templist
            getline(inSS, tempWord, ' ');
            addOrgArticles(tempWord, indexer);
        }
        else{ //normal word
            tempList.push_back(tempWord);
        }
    }
    //these are for when there is no ORG or PERSON
    if(currOperator == ""){
        addArticle(tempList.at(0), indexer);
    }
    else if(currOperator == "and" || currOperator == "or") {
        addArticles(currOperator, tempList, indexer); //will need to add checks for if its AND or OR or NOT, etc
    }
    else if(currOperator == "not"){
        removeArticles(tempList, indexer);
    }
}

void QueryProcessor::addArticles(const string& op, vector<string>& words, IndexHandler& indexer){
    if(op == "and") {
        // add all the articles from the first word to the matches
        vector<Article>* firstWord = &(indexer.getWordIndex().insert(Word(words.at(0)))->getArticles());
        for(int i = 0; i < firstWord->size(); i++){
            matches.insert(firstWord->at(i));
        }
        for(int i = 1; i < words.size(); i++){
            //vector<Article> templist;
            vector<Article> *word1Articles = &(indexer.getWordIndex().insert(Word(words.at(i)))->getArticles());
            vector<Article> deleteThese;
            for(auto itr = matches.begin(); itr != matches.end(); itr++){
                if(find(word1Articles->begin(), word1Articles->end(), *itr) == word1Articles->end()){
                    deleteThese.push_back(*itr);
                }
            }
            if(!deleteThese.empty()) {
                for (int j = 0; j < word1Articles->size(); j++) {
                    matches.erase(deleteThese.at(i));
                }
            }
        }
    }
    else if(op == "or"){
        // add all the articles from the first word to the matches
        vector<Article>* firstWord = &(indexer.getWordIndex().insert(Word(words.at(0)))->getArticles());
        for(int i = 0; i < firstWord->size(); i++){
            matches.insert(firstWord->at(i));
        }
        for(int i = 1; i < words.size(); i++){
            //vector<Article> templist;
            vector<Article> *word1Articles = &(indexer.getWordIndex().insert(Word(words.at(i)))->getArticles());
            for(int j = 0; j < word1Articles->size();j++){
                if(find(matches.begin(), matches.end(), word1Articles->at(j)) == matches.end()){ //means the current article is not already in matches
                    matches.insert(word1Articles->at(j));
                }
            }
        }
    }
}

void QueryProcessor::addArticle(const string& word1, IndexHandler& indexer){
    //if single word query just add all the words articles to matches set
     vector<Article>* temp = &(indexer.getWordIndex().insert(Word(word1))->getArticles());
     for(int i = 0; i < temp->size(); i++){
         matches.insert(temp->at(i));
     }
}

void QueryProcessor::addPersonArticles(const string& person, IndexHandler& indexer){
    set<Article>* temp = &(indexer.getPersonIndex().at(person));
    vector<Article> deleteThese;
    for(auto itr = matches.begin(); itr != matches.end(); itr++){
        if(find(temp->begin(), temp->end(), *itr) == temp->end()){
            deleteThese.push_back(*itr);
        }
    }
    if(!deleteThese.empty()) {
        for (int j = 0; j < temp->size(); j++) {
            matches.erase(deleteThese.at(j));
        }
    }
}

void QueryProcessor::addOrgArticles(const string& org, IndexHandler& indexer){
    set<Article>* temp = &(indexer.getOrgIndex().at(org));
    vector<Article> deleteThese;
    for(auto itr = matches.begin(); itr != matches.end(); itr++){
        if(find(temp->begin(), temp->end(), *itr) == temp->end()){
            deleteThese.push_back(*itr);
        }
    }
    if(!deleteThese.empty()) {
        for (int j = 0; j < temp->size(); j++) {
            matches.erase(deleteThese.at(j));
        }
    }
}

void QueryProcessor::removeArticles(vector<string> words, IndexHandler& indexer){
    //I think this will work, will find the difference and result in set with elements in matches but not in word1Articles

    for(int i = 0; i < words.size(); i++) {
        vector<Article>* temp = &(indexer.getWordIndex().insert(Word(words.at(i)))->getArticles());
        for(int j = 0; j < temp->size(); j++){
            matches.erase(temp->at(j));
        }
    }
}

void QueryProcessor::printMatches(){
    auto itr = matches.begin();
    if(getSize() >= 15) {
        for (int i = 0; i < 15; i++, itr++) {
            cout << "Article " << i + 1 << " Title: ";
            itr->displayTitle();
            cout << "\n\tDate Published: ";
            itr->displayDate();
            cout << endl;
        }
    }
    else{
        for(int count = 1; itr != matches.end();count++, itr++){
            cout << "Article " << count << " Title: ";
            itr->displayTitle();
            cout <<  "\nDate Published: ";
            itr->displayDate();
            cout << endl;
        }
    }
}

set<Article>& QueryProcessor::getMatches(){
    return matches;
}

int QueryProcessor::getSize(){
    return matches.size();
}