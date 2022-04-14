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
    AVLTree<Word> peopleIndex; //don't need for speed test
    AVLTree<Word> organizationsIndex;

public:
    void writeToWordIndex(const string& x, const Article& tempArticle);
    AVLTree<Word>& getWordIndex();
};
#endif //INC_22S_FINAL_PROJ_INDEXHANDLER_H
