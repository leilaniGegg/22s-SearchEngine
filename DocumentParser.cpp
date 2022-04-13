//
// Created by leila on 4/12/2022.
//

#include "DocumentParser.h"

DocumentParser::DocumentParser(){
    generateStopWords();
}

void DocumentParser::generateStopWords(){
    ifstream file("stopwords.txt");
    if(!file.is_open()){
        cout << "failed to open" << endl;
    }
    string templine;
    while(getline(file, templine)){
        stopWords.push_back(templine);
    }
}

void DocumentParser::open_dir_using_filesystem(const string& directory, IndexHandler& indexer){
    for (const auto & entry : fs::recursive_directory_iterator(directory)){
        if (entry.is_regular_file()) {
            cout << "in first if" << endl;
            if (entry.path().extension().string() == ".json") {
                cout << "in inner if" << endl;
                string filename = entry.path().c_str();
                readFile(filename, indexer);
                //std::cout << filename << std::endl;
            }
        }
    }
}

void DocumentParser::readFile(const string& filename, IndexHandler& indexer){
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

bool DocumentParser::isStopWord(string word){
    if (std::count(stopWords.begin(), stopWords.end(), word)){
        return true;
    }
    return false;
}

void DocumentParser::indexArticleWords(const Article& tempArticle, string& articleText, IndexHandler& indexer){ //not sure if this should just be reference
    for (int i = 0, length = articleText.size(); i < length; i++)
    {
        // check whether parsing character is punctuation or not
        if (ispunct(articleText[i]))
        {
            articleText.erase(i--, 1);
            length = articleText.size();
        }
    }

    stringstream inSS(articleText);
    string tempWord;
    while(getline(inSS, tempWord, ' ')){
        if(!isStopWord(tempWord)) {
            Porter2Stemmer::trim(tempWord);
            Porter2Stemmer::stem(tempWord);
            Word temp(tempWord);
            indexer.writeToWordIndex(temp);
        }
    }
}