#include "node.h"
#include <iostream>

#ifndef SEARCHINGALGO_H
#define SEARCHINGALGO_H

//================ ARRAY ========================================

template<typename T>
void linearSearch(int size,T item,T array[]){
    //int comparisons = 0;
    int count = 0;
    for (int i = 0; i < size;i++){
        //std::cout << "Comparisons made:" << ++comparisons << '\n';
        if(array[i] == item){
            std::cout << "Data Found at index " << i << "\n";
            std::cout << "The same element found: " << ++count << '\n';
            //return;
        }
    }
    if (count > 0) {
        return;
    }
    std::cout << "Data not found\n";
}

template<typename T>
void binarySearchArr(T arr[],int arrSize,T dataFind){
    int low = 0;
    int high = arrSize - 1;
    int middle;

    while (low <= high){
        middle = (int)((low+high)/2);
        std::cout << "Middle index: " << middle << " , element: " << arr[middle] << '\n';
        if (dataFind == arr[middle]){
            std::cout << "The data was found\n";
            return;
        }
        else if (dataFind < arr[middle]){
            high = middle - 1;
            std::cout << "less than middle, searching the left half, high: " << high << '\n' ;
        }
        else {
            low = middle + 1;
            std::cout << "greater than middle, searching the right half, low: " << low << '\n' ;
        }
    }

    std::cout << "The data was not found\n";
}

template<typename T>
void binarySearchArrRec(T arr[],int low,int high,T dataFind){
    if (low > high){
        std::cout << "Data not found"<<'\n';
        return;
    }
    int middle = (int)((low+high)/2);
    if (dataFind == arr[middle]){
        std::cout << "Element found at index: " << middle << '\n';
        return;
    }
    if (dataFind < arr[middle]){
        binarySearchArrRec(arr, low, middle - 1, dataFind);
    }
    else{
        binarySearchArrRec(arr, middle+1, high, dataFind);
    }
}
//===================================================================

//=============================== LINKED LIST ================================
template<typename T>
void linearSearchLL(Node<T> *headNode, T dataToBeFound){
    //int comparisons = 0;
    int count = 0;
    while (headNode != nullptr){
        //std::cout << "Comparisons made:" << ++comparisons << '\n';
        if (headNode->data == dataToBeFound){
            std::cout << "Found Data inside the node\n";
            std::cout << "The same element found: " << ++count << '\n';
            //return;
        }
        headNode = headNode->next;
    }
    if (count > 0) {
        return;
    }
    std::cout << "Data not found in nodes given\n";
}

template<typename T>
Node<T>* getMiddle(Node<T>* start, Node<T>* end){
    Node<T>* slow = start;
    Node<T>* fast = start;

    while (fast != end && fast->next!= end){
        slow = slow->next;

        fast = fast->next->next;
    }

    return slow;
}

template <typename T>
void binarySearchLL(Node<T>* start, T dataFind) {
    Node<T>* last = nullptr;
    
    while (start != last) {
        Node<T>* middle = getMiddle(start, last);

        if (middle->data == dataFind) {
            std::cout << "Data found\n";
            return;
        }
        else if (middle->data > dataFind) {
            last = middle;
        }
        else {
            start = middle->next; 
        }
    }

    std::cout << "Data not found\n";
}

#endif