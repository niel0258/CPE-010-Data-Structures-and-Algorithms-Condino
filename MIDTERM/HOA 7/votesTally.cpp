#include <iostream>
#include "sortingAlgo.h"
#include <cstdlib>
#include <time.h>

const int max_size = 100;

void displayAll(int arr[]);

int main(){

    int votes[max_size];
    srand(time(0));

    for (int i = 0; i < max_size; i++){
        votes[i] = rand()%5 + 1;
    }

    insertionSort(votes, max_size);

    displayAll(votes);

    return 0;

}

void displayAll(int arr[]){
    for (int i = 0; i < max_size; i++){
    std::cout << arr[i] << " ";
    }
}

