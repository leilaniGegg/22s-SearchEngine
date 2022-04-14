//
// Created by leila on 4/12/2022.
//

#ifndef INC_22S_FINAL_PROJ_DOCUMENTPARSER_H
#define INC_22S_FINAL_PROJ_DOCUMENTPARSER_H
#include <string>

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
    vector<string> stopWords;
public:
    DocumentParser();
    void generateStopWords();
    void open_dir_using_filesystem(const string& directory, IndexHandler& indexer);
    void readFile(const string& filename, IndexHandler& indexer);
    void indexArticleWords(const Article& tempArticle, const string& articleText, IndexHandler& indexer);
    bool isStopWord(string word);
};
#endif //INC_22S_FINAL_PROJ_DOCUMENTPARSER_H
