//
// Created by leila on 4/12/2022.
//

#include "DocumentParser.h"

void DocumentParser::open_dir_using_filesystem(const string& directory, IndexHandler& indexer){
    for (const auto & entry : fs::recursive_directory_iterator(directory)){
        if (entry.is_regular_file()) {
            cout << "in first if" << endl;
            if (entry.path().extension().string() == ".json") {
                cout << "in inner if" << endl;
                string filename = entry.path().c_str();
                readFile(filename);
                //std::cout << filename << std::endl;
            }
        }
    }
}

void DocumentParser::readFile(const string& filename){
    rapidjson::Document doc;
    ifstream file(filename);
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
    Article temp(doc["title"].GetString(), filename, doc["uuid"].GetString(), doc["published"].GetString());
    cout << "Title: " << doc["title"].GetString() << endl;


}

void indexArticleWords(const Article& tempArticle, const string& articleText){

}