//
// Created by leila on 4/12/2022.
//

#include "SearchEngine.h"

void SearchEngine::processCorpus(const string& directoryName){
    docPars.open_dir_using_filesystem(directoryName, indexer);
}

void SearchEngine::parseQuery(const string& request){
    // call function from QueryProcessor and send the request and indexer
    query.query(request, indexer);
    query.printMatches();
}