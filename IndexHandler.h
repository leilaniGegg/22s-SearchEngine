//
// Created by leila on 4/12/2022.
//

#ifndef INC_22S_FINAL_PROJ_INDEXHANDLER_H
#define INC_22S_FINAL_PROJ_INDEXHANDLER_H
#include "AVLTree.h"
#include "Word.h"
class IndexHandler{
private:
    AVLTree<Word> wordIndex;
    AVLTree<Word> peopleIndex; //don't need for speed test
    AVLTree<Word> organizationsIndex;

public:
    void writeToWordIndex(Word& x);
    AVLTree<Word>& getWordIndex();
};
#endif //INC_22S_FINAL_PROJ_INDEXHANDLER_H
