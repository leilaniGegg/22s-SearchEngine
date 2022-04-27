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
    set<Article> matches; //data type may change when hash table is made
public:
    void findWord(const string& request, IndexHandler& indexer); // for timing demo
    void query(const string& request, IndexHandler& indexer); //indexer has AVL tree for words and hash maps for person and orgs
    void addArticles(const string& op, vector<string>& words, IndexHandler& indexer);
    void addArticle(const string& word1, IndexHandler& indexer); //for single word queries
    void addPersonArticles(const string& person, IndexHandler& indexer);
    void addOrgArticles(const string& person, IndexHandler& indexer);
    void removeArticles(vector<string> words, IndexHandler& indexer);
    void printMatches();
};
#endif //INC_22S_FINAL_PROJ_QUERYPROCESSOR_H
