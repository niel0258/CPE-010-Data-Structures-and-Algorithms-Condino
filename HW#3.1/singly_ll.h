#ifndef SINGLY_LL_H
#define SINGLY_LL_H

#include <iostream>

template<typename T>
class SingleList{
    public:
    T data; //contains data to be stored in the node
    SingleList* next = nullptr;
};

template<typename T>
void singleListTravesal(SingleList<T>* head){
    if (head == nullptr){
        std::cout << "There is no list\n";
    }
    while(head!= nullptr){
        std::cout<< head->data;
        head = head->next;
    };
}

template<typename T>
void sllinsertHead(T newData,SingleList<T>** currentHead){
    SingleList<T>* newNode = new SingleList<T>;

    newNode->data = newData;
    newNode->next = *currentHead;
    *currentHead = newNode;

}

template <typename T>
void sllGeneralInsert(T newData,SingleList<T>* prevNode){
    //If check if head
    if (prevNode == nullptr){
        std::cout << "Previous value cannot be null\n";
        return;
    }
    //Allocate new node
    SingleList<T>* newNode = new SingleList<T>;
    //Store Data
    newNode->data = newData;
    //Point new node 
    newNode->next = prevNode->next;
    prevNode->next = newNode;

}

template<typename T>
void sllInsertEnd(T newData, SingleList<T>** head){
    SingleList<T>* newNode = new SingleList<T>;
    SingleList<T>* currentNode = *head;
    newNode->data = newData;
    newNode->next = nullptr;

    while(currentNode->next != nullptr){
        currentNode = currentNode->next;
    }

    currentNode->next = newNode;
}

template <typename T>
void sllDeleteNode(T findData,SingleList<T>** head){

    if (head == nullptr) return;

    SingleList<T>* currNode = *head;
    SingleList<T>* prevNode = nullptr;


    while (currNode != nullptr &&  currNode->data != findData){
        prevNode = currNode;
        currNode = currNode ->next;
    }

    if (currNode == nullptr){
        std::cout << "\nData Not Found\n";
        return;
    }

    if (prevNode == nullptr){
        *head = currNode->next;
    }
    else{
        prevNode->next = currNode->next;
    }

    delete currNode;
}


template <typename T>
void sllDeleteList(SingleList<T>** head){
    SingleList<T>* current = *head;

    while (current != nullptr){
        SingleList<T>* temp = current;
        current = current->next;
        delete temp;
    }

    *head = nullptr;
}
#endif