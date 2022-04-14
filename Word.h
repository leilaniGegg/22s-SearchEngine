//
// Created by leila on 4/11/2022.
//

#ifndef INC_22S_FINAL_PROJ_WORD_H
#define INC_22S_FINAL_PROJ_WORD_H
#include <string>
#include <vector>
#include <algorithm>
#include "Article.h"

using namespace std;

class Word{
private:
    string word;
    vector<Article> articles;
    int frequency = 0;
public:
    Word();
    Word(string word);
    ~Word();
    Word(const Word& temp);
    Word& operator=(const Word& temp);
    Word& operator=(const string& temp);
    string getWord();
    bool operator<(const Word& temp)const;
    Word& operator+(const Word& temp);
    vector<Article>& getArticles();
    void addArticle(const Article& article);
};
#endif //INC_22S_FINAL_PROJ_WORD_H
