//
// Created by leila on 4/25/2022.
//

#ifndef INC_22S_FINAL_PROJ_HASHTABLE_H
#define INC_22S_FINAL_PROJ_HASHTABLE_H
#include <vector>
#include <set>
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
    vector<set<V>> table;
public:
    HashTable();
    void insert(K key, V value);
    V deleteNode(K key);
    V at(K key);
    int hash(K key);
    int sizeOf();
    bool isEmpty();
    void display();
};

template <typename S, typename T>
HashTable<S, T>::HashTable(){
    size = 0;
    capacity = 100;
}

template <typename K, typename V>
void HashTable<K, V>::insert(K key, V value){
    HashTableNode<K,V>* temp = new HashTableNode<K,V>(key, value);
    int hashKey = hash(key);
    //finding empty spot in table to insert
    while(table[hashKey].key != key && table[hashKey] != NULL){ //&& table[hashKey] != nullptr
        hashKey++;
        hashKey %= capacity;
    }
    //checking for collisions
    if(table[hashKey].key == key){
        table[hashKey].value.push_back(value);
    }
    //found a spot, add it into table
    else{
        table[hashKey] = temp;
        size++;
    }
}

template <typename K, typename V>
V HashTable<K, V>::deleteNode(K key){
    int hashKey = hash(key);
    while(table[hashKey] != NULL){
        if(table[hashKey].key == key){
            HashTableNode<K,V>* temp = table[hashKey];
            delete table[hashKey]; //no clue if this works
            return temp->key;
        }
    }
}

template <typename K, typename V>
V HashTable<K, V>::at(K key){
    int hashKey = hash(key);
    int count = 0;
    //loop through the hashtable
    while(table[hashKey] != NULL){
        count++;
        hashKey++;
        hashKey %= capacity;
        if(count > capacity){
            return NULL;
        }
        if(table[hashKey].key == key){
            return table[hashKey].value;
        }
        hashKey++;
    }
}

template <typename K, typename V>
int HashTable<K, V>::hash(K key){
    return hash(key);
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
        if(table[r] != NULL){
            for(int c = 0; c < table[r].size(); c++){
                cout << "Key: " << table[r][c].key; //?????? bruh
                cout << "\tValue: " << table[r][c].value << endl;
            }
        }
    }
}
#endif //INC_22S_FINAL_PROJ_HASHTABLE_H
