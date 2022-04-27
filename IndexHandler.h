//
// Created by leila on 4/12/2022.
//

#ifndef INC_22S_FINAL_PROJ_INDEXHANDLER_H
#define INC_22S_FINAL_PROJ_INDEXHANDLER_H
#include "AVLTree.h"
#include "Word.h"
#include <iostream>
using namespace std;

class IndexHandler{
private:
    AVLTree<Word> wordIndex;
    AVLTree<Word> personIndex;
    AVLTree<Word> orgIndex;
    //here will be AVLTree for for people and organizations( or hashmap)

public:
    void writeToWordIndex(const string& x, const Article& tempArticle);
    void writeToPersonIndex(const string& x, const Article& tempArticle);
    void writeToOrgIndex(const string& x, const Article& tempArticle);
    AVLTree<Word>& getWordIndex();
    AVLTree<Word>& getPersonIndex();
    AVLTree<Word>& getOrgIndex();
};
#endif //INC_22S_FINAL_PROJ_INDEXHANDLER_H
