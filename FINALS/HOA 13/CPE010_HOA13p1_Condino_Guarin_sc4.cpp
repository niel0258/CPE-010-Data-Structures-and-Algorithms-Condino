#include <chrono>
#include <iostream>
#include <thread>
#include <cstdlib>
#include <ctime>
#include "sortingAlgo2.h"

constexpr int maxSize =  1000000;

template<typename T>
void quickSortMT(T arr[], int low, int high);
void testTime(int origArr[],void (*sorting)(int*,int,int),std::string name);
void displayArr(int arr[]);

int main() {
    //seed
    srand(time(0));
    int myArr[maxSize];
    //populate array
    for (int i =0;i < maxSize; i++){
        myArr[i] = rand() % 1000;
    }

    //run test
    testTime(myArr,quickSort,"Single Threaded Quick Sort");//single thread
    testTime(myArr, quickSortMT, "Multi Threaded Quick Sort");//multithreaded

    return 0;
}


void testTime(int origArr[],void (*sorting)(int*,int,int),std::string name){
    //create deepcopy of orig array
    //prevent stack overflow
    int* copyArr = new int[maxSize];
    for (int i =0;i < maxSize; i++){
        copyArr[i] = origArr[i];
    }

    auto begin = std::chrono::steady_clock::now();
    sorting(copyArr,0,maxSize-1);
    auto end = std::chrono::steady_clock::now();

    std::cout << name << " Algorithm's Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end-begin).count() << " milliseconds\n"; 
    delete [] copyArr;
}

template<typename T>
// the QuickSort function implementation
void quickSortMT(T arr[], int low, int high) {
    if (low < high) {
        // pi is the partition return index of pivot
        int pi = partition(arr, low, high);

        //creating a thread has big runtime cost so we fallback to normal if the size is not too big
        if ((high - low) > 10000){// different threads for each recursive call
            std::thread t1(quickSortMT<T>,arr, low, pi - 1);
            quickSortMT(arr, pi + 1, high);//For the main thread
            t1.join();
        }
        else{
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }
}
