#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <dirent.h>
#include "include/rapidjson/document.h"
#include "Word.h"
#include "AVLTree.h"
#include "SearchEngine.h"


using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
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