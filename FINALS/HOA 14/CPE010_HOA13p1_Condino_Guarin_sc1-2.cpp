#include<iostream>
#include<chrono>
#include "sortingAlgo2.h"

const int maxSize = 100;

void sortedArray(int arr[], int maxSize){
    for(int i = 0; i < maxSize; i++){
        arr[i]= i;
    }
}

void convertToBestCase(int arr[], int left, int right){
       if(left >= right) return;
       int mid = left + (right - left) / 2;
       convertToBestCase(arr, left, mid - 1);
       convertToBestCase(arr, mid + 1, right);
       std::swap(arr[mid], arr[right]);
}
//worst case for mege
void generateWorstCase(int arr[], int source[], int l, int r, int srcL) {
    if (l == r) {
        arr[l] = source[srcL];
        return;
    }


    int m = l + (r - l) / 2;


    // Distribute elements: evens go to the left half, odds go to the right half
    generateWorstCase(arr, source, l, m, srcL * 2);
    generateWorstCase(arr, source, m + 1, r, srcL * 2 + 1);
}

// Measure Merge Sort
long long testMergeSort(int arr[]){
    auto begin = std::chrono::steady_clock::now();
    mergeSort(arr, 0, maxSize - 1);
    auto end = std::chrono::steady_clock::now();
    return std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
}


// Measure Quick Sort
long long testQuickSort(int arr[]){
    auto begin = std::chrono::steady_clock::now(); 
    quickSort(arr, 0, maxSize - 1);
    auto end = std::chrono::steady_clock::now();
    return std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
}


int main(){


    int mergeBest[maxSize];
    int mergeWorst[maxSize];
    int quickBest[maxSize];
    int quickWorst[maxSize];

    // Generate inputs
    sortedArray(mergeBest, maxSize);
    sortedArray(mergeWorst, maxSize);
    sortedArray(quickBest, maxSize);
    sortedArray(quickWorst, maxSize);


    // Prepare Quick Sort test cases
    convertToBestCase(quickBest, 0, maxSize - 1);
    // worst case for merge
    generateWorstCase(mergeWorst, quickBest, 0,maxSize - 1, 0);


    // Quick Sort worst case: sorted input
    // Last element is used as the pivot

    std::cout << "Algorithm 1: Merge Sort\n";
    std::cout << "Best Case: "<< testMergeSort(mergeBest)<< " nanoseconds\n";
    std::cout << "Worst Case: "<< testMergeSort(mergeWorst)<< " nanoseconds\n\n";

    std::cout << "Algorithm 2: Quick Sort\n";
    std::cout << "Best Case: "<< testQuickSort(quickBest)<< " nanoseconds\n";

    std::cout << "Worst Case: "<< testQuickSort(quickWorst)<< " nanoseconds\n";


    return 0;
}