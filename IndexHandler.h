//
// Created by leila on 4/12/2022.
//

#ifndef INC_22S_FINAL_PROJ_INDEXHANDLER_H
#define INC_22S_FINAL_PROJ_INDEXHANDLER_H
#include "AVLTree.h"
#include "Word.h"
#include "HashTable.h"
#include "Article.h"
#include <vector>
#include <set>
#include <fstream>
#include <ostream>
#include <iostream>
using namespace std;

class IndexHandler{
private:
    AVLTree<Word> wordIndex;
    //AVLTree<Word> personIndex;
    HashTable<string, set<Article>> personIndex;
    //AVLTree<Word> orgIndex;
    HashTable<string, set<Article>> orgIndex;
    HashTable<string, set<string>> articleText;

public:
    void writeToWordIndex(const string& x, const Article& tempArticle);
    void writePFileToWordIndex(const Word& x);
    void writeToPersonIndex(const string& x, const Article& tempArticle);
    void writeToOrgIndex(const string& x, const Article& tempArticle);
    void writeArticleTextToIndex(const string& uuid, const string& text);
    AVLTree<Word>& getWordIndex();
    HashTable<string, set<Article>>& getPersonIndex();
    HashTable<string, set<Article>>& getOrgIndex();
    HashTable<string, set<string>>& getArticleText();
    void writeWordIndexToFile();
    void writePersonIndexToFile();
    void writeOrgIndexToFile();
    void writeArticleTextToFile();

};
#endif //INC_22S_FINAL_PROJ_INDEXHANDLER_H
