//
// Created by leila on 4/12/2022.
//

#include "IndexHandler.h"

void IndexHandler::writeToWordIndex(Word& x){
    wordIndex.insert(x);
}
AVLTree<Word>& getWordIndex();