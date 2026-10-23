#include <cstddef>
#include <iostream>
#include <utility>

#ifndef SORTINGALGO_H
#define SORTINGALGO_H

//========================== BUBBLE SORT ==========================
/*
Bubble Sort Algorithm is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in the wrong order. 
It is often used to introduce the concept of a sorting and is particularly suitable for sorting small datasets.

To sort a data set using bubble sort algorithm, follow the below steps:

    Start by comparing the first two elements. If they are in the wrong order, swap them.
    Continue this process for all elements moving from left to right. After the first pass, the largest element will be at the end.
    In the next pass, skip the last element since it's already sorted and repeat the above steps. 
    The second-largest element will move to the second-last position.
    Repeat the steps until the entire array is sorted.
*/
template<typename T>
void bubbleSort(T arr[], int arrSize){
    //step1: for i =0 to N-1 repeat inner loop
    for(int i = 0; i < arrSize; i++){
        //step 2 inner loop that for K = i+1 to N-I repaeat
        bool swapped = false;
        for(int adj = i+1; adj < arrSize; adj++){
            //step 3: swap if the arr[j] > arr[i]
            if (arr[i] > arr[adj]){
                //swap arr[j] array[i]
                std::swap(arr[i], arr[adj]);
                swapped = true;
            }
        }
        
        //stop loop if no swap occured
        if (!swapped){
            break;
        }
    }
}

//============================= SELECTION SORT =========================
template<typename T>
//Find the smallest
int routineSmallest(T arr[],int sortedLastIndex, const int arrSize){
    int position;
    T smallestElem = arr[sortedLastIndex];

    for (int i = sortedLastIndex + 1; i < arrSize; i++){
        if (arr[i] < smallestElem){
            smallestElem = arr[i];
            position = i;
        }
    }
    
    return position;
}
/*
Selection Sort is a comparison-based sorting algorithm. It sorts by repeatedly selecting the smallest (or largest) element from the unsorted portion 
and swapping it with the first unsorted element.

    Find the smallest element and swap it with the first element. This way we get the smallest element at its correct position.
    Then find the smallest among remaining elements (or second smallest) and swap it with the second element.
    We keep doing this until we get all elements moved to correct position.
*/
template<typename T>
void selectionSort(T arr[],int arrSize){
    int smallestElemIndex,pass;
    T temp;

    for (int i = 0; i < arrSize; i++){
        //get the smallest element
        smallestElemIndex = routineSmallest(arr, i, arrSize);
        //swap the smallest element with the current index
        temp = arr[i];
        arr[i] = arr[smallestElemIndex];
        arr[smallestElemIndex] = temp;
        pass++;
    }
}

//============================ INSERTION SORT =================================
/*
Insertion sort is a simple sorting algorithm that works by iteratively inserting each element of an unsorted list into its correct 
position in a sorted portion of the list. It is like sorting playing cards in your hands. You split the cards into two groups: the sorted cards
and the unsorted cards. Then, you pick a card from the unsorted group and put it in the right place in the sorted group.

    Start with the second element as the first element is assumed to be sorted.
    Compare the second element with the first if the second is smaller then swap them.
    Move to the third element, compare it with the first two, and put it in its correct position
    Repeat until the entire array is sorted.
    
*/
template<typename T>
void insertionSort(T arr[],int arrSize){
    for (int i = 1; i < arrSize;i++){
        T toBeCompared = arr[i];
        int keyPrev = i - 1;

        while (keyPrev > -1 && arr[keyPrev] > toBeCompared){
            //swap
            arr[keyPrev+1] = arr[keyPrev];
            keyPrev--;
        }
        arr[keyPrev+1] = toBeCompared;
    }
}

#endif