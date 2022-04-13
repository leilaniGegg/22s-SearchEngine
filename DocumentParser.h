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
#include "porter2_stemmer/porter2_stemmer.h"
#include <filesystem>
#include <fstream>
#include "IndexHandler.h"
using namespace std;
namespace fs = std::filesystem;

class DocumentParser{
private:

public:
    void open_dir_using_filesystem(const string& directory, IndexHandler& indexer);
    void readFile(const string& filename);
    void indexArticleWords(const Article& tempArticle, const string& articleText);
};
#endif //INC_22S_FINAL_PROJ_DOCUMENTPARSER_H
