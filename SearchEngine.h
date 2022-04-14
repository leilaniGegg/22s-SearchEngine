//
// Created by leila on 4/12/2022.
//

#ifndef INC_22S_FINAL_PROJ_SEARCHENGINE_H
#define INC_22S_FINAL_PROJ_SEARCHENGINE_H
#include "DocumentParser.h"
#include "IndexHandler.h"
#include "QueryProcessor.h"

class SearchEngine{
private:
    DocumentParser docPars;
    IndexHandler indexer;
    QueryProcessor query;
public:
    void processCorpus(const string& directoryName);
    //for speed demo
    void parseQuery(const string& request);

};
#endif //INC_22S_FINAL_PROJ_SEARCHENGINE_H
