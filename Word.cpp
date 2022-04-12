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

bool Word::operator<(const Word& temp){
    if(this->word < temp.word){
        return true;
    }
    return false;
}

string Word::getWord(){
    return word;
}


