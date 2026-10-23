//#include "node.h"
#include "node.h"
#include "searchingAlgo.h"

const int max_size = 10;

int main(){
    int myList[max_size] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18}; 

    binarySearchArr(myList, max_size, 8);
    //binarySearchArrRec(myList, 0,max_size-1 ,20);
    return 0;
}