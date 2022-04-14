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
    Word test1("taco");
    Word test2("pizza");
    Word test3("gian");
    Word test4("religion");
    AVLTree<Word> tree;
    tree.insert(test1);
    tree.insert(test2);
    tree.insert(test3);
    tree.insert(test4);

    SearchEngine temp;
    temp.processCorpus("../testdata");
    rapidjson::Document doc;
    /*
    ifstream file("../testdata/blogs_0000001.json");
    if(!file.is_open()){
        cout << "failed to open" << endl;
    }
    string fullfile;
    string line;
    while(getline(file, line)){
        fullfile += line;
    }
    file.close();
    doc.Parse(fullfile.c_str());
    string uuid = doc["uuid"].GetString();
    cout << uuid << endl;
    if(doc.IsObject()){
        cout <<  "its an object woo" << endl;
    }

    string title = doc["title"].GetString();
    string url = doc["url"].GetString();
    cout << "Title: " << title << endl;
    cout << "URL: " << url << endl;
*/
    return 0;
}