//
// Created by leila on 4/11/2022.
//
// Resources: https://www.geeksforgeeks.org/level-order-tree-traversal/ (helped with breadth first traversal)
//
#ifndef INC_22S_FINAL_PROJ_AVLTREE_H
#define INC_22S_FINAL_PROJ_AVLTREE_H
#include <algorithm>
#include <ostream>
using namespace std;

template <typename T>
class AVLTree{
private:
    class AVLNode{
    public:
        T data;
        AVLNode* left;
        AVLNode* right;
        int height;
        AVLNode(const T& element, AVLNode* lt, AVLNode* rt, int h = 0):data(element), left(lt), right(rt), height(h){}
    };
    AVLNode* root;
    int nodeCount = 0;
    T* insert(const T& x, AVLNode*& t);
    //T& find(const T& x, AVLNode*& t);
    void balance(AVLNode*& t);
    void deleteTree(AVLNode*& t);
    bool contains(const T& x, AVLNode*& t);
public:
    AVLTree():root(nullptr){}
    AVLTree(const AVLTree& rhs) : root(nullptr){*this = rhs;}
    ~AVLTree();
    T* insert(const T& x);
    //T& find(const T& x);
    bool contains(const T& x);
    void deleteTree();
    ostream& printBreadthFirstTraversal(ostream& output);
    ostream& printCurrLevel(ostream& output,AVLNode*& root1, int level);
    int height(AVLNode* t);
    void rotateWithLeftChild(AVLNode*& k2);
    void rotateWithRightChild(AVLNode*& k1);
    void doubleWithLeftChild(AVLNode*& k3);
    void doubleWithRightChild(AVLNode*& k3);
    int getNodeCount();
    friend ostream& operator<<(ostream& output, AVLTree<T>& temp){
        output << temp.printBreadthFirstTraversal(output);
        return output;
    }
};

template <typename T>
AVLTree<T>::~AVLTree(){
    deleteTree();
}

template <typename T>
T* AVLTree<T>::insert(const T& x){
    return insert(x, root);
}

/*template <typename T>
T& AVLTree<T>::find(const T& x){
    return find(x, root);
}*/

template <typename T>
void AVLTree<T>::deleteTree(){
    deleteTree(this->root);
    root = nullptr;
    nodeCount = 0;
}

template <typename T>
void AVLTree<T>::deleteTree(AVLNode*& t){
    if(t != nullptr){
        deleteTree(t->left);
        deleteTree(t->right);
        delete t;
    }
}

template <typename T>
ostream& AVLTree<T>::printBreadthFirstTraversal(ostream& output){
    //loop through each level of the tree, print out each node at that level
    for(int i = 1; i < height(this->root); i++){
        printCurrLevel(output, this->root, i);
    }
    return output;
}

template <typename T>
ostream& AVLTree<T>::printCurrLevel(ostream& output, AVLNode*& root1, int level){
    if(root1 != nullptr){
        if(level == 1){
            output << root1->data << '\\';
        }
        else{
            printCurrLevel(output, root1->left, level-1);
            printCurrLevel(output, root1->right, level-1);
        }
    }
    return output;
}

template <typename T>
int AVLTree<T>::height(AVLNode* t){
    return t == nullptr ? -1:t->height;
}

template <typename T>
void AVLTree<T>::rotateWithLeftChild(AVLNode*& k2){
    AVLNode* k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(height(k1->left), k2->height) + 1;
    k2 = k1;
}

template <typename T>
void AVLTree<T>::rotateWithRightChild(AVLNode*& k1){
    AVLNode* k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    k1->height = max(height(k1->left), height(k1->right)) + 1;
    k2->height = max(height(k2->right), k1->height) + 1;
    k1 = k2;
    //this should be right?
}

template <typename T>
void AVLTree<T>::doubleWithLeftChild(AVLNode*& k3){
    rotateWithRightChild(k3->left);
    rotateWithLeftChild(k3);
}

template <typename T>
void AVLTree<T>::doubleWithRightChild(AVLNode*& k3){
    //not sure if this is right
    rotateWithLeftChild(k3->right);
    rotateWithRightChild(k3);
}

template <typename T>
T* AVLTree<T>::insert(const T& x, AVLNode*& t){
    if(t == nullptr){
        t = new AVLNode(x, nullptr, nullptr);
        nodeCount++;
        return &(t->data);
    }
    else if(x < t->data){
        balance(t);
        return insert(x, t->left);
    }
    else if(t->data < x){
        balance(t);
        return insert(x, t->right);
    }
    else if(x == t->data){
        //duplicates
        t->data = t->data + x;
        return &(t->data);
    }
}

/*template <typename T>
T& AVLTree<T>::find(const T& x, AVLNode*& t){
    if(t == nullptr){
        t = new AVLNode(x, nullptr, nullptr);
        balance(t);
        return t->data;
    }
    else if(x < t->data){
        return insert(x, t->left);
    }
    else if(t->data < x){
        return insert(x, t->right);
    }
    else{
        //duplicates
        return t->data;
    }
}*/

template <typename T>
bool AVLTree<T>::contains(const T& x){
   return contains(x, root);
}

template <typename T>
bool AVLTree<T>::contains(const T& x, AVLNode*& t){
    if(t == nullptr) {
        return false;
    }
    else if(x < t->data){
        return contains(x, t->left);
    }
    else if(t->data < x){
        return contains(x, t->right);
    }
    else {
        return true;
    }

}

template <typename T>
void AVLTree<T>::balance(AVLNode*& t){
    if(t == nullptr){
        return;
    }
    if(height(t->left) - height(t->right) > 1){
        if(height(t->left->left) >= height(t->left->right)){ //case 1
            rotateWithLeftChild(t);
        }
        else{                                          //case 2
            doubleWithLeftChild(t);
        }
    }
    else if(height(t->right) - height(t->left) > 1){
        if(height(t->right->right) >= height(t->right->left)){ // case 4
            rotateWithRightChild(t);
        }
        else{
            doubleWithRightChild(t);
        }
    }
    t->height = max(height(t->left), height(t->right)) + 1;
}

template <typename T>
int AVLTree<T>::getNodeCount(){
    return nodeCount;
}

#endif //INC_22S_FINAL_PROJ_AVLTREE_H