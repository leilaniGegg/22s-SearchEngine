//
// Created by leila on 4/12/2022.
//

#include "IndexHandler.h"

void IndexHandler::writeToWordIndex(const string& x, const Article& tempArticle){
    Word temp(x);
    temp.addArticle(tempArticle);
    wordIndex.insert(temp);
}
AVLTree<Word>& IndexHandler::getWordIndex(){
    return wordIndex;
}