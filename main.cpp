#include <iostream>
#include <string>
#include "include/rapidjson/document.h"
#include "SearchEngine.h"
#include "HashTable.h"
#include <chrono>


using namespace std;

int main(int argc, char** argv) {
    /*std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    start = std::chrono::high_resolution_clock::now();
    SearchEngine temp;
    temp.processCorpus(argv[2]); //input will be argv[2]
    temp.parseQuery("hour NOT market"); //input will be argv[1]
    end = std::chrono::high_resolution_clock::now();
    cout << std::chrono::duration<double>(end-start).count() << endl;*/

    HashTable<int, int> test;
    test.insert(1, 1);
    test.insert(2, 2);
    test.insert(2, 3);

    return 0;
}