#include <iostream>
#include <chrono>
#include <thread>
#include "searchingAlgo.h"

constexpr int maxSize = 10000;

void populateArr(int arr[]);
void testTime(int arr[],void (*searching)(int*,int,int),std::string name,int caseTesting);

int main(){
    int myArr[maxSize];
    populateArr(myArr);

    const int wCase= maxSize + 1;

    std::thread wCaseLinearTest(testTime, myArr, linearSearch<int>, "Worst Case Linear Search",wCase);
    wCaseLinearTest.join();
    std::thread wCaseBinaryTest(testTime, myArr, binarySearchArr<int>, "Worst Case Binary Search",wCase);
    wCaseBinaryTest.join();
    return 0;
}

void testTime(int arr[],void (*searching)(int*,int,int),std::string name,int caseTesting){

    auto begin = std::chrono::steady_clock::now();
    searching(arr,maxSize,caseTesting);
    auto end = std::chrono::steady_clock::now();

    std::cout << name << " Algorithm's Time: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count() << " nanoseconds\n\n\n"; 
}


void populateArr(int arr[]){
    for (int i = 0; i < maxSize;i++){
        arr[i] = i;
    }
}

