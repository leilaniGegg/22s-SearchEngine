//
// Created by leila on 4/12/2022.
//

#include "IndexHandler.h"

void IndexHandler::writeToWordIndex(const string& x, const Article& tempArticle){
    Word temp(x);
    temp.addArticle(tempArticle);
    wordIndex.insert(temp);
}

void IndexHandler::writeToPersonIndex(const string& x, const Article& tempArticle){
    set<Article> temp;
    temp.insert(tempArticle);
    personIndex.insert(x, temp);
}

void IndexHandler::writeToOrgIndex(const string& x, const Article& tempArticle){
    Word temp(x);
    temp.addArticle(tempArticle);
    orgIndex.insert(temp);
}
AVLTree<Word>& IndexHandler::getWordIndex(){
    return wordIndex;
}

HashTable<string, set<Article>>& IndexHandler::getPersonIndex(){
    return personIndex;
}

AVLTree<Word>& IndexHandler::getOrgIndex(){
    return orgIndex;
}