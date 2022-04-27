//
// Created by leila on 4/25/2022.
//

#ifndef INC_22S_FINAL_PROJ_HASHTABLE_H
#define INC_22S_FINAL_PROJ_HASHTABLE_H
#include <vector>
#include <list>
#include <functional>
#include <iostream>

using namespace std;

template <typename K, typename V>
class HashTableNode{
public:
    K key;
    vector<V> value;
    HashTableNode(K key, V val){
        this->key = key;
        this->value.push_back(val);
    }
};

template <typename K, typename V>
class HashTable{
private:
    int size;
    int capacity;
    vector<list<HashTableNode<K,V>>> table;
public:
    HashTable();
    void insert(K key, V value);
    V deleteNode(K key);
    V at(K key);
    size_t hashFunction(const K& key);
    int sizeOf();
    bool isEmpty();
    void display();
};

template <typename S, typename T>
HashTable<S, T>::HashTable(){
    size = 0;
    capacity = 10;
}

template <typename K, typename V>
void HashTable<K, V>::insert(K key, V value){
    HashTableNode<K,V>* temp = new HashTableNode<K,V>(key, value);
    int hashKey = hashFunction(key);
    hashKey %= capacity;
    auto& row = table[hashKey];
    bool keyPresent = false;
    //finding empty spot in table to insert
        for (auto itr = begin(row); itr != end(row); itr++) {
            if (find(itr->value.begin(), itr->value.end(), value) == itr->value.end()) { //if the parameter value exists in the current list of values
                keyPresent = true;
                itr->value.push_back(value);
                break;
            }
        }
    //checking for collisions
    if(!keyPresent){
        list<HashTableNode<K,V>>* temp2;
        temp2->emplace_back(*temp);
        table.push_back(*temp2); //????
        size++;
    }
}

template <typename K, typename V>
V HashTable<K, V>::deleteNode(K key){
    int hashKey = hashFunction(key);
    hashKey %= capacity;
    auto& row = table[hashKey];
    for(auto itr = row.begin(); itr != row.end(); itr++){
        if(itr.key == key){
            HashTableNode<K,V>* temp = *itr;
            delete itr; //no clue if this works
            return temp->value;
        }
    }
}

template <typename K, typename V>
V HashTable<K, V>::at(K key){
    int hashKey = hashFunction(key);
    hashKey %= capacity;
    auto& row = table[hashKey];
    bool keyPresent = false;
    //finding empty spot in table to insert
    for(auto itr = row.begin(); itr != row.end(); itr++){
        if(itr->key == key){ //if the parameter value exists in the current list of values
            return itr->value;
        }
    }
    return NULL;
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
            for(int c = 0; c < table[r].size(); c++){
                cout << "Key: " << table[r][c].key; //?????? bruh
                cout << "\tValue: " << table[r][c].value << endl;
            }
        }
    }
}
#endif //INC_22S_FINAL_PROJ_HASHTABLE_H
