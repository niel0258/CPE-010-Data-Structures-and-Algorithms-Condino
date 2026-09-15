#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sortingAlgo.h"

const int maxSize = 100;

void displayArr(int arr[]);
//Procedure

int main(){

    //create an array with unsorted list
    int unsortedArr[maxSize];
    // use time (0) as seed for random
    srand(time(0));
    //populate the array with random val
    for(int i = 0; i < maxSize; i++){
        unsortedArr[i] = rand()%100;
    }
    
    std::cout << "Unsorted Array:\n";
    //display the randomly generated arr
    displayArr(unsortedArr);

    //sort the array using bubbleSort
    //std::cout << "\nSorting using bubble sort\n";
    //bubbleSort(unsortedArr, maxSize);
    //sort using selectionSort
    //std::cout << "\nSorting using selection sort\n";
    //selectionSort(unsortedArr, maxSize);
    //sort using insertion sort
    std::cout << "\nSorting using insertion sort\n";
    insertionSort(unsortedArr, maxSize);

    std::cout << "\nSorted Array:\n";
    displayArr(unsortedArr);

    return 0;
}

void displayArr(int arr[]){
    for(int i = 0; i < maxSize; i++){
        std::cout << arr[i] << " ";
        if ((i%10) == 9){
            std::cout << '\n';
        }
    }
}