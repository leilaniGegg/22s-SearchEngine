#include <iostream>
#include <string>
#include "include/rapidjson/document.h"
#include "SearchEngine.h"
#include "HashTable.h"
#include "Article.h"
#include <chrono>


using namespace std;

int main(int argc, char** argv) {
    SearchEngine temp;
    temp.processCorpus(argv[2]); //input will be argv[2]
    //temp.parseQuery("AND market hour NOT spot ORG cnbc"); //input will be argv[1]

    return 0;
}