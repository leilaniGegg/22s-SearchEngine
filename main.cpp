#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <dirent.h>
#include "include/rapidjson/document.h"
#include "Word.h"
#include "AVLTree.h"


using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    rapidjson::Document doc;
    AVLTree<Word> test;
    Word temp1("taco");
    Word temp2("banana");
    Word temp3("watermelon");
    test.insert(temp1);
    test.insert(temp2);
    test.insert(temp3);
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

    return 0;
}