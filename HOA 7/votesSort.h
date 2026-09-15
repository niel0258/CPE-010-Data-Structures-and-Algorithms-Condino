#ifndef VOTESSORT_H
#define VOTESSORT_H

template <typename T>
void insertionSort(T arr[], int maxSize){
    int k = 1, j, temp;

    while (k < maxSize){
        temp = arr[k];
        j = k - 1;

        while(temp <= arr[j] && j > -1){
            arr[ j + 1 ] = arr[j];
            j--;
        }
        arr[ j + 1 ] = temp;
        k++;
    }
}



#endif