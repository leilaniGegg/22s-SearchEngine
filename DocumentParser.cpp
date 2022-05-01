//
// Created by leila on 4/12/2022.
//

#include "DocumentParser.h"
#include "porter2_stemmer/porter2_stemmer.h"
#include "porter2_stemmer/porter2_stemmer.cpp"

void DocumentParser::generateStopWords(){
    ifstream file("../stopwords.txt");
    /*if(!file.is_open()){
        std::cout << "failed to open stop words" << std::endl;
    }*/
    std::string templine;
    while(getline(file, templine)){
        stopWords.insert(templine);
    }
    file.close();
}

DocumentParser::DocumentParser(){
    generateStopWords();
}

int DocumentParser::getArticleCount(){
    return articleCount;
}

void DocumentParser::readPersistenceFile(IndexHandler& indexer){
    articleCount = 0;
    ifstream file("../persistence_file.txt");
    if(!file.is_open()){
        cout << "Failed to open file" << endl;
    }
    string line;
    while(getline(file, line, '\\')){
        articleCount++;
        stringstream inSS(line);
        string temp;
        getline(inSS, temp, ' ');
        Word tempWord(temp);
        while(getline(inSS, temp, '\t')){ //delimiter may change
            vector<string> articleAttributes(4);
            stringstream articleInput(temp);
            for (int i = 0; i < 4; i++) {
                getline(articleInput, articleAttributes.at(i), '~');
            }
            Article tempArticle(articleAttributes[0], articleAttributes[1], articleAttributes[2], articleAttributes[3]);
            tempWord.addArticle(tempArticle);
        }
        indexer.writePFileToWordIndex(tempWord);
    }
}

void DocumentParser::readDirectory(const string& directory, IndexHandler& indexer){
    articleCount = 0;
    for (const auto & entry : fs::recursive_directory_iterator(directory)){
        if (entry.is_regular_file()) {
            if (entry.path().extension().string() == ".json") {
                readFile(entry.path().c_str(), indexer); //sending the filename and indexer
                articleCount++;
            }
        }
    }
}

void DocumentParser::readFile(const std::string& filename, IndexHandler& indexer){
    rapidjson::Document doc;
    ifstream file(filename);
    /*if(!file.is_open()){
        cout << "failed to open" << endl;
    }*/
    std::string fullfile;
    std::string line;
    while(getline(file, line)){
        fullfile += line;
    }
    file.close();
    doc.Parse(fullfile.c_str());
    Article temp(doc["title"].GetString(), filename, doc["uuid"].GetString(), doc["published"].GetString());

    for (auto &x : doc["entities"]["persons"].GetArray()) {
        indexer.writeToPersonIndex(x["name"].GetString(), temp);
    }
    for (auto &x : doc["entities"]["organizations"].GetArray()) {
        indexer.writeToOrgIndex(x["name"].GetString(), temp);
    }
    indexArticleWords(temp, doc["text"].GetString(), indexer);

}

bool DocumentParser::isStopWord(const string& word){
    if (stopWords.contains(word)){
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
            //if (tempWord == ""){ //basically if tempword was a number the trim method makes it null
              //  continue;
            //}
            Porter2Stemmer::stem(tempWord);
                if (!words.contains(tempWord)) { //if a word from current article is already in the main word index
                    words.insert(tempWord);
                    indexer.writeToWordIndex(tempWord, tempArticle);
                }
        }
    }
}