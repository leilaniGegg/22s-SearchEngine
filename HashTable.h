//
// Created by leila on 4/25/2022.
//

#ifndef INC_22S_FINAL_PROJ_HASHTABLE_H
#define INC_22S_FINAL_PROJ_HASHTABLE_H
#include <vector>
#include <list>
#include <functional>
#include <iostream>
#include <cmath>
#include "Article.h"

using namespace std;

template <typename K, typename V>
class HashTable{
private:
    int size = 0;
    int capacity = 100000;
    //pair will be <string, vector<Article>
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
}

template <typename K, typename V>
void HashTable<K, V>::insert(const K& key, const V& value){
    pair<K, V> temp(key, value);
    int hashKey = hashFunction(key);
    if(hashKey < 0){
        hashKey *= -1;
    }
    hashKey %= capacity;
        list <pair<K, V>> &row = table[hashKey];
        bool keyPresent = false;
        //searching through list at current vector hashKey index
        for (auto itr = begin(row); itr != end(row); itr++) {
            if (itr->first == key) { //if the parameter value exists in the current list of values
                keyPresent = true;
                itr->second.insert(value.begin(), value.end());
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
    hashKey %= capacity;
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
    hashKey %= capacity;
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
    return temp(key);
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
#endif //INC_22S_FINAL_PROJ_HASHTABLE_H
