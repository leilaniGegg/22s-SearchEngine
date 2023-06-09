//
// Created by leila on 4/11/2022.
//

#include "Article.h"

Article::Article(){
    title = "";
    filename = "";
    uuid = "";
    date = "";
}
Article::Article(const string& title,const string& filename, const string& uuid, const string& date){
    this->title = title;
    this->filename = filename;
    this->uuid = uuid;
    this->date = date;
}

Article::Article(const string& uuid){
    this->uuid = uuid;
    title = "";
    filename = "";
    date = "";
}

Article::Article(const Article& temp){
    this->title = temp.title;
    this->filename = temp.filename;
    this->uuid = temp.uuid;
    this->date = temp.date;
}
Article::~Article(){

}
Article& Article::operator=(const Article& temp){
    this->title = temp.title;
    this->filename = temp.filename;
    this->uuid = temp.uuid;
    this->date = temp.date;
    return *this;
}

bool Article::operator<(const Article& temp)const{
    if(this->date < temp.date){
        return true;
    }
    return false;
}

bool Article::operator==(const Article& temp)const{
    if(this->uuid == temp.uuid){
        return true;
    }
    return false;
}

ostream& operator<<(ostream& output, const Article& temp){
    output << temp.title << '~' << temp.filename << '~' << temp.uuid << '~' << temp.date << '\t';
    return output;
}
string& Article::getTitle(){
    return title;
}
void Article::displayTitle()const{
    cout << title;
}

void Article::displayDate()const{
    cout << date;
}

string& Article::getFileName(){
    return filename;
}
string& Article::getUUID(){
    return uuid;
}
string& Article::getDate(){
    return date;
}

void Article::printArticleText(HashTable<string, set<string>>& table)const{
    cout << "[" << title << "]" << endl;
    cout << *table.at(this->uuid).begin() << endl;
}