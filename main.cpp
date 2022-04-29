#include <iostream>
#include <string>
#include "include/rapidjson/document.h"
#include "SearchEngine.h"
#include "HashTable.h"
#include "Article.h"
#include <chrono>


using namespace std;

int main(int argc, char** argv) {
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    start = std::chrono::high_resolution_clock::now();
    SearchEngine temp;
    temp.processCorpus(argv[2]); //input will be argv[2]
    //temp.parseQuery("AND market hour NOT spot ORG cnbc"); //input will be argv[1]
    end = std::chrono::high_resolution_clock::now();
    cout << std::chrono::duration<double>(end-start).count() << endl;
    /*HashTable<string, set<Article>> table;
    Article temp1("12345");
    Article temp2("54321");
    Article temp3("32415");
    set<Article> set1;
    set<Article> set2;
    set1.insert(temp1);
    set1.insert(temp3);
    set2.insert(temp3);
    set2.insert(temp2);
    table.insert("taco", set1);
    table.insert("burger", set2);
    table.insert("coffee", set1);
    table.insert("burger", set2);

    table.display();*/

    return 0;
}