#include <iostream>

#ifndef SORTINGALGO2_H
#define SORTINGALGO2_H

template<typename T>
void shellSort(T array[],int size,int start = 0){
    for (int gap = size/2;gap > 0; gap /=2){
        //selection like sorting
        for (int i = start + gap;i < size;i++){
            int temp = array[i];
            int key = i;
            while (key >= gap && array[key - gap] > temp) {
                array[key] = array[key - gap];
                key -= gap;
            }
            array[key] = temp;   
        }
    }
}

template<typename T>
void merge(T array[],int left,int mid,int right){
    int sizeL = mid-left + 1;
    int sizeR = right - mid;

    T arrL[sizeL];
    T arrR[sizeR];

    for (int i = 0; i < sizeL; i++){
        arrL[i] = array[left + i];
    }
        
    for (int j = 0; j < sizeR; j++){
        arrR[j] = array[mid + 1 + j];    
    }

    int i = 0, j = 0;
    int k = left;

    // Merge the temp arrays back 
    // into arr[left..right]
    while (i < sizeL && j < sizeR) {
        if (arrL[i] <= arrR[j]) {
            array[k] = arrL[i];
            i++;
        }
        else {
            array[k] = arrR[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], 
    // if there are any
    while (i < sizeL) {
        array[k] = arrL[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], 
    // if there are any
    while (j < sizeR) {
        array[k] = arrR[j];
        j++;
        k++;
    }

}

template<typename T>
void mergeSort(T array[],int left,int right){
    if (left >= right)return;
    int mid = left + (right - left) / 2;
    mergeSort(array, left, mid);
    mergeSort(array, mid + 1, right);
    merge(array, left, mid, right);
}

template<typename T>
int partition(T arr[], int low, int high) {
  
    // choose the pivot
    T pivot = arr[high];
  
    // undex of smaller element and indicates 
    // the right position of pivot found so far
    int i = low - 1;

    // Traverse arr[low..high] and move all smaller
    // elements on left side. Elements from low to 
    // i are smaller after every iteration
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    
    // move pivot after smaller elements and
    // return its position
    std::swap(arr[i + 1], arr[high]);  
    return i + 1;
}

template<typename T>
// the QuickSort function implementation
void quickSort(T arr[], int low, int high) {
    if (low < high) {
      
        // pi is the partition return index of pivot
        int pi = partition(arr, low, high);

        // recursion calls for smaller elements
        // and greater or equals elements
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

template <typename T>
void partiMerge(T arr[],int low,int high){
    int pi = partition(arr, low, high);

    // recursion calls for smaller elements
    // and greater or equals elements
    mergeSort(arr, low, pi - 1);
    mergeSort(arr, pi + 1, high);
}

template<typename T>
void partiShell(T arr[],int size){
    int pi = partition(arr, 0, size-1);

    shellSort(arr, pi,0);
    shellSort(arr,size,pi);
}

#endif