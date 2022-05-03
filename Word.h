//
// Created by leila on 4/11/2022.
//

#ifndef INC_22S_FINAL_PROJ_WORD_H
#define INC_22S_FINAL_PROJ_WORD_H
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "Article.h"

using namespace std;

class Word{
private:
    string word;
    vector<Article> articles;
public:
    Word();
    Word(const string& word);
    ~Word();
    Word(const Word& temp);
    Word& operator=(const Word& temp);
    Word& operator=(const string& temp);
    string& getWord();
    bool operator==(const Word& temp)const;
    bool operator<(const Word& temp)const;
    Word& operator+(const Word& temp);
    friend ostream& operator<<(ostream& output, Word& temp);
    vector<Article>& getArticles();
    void addArticle(const Article& article);
    void displayArticles();
};
#endif //INC_22S_FINAL_PROJ_WORD_H
