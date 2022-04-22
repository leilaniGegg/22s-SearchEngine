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
    string currOperator;  //could be AND, OR, NOT
    stringstream inSS(request);
    string tempWord;
    while(getline(inSS, tempWord, ' ')){
        if(tempWord == "AND"){
            currOperator = "AND";
        }
        else if(tempWord == "OR"){
            currOperator = "OR";
        }
        else if(tempWord == "NOT"){
            currOperator = "NOT";
        }
        else{ //normal word

        }
    }

}