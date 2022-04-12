//
// Created by leila on 4/11/2022.
//

#ifndef INC_22S_FINAL_PROJ_AVLTREE_H
#define INC_22S_FINAL_PROJ_AVLTREE_H
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
    void insert(T& x, AVLNode*& t);
    void balance(AVLNode*& t);
public:
    T element;
    AVLTree():root(nullptr){}
    AVLTree(const AVLTree& rhs) : root(nullptr){*this = rhs;}
    ~AVLTree(){};//implement later
    void insert(T& x);
    int height(AVLNode* t);
    void rotateWithLeftChild(AVLNode*& k2);
    void rotateWithRightChild(AVLNode*& k1);
    void doubleWithLeftChild(AVLNode*& k3);
    void doubleWithRightChild(AVLNode*& k3);
};

template <typename T>
void AVLTree<T>::insert(T& x){
    insert(x,root);
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
void AVLTree<T>::insert(T& x, AVLNode*& t){
    if(t == nullptr){
        t = new AVLNode(x, nullptr, nullptr);
    }
    else if(x < t->data){
        insert(x, t->left);
    }
    else if(t->data < x){
        insert(x, t->right);
    }
    else{
        //duplicates
    }
    balance(t);
}

template <typename T>
void AVLTree<T>::balance(AVLNode*& t){
    if(t == nullptr){
        return;
    }
    if(height(t->left) - height(t->right) > 1){
        if(height(t->left) >= height(t->left->right)){ //case 1
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

#endif //INC_22S_FINAL_PROJ_AVLTREE_H