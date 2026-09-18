#include <iostream>
#include "BST.h"

int main(){
    //create ugat
    BinarySearchTree<int> tree(20);
    const int size = 7;
    int treeArr[size] = {20,10,5,70,60,80,50};

    for (int i = 0; i < size; i++){
        //std::cout << treeArr[i] << '\n';
        tree.insert(treeArr[i]);
    }

    std::cout << "preOrder:";
    tree.preOrder();
    std::cout << '\n';
    std::cout << "inOrder:";
    tree.inOrder();
    std::cout << '\n';
    std::cout << "postOrder:";
    tree.postOrder();
    return 0;
}