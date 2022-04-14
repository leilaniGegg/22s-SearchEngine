//
// Created by leila on 4/11/2022.
//

#include "Word.h"

Word::Word(){
    word = "";
}

Word::Word(string word){
    this->word = word;
}

Word::~Word(){
    /*for(int i = 0; i < articles.size(); i++){
        delete articles.at(i);
    }*/
}
Word::Word(const Word& temp){
    this->word = temp.word;
    this->articles = temp.articles;
    this->frequency = temp.frequency;
}
Word& Word::operator=(const Word& temp){
    this->word = temp.word;
    this->articles = temp.articles;
    this->frequency = temp.frequency;
    return *this;
}

Word& Word::operator=(const string& temp){
    this->word = temp;
    return *this;
}
bool Word::operator<(const Word& temp)const{
    if(this->word < temp.word){
        return true;
    }
    return false;
}

vector<Article>& Word::getArticles(){
    return articles;
}

Word& Word::operator+(const Word& temp){
    this->frequency++;
    if(!count(this->articles.begin(), this->articles.end(), temp.articles.at(0))){
        this->addArticle(temp.articles.at(0));
    }

    return *this;
}

bool Word::operator==(const Word& temp)const{
   if(this->word == temp.word){
       return true;
   }
   return false;
}

void Word::addArticle(const Article& article){
    articles.push_back(article);
}

string Word::getWord(){
    return word;
}

void Word::displayArticles(){
    for(int i = 0; i < articles.size(); i++){
        cout << articles.at(i).getUUID() << endl;
    }
}