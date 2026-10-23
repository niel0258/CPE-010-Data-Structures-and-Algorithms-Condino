#include <iostream>
#include "binaryTree.h"

int main(){

    //paggawa ng ugat na punong-ugnay
    BinaryTree<char>* root = new BinaryTree<char>('A');

    //paggawa ng bata ng punong-ugnay "A"
    root->insertLeftChild('B');
    root->insertRightChild('C');

    //pagdagdag ng anak sa anak
    root->getLeftChild()->insertLeftChild('D');
    root->getLeftChild()->insertRightChild('F');

    root->getRightChild()->insertLeftChild('E');

    //pagimprinta ng ugat na node
    std::cout << "Root value: " << root->getKey() << '\n';
    std::cout << "Left child of root: " << root->getLeftChild()->getKey() << '\n';
    std::cout << "Right child of root: " << root->getRightChild()->getKey() << '\n';

    std::cout << "Left child of root: " << root->getLeftChild()->getLeftChild()->getKey() << '\n';
    std::cout << "Right child of root: " << root->getLeftChild()->getRightChild()->getKey() << '\n';

    //papalitan ang anak na F
    root->getLeftChild()->getRightChild()->changeKey('K');
    std::cout << "Right child of root: " << root->getLeftChild()->getRightChild()->getKey() << '\n';
    return 0;
}