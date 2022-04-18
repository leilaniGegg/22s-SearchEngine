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