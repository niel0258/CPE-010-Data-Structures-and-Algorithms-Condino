#ifndef DOUBLY_LL_H
#define DOUBLY_LL_H

#include <iostream>

template <typename T>
class DoubleList{
    public:
        T data;
        DoubleList<T>* prev = nullptr;
        DoubleList<T>* next = nullptr;
};

template <typename T>
DoubleList<T>* createNewNode(T newData){
    DoubleList<T> *newNode = new DoubleList<T>;

    newNode->data = newData;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    return newNode;
}

template <typename T>
void dllTraverse(DoubleList<T>* currentNode){
    if (currentNode == nullptr){
        std::cout << "List is empty\n";
        return;
    }

    DoubleList<T>* tail; 

    std::cout << "Forward\n";

    while (currentNode != nullptr){
        std::cout << currentNode->data<< " -> ";
        tail = currentNode;
        currentNode = currentNode->next;
    }

    std::cout << "null";
    std::cout << "\n";
    std::cout << "Backward\n";

    while (tail != nullptr){
        std::cout << tail->data<< " -> ";
        tail = tail->prev;
    }

    std::cout << "null";
    std::cout << "\n";
}

template<typename T>
void dllInsertHead(T newData, DoubleList<T>** currentHead){
    DoubleList<T>* newNode = createNewNode(newData);
    newNode->next = *currentHead;
    (*currentHead)->prev = newNode;

    *currentHead = newNode;
}

template<typename T>
void dllInsertEnd(T newData,DoubleList<T>* currentHead){
    DoubleList<T>* newNode = createNewNode(newData);

    while(currentHead->next != nullptr){
        currentHead = currentHead->next;
    }

    currentHead->next = newNode;
    newNode->prev = currentHead;
}

template <typename T>
//Inserts a node at the right side of given node
void dllGenInsert(T newData,DoubleList<T>* besideNode){
    if (besideNode == nullptr){
        std::cout << "Node cannot be inserted\n";
        return;
    }

    DoubleList<T>* newNode = createNewNode(newData);

    //Set addresses for the node
    newNode->next = besideNode->next;
    newNode->prev = besideNode;

    if (besideNode->next != nullptr){
        besideNode->next->prev = newNode;
    }

    besideNode->next = newNode;

}

template<typename T>
void dllDeleteNode(T findData,DoubleList<T>** head,std::string err_mess = "\nData Not Found\n",std::string succ_mess = ""){

    if (head == nullptr|| *head == nullptr) return;

    DoubleList<T>* currNode = *head;
    //traverse
    while (currNode != nullptr &&  currNode->data != findData){
        currNode = currNode ->next;
    }

    if (currNode == nullptr){
        std::cout << err_mess;
        return;
    }
    
    std::cout << succ_mess;

    if (currNode == *head){
        *head = currNode->next;
    }

    //Data found

    if (currNode->next != nullptr) currNode->next->prev = currNode->prev;
    if (currNode->prev != nullptr) currNode->prev->next = currNode->next;

    delete currNode;
}

template<typename T>
void dllDeleteList(DoubleList<T>** head){
    DoubleList<T>* current = *head;

    while (current != nullptr){
        DoubleList<T>* temp = current;
        current = current->next;
        delete temp;
    }

    *head = nullptr;
}

template <typename T>
DoubleList<T>* dllFindValue(DoubleList<T>* currentNode,T dataNeeded){
    if (currentNode == nullptr){
        return nullptr;
    }

    while (currentNode != nullptr && currentNode->data != dataNeeded){
        currentNode = currentNode->next;
    }

    return currentNode;
}

#endif