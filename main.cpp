#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <dirent.h>
#include "include/rapidjson/document.h"
#include "Word.h"
#include "AVLTree.h"
#include "SearchEngine.h"
#include "porter2_stemmer/porter2_stemmer.h"


using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;

    SearchEngine temp;
    temp.processCorpus("../testdata"); //input will be argv[2]
    temp.parseQuery("emerging"); //input will be argv[1]
    rapidjson::Document doc;

    return 0;
}