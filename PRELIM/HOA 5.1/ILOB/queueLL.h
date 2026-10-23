#ifndef QUEUELL_H
#define QUEUELL_H

#include <iostream>

//node class
template<typename T>
class qNode{
    public:
    T data; //contains data to be stored in the node
    qNode* next = nullptr;
};

//new node creator
template <typename T>
qNode<T>* createNewNode(T newData){
    qNode<T> *newNode = new qNode<T>;

    newNode->data = newData;
    newNode->next = nullptr;

    return newNode;
}

//isempty
template<typename T>
bool isQEmpty(qNode<T>* frontPtr,qNode<T>* backPtr){
    if (frontPtr == nullptr && backPtr == nullptr){
        return true;
    }
    return false;
}

//enqueue
//double pointer to modify the pointers
template<typename T>
void enqueue(T newData,qNode<T>** frontPtr,qNode<T>** backPtr){
    //create new node
    qNode<T>* newNode = createNewNode(newData);
    //check if queue empty
    if (isQEmpty(*frontPtr,*backPtr)){
        (*frontPtr) = newNode;
        (*backPtr) = newNode;
    }
    //if not insert at back
    else{
        (*backPtr)->next = newNode;
        (*backPtr) = newNode;
    }
}

//dequeue
template<typename T>
T dequeue(qNode<T>** frontPtr,qNode<T>** backPtr){
    //check if q empty
    if (isQEmpty(*frontPtr,*backPtr)){
        std::cout << "queue empty"<<std::endl;
        return T();
    }
    //create temp var to store node to be delted
    qNode<T>* toBeDeleted = nullptr;
    //assign the current front to the toBeDeleted
    toBeDeleted = (*frontPtr);
    //store data
    T dataReturned = toBeDeleted->data;
    //check if the q has 1 item
    if ((*frontPtr)->next == nullptr){
        //only one item in queue
        *frontPtr = nullptr;
        *backPtr = nullptr;
        delete toBeDeleted;
        return dataReturned;
    }
    //shift the front node
    (*frontPtr) = (*frontPtr)->next;
    //unlink the node to be deleted
    toBeDeleted->next = nullptr;
    //delete the node
    delete toBeDeleted;
    return dataReturned;
}

//display
template<typename T>
void displayQ(qNode<T>* front){
    if (front == nullptr){
        std::cout << "There is no list\n";
    }
    while(front!= nullptr){
        std::cout<< front->data << " \n";
        front = front->next;
    };
}

#endif