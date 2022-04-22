//
// Created by leila on 4/12/2022.
//

#ifndef INC_22S_FINAL_PROJ_QUERYPROCESSOR_H
#define INC_22S_FINAL_PROJ_QUERYPROCESSOR_H

#include <string>
#include <set>
#include <sstream>
#include "IndexHandler.h"
#include "Article.h"

using namespace std;

class QueryProcessor{
private:

public:
    void findWord(const string& request, IndexHandler& indexer); // for timing demo
    void query(const string& request, IndexHandler& indexer); //indexer has AVL tree for words and hash maps for person and orgs
};
#endif //INC_22S_FINAL_PROJ_QUERYPROCESSOR_H
