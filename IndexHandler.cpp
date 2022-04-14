//
// Created by leila on 4/12/2022.
//

#include "IndexHandler.h"

void IndexHandler::writeToWordIndex(const string& x){
    wordIndex.insert(Word(x));
}
AVLTree<Word>& getWordIndex();