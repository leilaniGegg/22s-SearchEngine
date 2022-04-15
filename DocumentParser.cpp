//
// Created by leila on 4/12/2022.
//

#include "DocumentParser.h"
#include "porter2_stemmer/porter2_stemmer.h"
#include "porter2_stemmer/porter2_stemmer.cpp"

void DocumentParser::generateStopWords(){
    ifstream file("../stopwords.txt");
    if(!file.is_open()){
        std::cout << "failed to open stop words" << std::endl;
    }
    std::string templine;
    while(getline(file, templine)){
        stopWords.push_back(templine);
    }
}

DocumentParser::DocumentParser(){
    generateStopWords();
}



void DocumentParser::open_dir_using_filesystem(const string& directory, IndexHandler& indexer){
    for (const auto & entry : fs::recursive_directory_iterator(directory)){
        if (entry.is_regular_file()) {
            if (entry.path().extension().string() == ".json") {
                std::string filename = entry.path().c_str();
                readFile(filename, indexer);
                std::cout << filename << std::endl;
            }
        }
    }
}

void DocumentParser::readFile(const std::string& filename, IndexHandler& indexer){
    rapidjson::Document doc;
    ifstream file(filename);
    if(!file.is_open()){
        cout << "failed to open" << endl;
    }
    std::string fullfile;
    std::string line;
    while(getline(file, line)){
        fullfile += line;
    }
    file.close();
    doc.Parse(fullfile.c_str());
    Article temp(doc["title"].GetString(), filename, doc["uuid"].GetString(), doc["published"].GetString());
    std::cout << "Title: " << doc["title"].GetString() << std::endl;
    string articleText = doc["text"].GetString();
    indexArticleWords(temp, articleText, indexer);


}

bool DocumentParser::isStopWord(const string& word){
    if (std::count(stopWords.begin(), stopWords.end(), word)){
        return true;
    }
    return false;
}

void DocumentParser::indexArticleWords(const Article& tempArticle, const string& articleText, IndexHandler& indexer){ //not sure if this should just be reference
    stringstream inSS(articleText);
    std::string tempWord;
    AVLTree<string> words;
    while(getline(inSS, tempWord, ' ')){
        if(!isStopWord(tempWord)) {
            Porter2Stemmer::trim(tempWord);
            if (tempWord == ""){ //basically if tempword was a number the trim method makes it null
                continue;
            }
            Porter2Stemmer::stem(tempWord);
            if(words.find(tempWord)){ //if a word from current article is already in the main word index
                continue;
            }
            else {
                words.insert(tempWord);
                indexer.writeToWordIndex(tempWord, tempArticle);
            }
        }
    }
}