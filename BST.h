#include <iostream>
#ifndef BST_H
#define BST_H

template <typename T>
class BinarySearchTree{
    private:
    //gumawa ng susi
    T key;
    //panturo sa kaliwa at kanan
    BinarySearchTree<T>* left;
    BinarySearchTree<T>* right;
    public:  
    //panggawa
    BinarySearchTree(T val);
    //tagasira
    ~BinarySearchTree();
    //paglagay sa kaliwa at kanan
    void insert(T val);
    //paggala
    void preOrder();
    void inOrder();
    void postOrder();
    //paghalungkat
};

template<typename T>
BinarySearchTree<T>::BinarySearchTree(T val){
    key = val;
    left = nullptr;
    right = nullptr;
}

template<typename T>
BinarySearchTree<T>::~BinarySearchTree(){
   delete left;
   delete right;
}

template<typename T>
void BinarySearchTree<T>::insert(T val){
    if (val < key){
        if (left == nullptr){
            left = new BinarySearchTree<T>(val);
        }
        else{
            left->insert(val);
        }
    }
    else if (val > key){
        if (right == nullptr){
            right = new BinarySearchTree<T>(val);
        }
        else{
            right->insert(val);
        }
    }
    else{

    }
}

template<typename T>
void BinarySearchTree<T>::preOrder(){
    std::cout << key << ' ';
    if (left != nullptr){
        left->preOrder();
    }
    if (right != nullptr){
        right->preOrder();
    }
}

template<typename T>
void BinarySearchTree<T>::inOrder(){
    if (left != nullptr){
        left->inOrder();
    }
    std::cout << key << ' ';
    if (right != nullptr){
        right->inOrder();
    }
}

template<typename T>
void BinarySearchTree<T>::postOrder(){
    if (left != nullptr){
        left->postOrder();
    }
    if (right != nullptr){
        right->postOrder();
    }
    std::cout << key << ' ';
}
#endif