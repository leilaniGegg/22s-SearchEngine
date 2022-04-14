//
// Created by leila on 4/12/2022.
//

#ifndef INC_22S_FINAL_PROJ_QUERYPROCESSOR_H
#define INC_22S_FINAL_PROJ_QUERYPROCESSOR_H

#include <string>
#include "IndexHandler.h"
using namespace std;

class QueryProcessor{
private:

public:
    void findWord(const string& request, IndexHandler& indexer);
};
#endif //INC_22S_FINAL_PROJ_QUERYPROCESSOR_H
