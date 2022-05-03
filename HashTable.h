//
// Created by leila on 4/25/2022.
//
// Resources: https://www.geeksforgeeks.org/implementing-hash-table-open-addressing-linear-probing-cpp/?ref=gcse (explained hashtables pretty well)
//

#ifndef INC_22S_FINAL_PROJ_HASHTABLE_H
#define INC_22S_FINAL_PROJ_HASHTABLE_H
#include <vector>
#include <list>
#include <functional>
#include <iostream>
#include <cmath>
#include <typeinfo>
#include <set>
#include "Article.h"

using namespace std;

template <typename K, typename V>
class HashTable{
private:
    int size = 0;
    int capacity = 100000;
    vector<list<pair<K, V>>> table;
public:
    HashTable();
    ~HashTable();
    void clearHashTable();
    void insert(const K& key, const V& value);
    V& deleteNode(const K& key);
    V& at(K key);
    size_t hashFunction(const K& key);
    int sizeOf();
    bool isEmpty();
    void display();
    void writeToFile(ostream& output);
    void writeToTextFile(ostream& output);
};

template <typename K, typename V>
HashTable<K, V>::HashTable(){
    table.resize(capacity);
}

template <typename K, typename V>
HashTable<K, V>::~HashTable(){
    clearHashTable();
}

template <typename K, typename V>
void HashTable<K, V>::clearHashTable(){
    for(int r = 0; r < capacity; r++){
        if(!table[r].empty()){
            auto& row = table[r];
            row.clear();
        }
    }
    for(int r = 0; r < capacity; r++){
        table[r].clear();
    }
    size = 0;
}

template <typename K, typename V>
void HashTable<K, V>::insert(const K& key, const V& value){
    pair<K, V> temp(key, value);
    int hashKey = hashFunction(key);
    if(hashKey < 0){
        hashKey *= -1;
    }
        list <pair<K, V>> &row = table[hashKey];
        bool keyPresent = false;
        //searching through list at current vector hashKey index
        for (auto itr = begin(row); itr != end(row); itr++) {
            if (itr->first == key) { //if the parameter value exists in the current list of values
                keyPresent = true;
                //auto& x = itr->second;
                //this first if is for the articleText hashmap
                if(typeid(itr->second) == typeid(std::string)){
                    itr->second = value;
                }
                else {
                    itr->second.insert(value.begin(), value.end());
                }
                break;
            }
        }
        //checking for collisions
        if (!keyPresent) {
            pair<K, V> newPair(temp);
            table[hashKey].push_back(newPair);
            size++;
        }
}

template <typename K, typename V>
V& HashTable<K, V>::deleteNode(const K& key){
    int hashKey = hashFunction(key);
    if(hashKey < 0){
        hashKey *= -1;
    }
    auto& row = table[hashKey];
    for(auto itr = row.begin(); itr != row.end(); itr++){
        if(itr->first == key){
            auto& temp = itr->second;
            row.erase(itr); //no clue if this works
            return temp;
        }
    }
}

template <typename K, typename V>
V& HashTable<K, V>::at(K key){
    int hashKey = hashFunction(key);
    if(hashKey < 0){
        hashKey *= -1;
    }
    auto& row = table[hashKey];
    bool keyPresent = false;
    //finding empty spot in table to insert
    for(auto itr = row.begin(); itr != row.end(); itr++){
        if(itr->first == key){ //if the parameter value exists in the current list of values
            return itr->second;
        }
    }
}

template <typename K, typename V>
size_t HashTable<K, V>::hashFunction(const K& key){
    hash<K> temp;
    return temp(key)% capacity;
}

template <typename K, typename V>
int HashTable<K, V>::sizeOf(){
    return size;
}

template <typename K, typename V>
bool HashTable<K, V>::isEmpty(){
    if(size == 0){
        return true;
    }
    return false;
}

template <typename K, typename V>
void HashTable<K, V>::display(){
    for(int r = 0; r < capacity; r++){
        if(!table[r].empty()){
            auto& row = table[r];
            for(auto itr = row.begin(); itr != row.end(); itr++){
                cout << "Key: " << itr->first << endl; //?????? bruh
                //print out vector of elements from pairs second value
                auto& pairValue = itr->second;
                cout << "Value: ";
                for (auto itr2 = pairValue.begin(); itr2 != pairValue.end(); itr2++){
                    cout << *itr2 << " ";
                }
                cout << endl << endl;
            }
        }
    }
}

template <typename K, typename V>
void HashTable<K,V>::writeToFile(ostream& output){
    for(auto itr1 = table.begin(); itr1 != table.end(); itr1++){
        //itr2 is a list of pairs
        if(!itr1->empty()){
            auto& row = itr1;
            for(auto itr2 = row->begin(); itr2 != row->end(); itr2++){
                //itr2 is a pair
                output << itr2->first << '|';
                auto& listOfArticles = itr2->second;
                for(auto itr3 = listOfArticles.begin(); itr3 != listOfArticles.end(); itr3++){
                    //itr3 is an article from second part of pair
                    output  << *itr3;
                }
                output << '?'; // delimiter to indicate end of the list of pairs per vector of the table
            }
            output << '\\'; //delimiter to separate each vector of the table
        }
    }
}

template <typename K, typename V>
void HashTable<K, V>::writeToTextFile(ostream& output){
    for(auto itr1 = table.begin(); itr1 != table.end(); itr1++){
        if(!itr1->empty()){
            auto& row = itr1;
            for(auto itr2 = row->begin(); itr2 != row->end(); itr2++){
                output << itr2->first << '|';
                auto& text = itr2->second;
                output << *text.begin() << '\t';
            }
        }
    }
}

#endif //INC_22S_FINAL_PROJ_HASHTABLE_H
