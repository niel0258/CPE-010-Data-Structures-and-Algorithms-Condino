#ifndef STACK_LIST_H
#define STACK_LIST_H

#include <iostream>

//class node that contains data and the next
template <typename T>
class Node{
    public:
    T data;     // VALUE THAT WE NEED STORE
    Node* next; // POINTER TO THE NEXT NODE
};

//global pointer for the top of the stack
template <typename T>
Node<T> *head = nullptr;

//operations for the stack

// push
template <typename T>
void push(T newData){
    //create a new node and assign the newData
    Node<T>* newNode = new Node<T>;
    newNode->data= newData;

    //new node points to current top, then becomes the new top
    newNode->next = head<T>;
    head<T> = newNode;
}

// isEmpty
template<typename T>
bool isEmpty(){
    return head <T> == nullptr;
}

// pop
template<typename T>
T pop(){
    //check if the stack is empty:
    if(isEmpty<T>()){
        std::cout<< "stack underflow. "<<std::endl;
        return T();
    }

    //save the current top node
    Node<T>* temp = head<T>;
    //store its data
    T tempVal = temp->data;

    // move the head to the next node
    head<T> = head<T>->next;
    //free the removed node
    delete temp;
    //return the removed value
    return tempVal;
}

// top
template<typename T>
T Top(){
    // error catching:
    if(isEmpty<T>()){
        std::cout<<"Stack underflow "<<std::endl;
        return T();
    }
    // display the Top node
    return head<T>->data;
    std::cout<<"Top of Stack: "<<head<T>->data <<std::endl;
}

//display All
template <typename T>
void displayALL(){
    if (isEmpty<T>()){
        std::cout << "stack undeflow\n";
        return;
    }
    std::cout<< "Displaying the stack: \n";
    Node<T>* currentElem = head<T>;
    while(currentElem != nullptr){
        std::cout << currentElem->data << "\n";
        currentElem = currentElem->next;
    }
    std::cout << "\n";
}

#endif