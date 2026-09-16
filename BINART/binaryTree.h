#ifndef BINARYTREE_H
#define BINARYTREE_H

template<typename T>
class BinaryTree{
    private:
        T key;
        //tagaturo
        BinaryTree<T>* leftChild;
        BinaryTree<T>* rightChild;
    public:
        //tagagawa
        BinaryTree(T rootObj);
        //tagasira
        ~BinaryTree();

        //pagdagdag ng anak na node
        void insertLeftChild(T newNode);
        void insertRightChild(T newNode);
        BinaryTree<T>* getLeftChild();
        BinaryTree<T>* getRightChild();
        T getKey();
        void changeKey(T val);
        bool isLeaf();
};

template<typename T>
BinaryTree<T>::BinaryTree(T rootObj){
    key = rootObj;
    leftChild = nullptr;
    rightChild = nullptr;
}


template<typename T>
void BinaryTree<T>::insertLeftChild(T newNode){
    if (leftChild == nullptr){
        leftChild = new BinaryTree<T>(newNode);
    }
    BinaryTree<T> *newChild = new BinaryTree<T>(newNode);
    //galawin ang anak sa ilalim ng bagong node
    newChild->leftChild = leftChild;
    leftChild = newChild;
}

template<typename T>
void BinaryTree<T>::insertRightChild(T newNode){
    if (rightChild == nullptr){
        rightChild = new BinaryTree<T>(newNode);
    }
    BinaryTree<T> *newChild = new BinaryTree<T>(newNode);
    //galawin ang anak sa ilalim ng bagong node
    newChild->rightChild = rightChild;
    rightChild = newChild;
}

template<typename T>
BinaryTree<T>* BinaryTree<T>::getLeftChild(){
    return leftChild;
}

template<typename T>
BinaryTree<T>* BinaryTree<T>::getRightChild(){
    return rightChild;
}


template<typename T>
T BinaryTree<T>::getKey(){
    return key;
}

template <typename T>
void BinaryTree<T>::changeKey(T val){
    key = val;
}

template<typename T>
bool BinaryTree<T>::isLeaf(){
    return leftChild == nullptr && rightChild == nullptr;
}

#endif