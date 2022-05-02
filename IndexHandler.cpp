//
// Created by leila on 4/12/2022.
//

#include "IndexHandler.h"

//for when reading from the data set
void IndexHandler::writeToWordIndex(const string& x, const Article& tempArticle){
    Word temp(x);
    temp.addArticle(tempArticle);
    wordIndex.insert(temp);
}

//for when reading from the persistence file
void IndexHandler::writePFileToWordIndex(const Word& x){
    wordIndex.insert(x);
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
    file.open("../word_persistence_file.txt");
    if(!file.is_open()){
        cout << "Failed to open file" << endl;
    }
    wordIndex.printBreadthFirstTraversal(file);
    file.close();
}

void IndexHandler::writePersonIndexToFile(){
    ofstream file;
    file.open("../person_persistence_file.txt");
    if(!file.is_open()){
        cout << "Failed to open file" << endl;
    }
    personIndex.writeToFile(file);
    file.close();
}

void IndexHandler::writeOrgIndexToFile(){
    ofstream file;
    file.open("../org_persistence_file.txt");
    if(!file.is_open()){
        cout << "Failed to open file" << endl;
    }
    orgIndex.writeToFile(file);
    file.close();
}

void IndexHandler::writeArticleTextToFile(){
    ofstream file;
    file.open("../articletext_persistence_file.txt");
    if(!file.is_open()){
        cout << "Failed to open file" << endl;
    }
    articleText.writeToTextFile(file);
    file.close();
}

void IndexHandler::writeArticleTextToIndex(const string& uuid, const string& text){
    set<string> temp;
    temp.insert(text);
    articleText.insert(uuid, temp);
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

HashTable<string, set<string>>& IndexHandler::getArticleText(){
    return articleText;
}