#include <iostream>
#include "sortingAlgo2.h"

const int maxSize = 15;

void displayArr(int arr[]);
//Procedure

int main(){

    //create an array with unsorted list
    int unsortedArr[maxSize] ={4, 34, 29, 48, 53, 87, 12, 30, 44, 25, 93, 67, 43, 19,74};
    //populate the array with random val
    
    std::cout << "Unsorted Array:\n";
    //display the randomly generated arr
    displayArr(unsortedArr);
    std::cout << "\nSorted using quick sort\n";
    quickSort(unsortedArr,0,maxSize-1);
    //std::cout << "\nSorted using partition shell and merge\n";

    std::cout << "\nSorted Array :\n";
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