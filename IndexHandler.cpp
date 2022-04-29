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
    set<Article> temp;
    temp.insert(tempArticle);
    orgIndex.insert(x, temp);
}

void IndexHandler::writeWordIndexToFile(){
    ofstream file;
    file.open("../persistence_file.txt");
    if(!file.is_open()){
        cout << "Failed to open file" << endl;
    }
    //file << wordIndex;
    wordIndex.printBreadthFirstTraversal(file);
    file.close();
}

void IndexHandler::writePersonIndexToFile(){

}

void IndexHandler::writeOrgIndexToFile(){

}

AVLTree<Word>& IndexHandler::getWordIndex(){
    return wordIndex;
}

HashTable<string, set<Article>>& IndexHandler::getPersonIndex(){
    return personIndex;
}

HashTable<string, set<Article>>& IndexHandler::getOrgIndex(){
    return orgIndex;
}