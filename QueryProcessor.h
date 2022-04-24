//
// Created by leila on 4/12/2022.
//

#ifndef INC_22S_FINAL_PROJ_QUERYPROCESSOR_H
#define INC_22S_FINAL_PROJ_QUERYPROCESSOR_H

#include <string>
#include <set>
#include <sstream>
#include <algorithm>
#include "IndexHandler.h"
#include "Article.h"

using namespace std;

class QueryProcessor{
private:

public:
    void findWord(const string& request, IndexHandler& indexer); // for timing demo
    void query(const string& request, IndexHandler& indexer); //indexer has AVL tree for words and hash maps for person and orgs
    void addArticles(const string& op, const string& word1, const string& word2, set<Article>& matches, IndexHandler& indexer);
    void addArticle(const string& word1, set<Article>& matches, IndexHandler& indexer); //for single word queries
    void removeArticles(const string& word1, set<Article>& matches, IndexHandler& indexer);
};
#endif //INC_22S_FINAL_PROJ_QUERYPROCESSOR_H
