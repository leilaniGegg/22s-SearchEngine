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
Article::Article(string title, string filename, string uuid, string date){
    this->title = title;
    this->filename = filename;
    this->uuid = uuid;
    this->date = date;
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

string Article::getTitle(){
    return title;
}
string Article::getFileName(){
    return filename;
}
string Article::getUUID(){
    return uuid;
}
string Article::getDate(){
    return date;
}