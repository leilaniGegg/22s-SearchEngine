//
// Created by leila on 4/12/2022.
//

#ifndef INC_22S_FINAL_PROJ_DOCUMENTPARSER_H
#define INC_22S_FINAL_PROJ_DOCUMENTPARSER_H
#include <string>
#include <sstream>
#include <iostream>
#include <dirent.h>
#include "include/rapidjson/document.h"
#include <sys/stat.h>
#include <filesystem>
#include <fstream>
#include "IndexHandler.h"

namespace fs = std::filesystem;

class DocumentParser{
private:
    AVLTree<string> stopWords;
    int articleCount = 0;
public:
    DocumentParser();
    void generateStopWords();
    void readDirectory(const string& directory, IndexHandler& indexer);
    void readWordPersistenceFile(IndexHandler& indexer);
    void readPersonPersistenceFile(IndexHandler& indexer);
    void readOrgPersistenceFile(IndexHandler& indexer);
    void readFile(const string& filename, IndexHandler& indexer);
    void indexArticleWords(const Article& tempArticle, const string& articleText, IndexHandler& indexer);
    //void indexArticlePeople(const Article& tempArticle, const string& articleText, IndexHandler& indexer);
    bool isStopWord(const string& word);
    int getArticleCount();
};
#endif //INC_22S_FINAL_PROJ_DOCUMENTPARSER_H
