//
// Created by leila on 4/11/2022.
//

#ifndef INC_22S_FINAL_PROJ_ARTICLE_H
#define INC_22S_FINAL_PROJ_ARTICLE_H
#include <string>

using namespace std;

class Article{
private:
    string title;
    string filename;
    string uuid;
    //string author;
    string date;
    //string text; don't need rn?

public:
    Article();
    Article(const string& title,const string& filename, const string& uuid, const string& date);
    Article(const string& uuid);
    Article(const Article& temp);
    ~Article();
    Article& operator=(const Article& temp);
    bool operator<(const Article& temp)const;
    friend ostream& operator<<(ostream& output, const Article& temp);
    bool operator==(const Article& temp)const; //maybe delete const if it causes problems
    string& getTitle();
    string& getFileName();
    string& getUUID();
    string& getDate();


};
#endif //INC_22S_FINAL_PROJ_ARTICLE_H
