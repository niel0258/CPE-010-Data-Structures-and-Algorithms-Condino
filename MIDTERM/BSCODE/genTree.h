#ifndef GENTREE_H
#define GENTREE_H
#include <iostream>
#include <string>
#include <vector>

template <typename T>
class GeneralTree{
    private:
        T key;
        //For all the siblings
        std::vector<GeneralTree<T>*> siblings;
        //First child
        GeneralTree<T>* child;
    public:
        //Constructor & Deconstructor
        GeneralTree(T val);
        ~GeneralTree();
        //Tree Modification
        void addChild(T val);
        GeneralTree<T>* getFirstChild() const;
        std::vector<GeneralTree<T>*> getSiblings() const;
        //Tree Checking
        T getKey() const;
        void printKey() const;
        bool isLeaf() const;
        void printTree(int depth = 0) const;

        //Find data
        void findData(int choice,T key) const;

        // Default no-arg calls printKey()
        void preOrder() const {
            preOrder([](const GeneralTree<T>* node) { node->printKey(); });
        }
        void inOrder() const {
            inOrder([](const GeneralTree<T>* node) { node->printKey(); });
        }
        void postOrder() const {
            postOrder([](const GeneralTree<T>* node) { node->printKey(); });
        }

        // Custom function callback overloads
        template<typename F>
        void preOrder(F funcCall) const;
        template<typename F>
        void inOrder(F funcCall) const;
        template<typename F>
        void postOrder(F funcCall) const;
};

template<typename T>
GeneralTree<T>::GeneralTree(T val){
    key = val;
    child = nullptr;
}

template<typename T>
GeneralTree<T>::~GeneralTree(){
    for(auto* ptr:siblings){
        delete ptr;
    }
    delete child;
}

template<typename T>
void GeneralTree<T>::addChild(T val){
    //Check if has child
    if (child != nullptr){
        //add to sibling
        child->siblings.push_back(new GeneralTree<T>(val));
    }
    else{
        //add as child
        child = new GeneralTree<T>(val);
    }
}

template<typename T>
GeneralTree<T>* GeneralTree<T>::getFirstChild() const{
    return child;
}

template<typename T>
std::vector<GeneralTree<T>*> GeneralTree<T>::getSiblings() const{
    return siblings;
}

template<typename T>
bool GeneralTree<T>::isLeaf() const{
    return child == nullptr;
}

template<typename T>
T GeneralTree<T>::getKey() const{
    return key;
}

template<typename T>
void GeneralTree<T>:: printKey() const{
    std::cout << key << ' ';
}

template <typename T>
void GeneralTree<T>::printTree(int depth) const {
    //Add spaces
    for (int i = 0;i< depth *2;i++){
        std::cout << ' ';
    }

    std::cout << "- " << key << "\n";

    // Print children of this node
    if (!isLeaf()) {
        child->printTree(depth + 1);
    }

    // Print siblings at the current level
    for (auto* sibling : siblings) {
        sibling->printTree(depth);
    }
}

template<typename T>
template<typename F>
void GeneralTree<T>::preOrder(F funcCall) const{
    funcCall(this);
    if (!isLeaf()){
        //visit child
        child->preOrder(funcCall);
        //then child siblings
        for (const auto* sibling:child->siblings){
            sibling->preOrder(funcCall);
        }
    }
}

template<typename T>
template<typename F>
void GeneralTree<T>::inOrder(F funcCall) const{
    if (!isLeaf()){
        child->inOrder(funcCall);
    }
    funcCall(this);
    if (!isLeaf()){
        for (const auto* sibling:child->siblings){
            sibling->inOrder(funcCall);
        }
    }
}

template<typename T>
template<typename F>
void GeneralTree<T>::postOrder(F funcCall) const{
    if (!isLeaf()){
        child->postOrder(funcCall);
        for (const auto* sibling:child->siblings){
            sibling->postOrder(funcCall);
        }
    }
    funcCall(this);
}

template<typename T>
void GeneralTree<T>::findData(int choice,T key) const{
    bool found = false;

    //lambda function for recursive searching
    auto search = [&key,&found](const::GeneralTree<T>* node){
        if (!found && key == node->getKey()){
            std::cout << key << " was found!\n";
            found = true;
        }
    };
    
    switch (choice){
        case 1:
            std::cout << "Using Pre-Order Traversal:\n";
            preOrder(search);
            break;
        case 2:
            std::cout << "Using Post-Order Traversal:\n";
            postOrder(search);
            break;
        case 3:
            std::cout << "Using In-Order Traversal:\n";
            inOrder(search);
            break;
        default:
            std::cout << "Invalid choice\n";
            return;
    }
}

#endif