#include <iostream>
#include <cstdlib>//random gen
#include <time.h>//seed

//#include "node.h"
#include "searchingAlgo.h"

const int max_size = 10;

void addRandomMembers(int dataset[]){
    srand(time(0));
    std::cout << "[";
    for (int i = 0; i < max_size;i++){
        dataset[i] = rand();
        std::cout << dataset[i]<<",";
    }
    std::cout << "]\n";
}

int main(){
    /*
    int dataset[max_size] = {1,2,3,4,5,6,7,8,9,10};
    //addRandomMembers(dataset);

    int itemToFind;
    std::cout << "Enter data to find:\n";
    std::cin >> itemToFind;

    //linearSearch(max_size,itemToFind,dataset);
    binarySearchArr(dataset, max_size, itemToFind);
    */

    Node<int> *num1  = newNode(10);
    Node<int> *num2  = newNode(20);
    Node<int> *num3  = newNode(30);
    Node<int> *num4  = newNode(40);
    Node<int> *num5  = newNode(50);
    Node<int> *num6  = newNode(60);
    Node<int> *num7  = newNode(70);
    Node<int> *num8  = newNode(80);
    Node<int> *num9  = newNode(90);
    Node<int> *num10 = newNode(100);

    num1->next  = num2;
    num2->next  = num3;
    num3->next  = num4;
    num4->next  = num5;
    num5->next  = num6;
    num6->next  = num7;
    num7->next  = num8;
    num8->next  = num9;
    num9->next  = num10;

    binarySearchLL(num1, 66);

    return 0;
}