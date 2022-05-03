//
// Created by leila on 4/12/2022.
//

#ifndef INC_22S_FINAL_PROJ_SEARCHENGINE_H
#define INC_22S_FINAL_PROJ_SEARCHENGINE_H
#include "DocumentParser.h"
#include "IndexHandler.h"
#include "QueryProcessor.h"
#include <iostream>
#include <chrono>

class SearchEngine{
private:
    DocumentParser docPars;
    IndexHandler indexer;
    QueryProcessor query;
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
public:
    SearchEngine();
    void printMenu();
    void parseQuery(const string& request);

};
#endif //INC_22S_FINAL_PROJ_SEARCHENGINE_H
