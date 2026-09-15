#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sortingAlgo.h"

const int maxSize = 100;
const int candidates = 5;

void displayArr(int arr[]);
int getMajorityVote(int voteArray[],const int& arrSize);

int main(){
    //create an array with unsorted list
    int unsortedArr[maxSize];
    // use time (0) as seed for random
    srand(time(0));
    //populate the array with random val
    for(int i = 0; i < maxSize; i++){
        unsortedArr[i] = (rand()%5) + 1; //generate a number from 1 to 5
    }
    
    std::cout << "Unsorted Array:\n";
    //display the randomly generated arr
    displayArr(unsortedArr);

    //sort using insertion sort
    insertionSort(unsortedArr, maxSize);

    //candidates 
    std::string candidateNames[candidates] = {"Bo Dalton Capistrano","Cornelius Raymon Agustín","Deja Jayla Bañaga","Lalla Brielle Yabut","Franklin Relano Castro"};
    //get winner of voting
    int winnerIndex = getMajorityVote(unsortedArr, maxSize);
    //display again
    std::cout << "\nSorted Array:\n";
    displayArr(unsortedArr);
    std::cout << "\nThe winner is " << candidateNames[winnerIndex] << '\n';
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


int getMajorityVote(int voteArray[],const int& arrSize){
    int voteCount[5] = {0};
    insertionSort(voteArray, arrSize);
    //count occurances
    for (int i = 0; i < arrSize; i++){
        voteCount[voteArray[i] - 1]++;
    }

    //find max
    int max = voteCount[0];
    int winner;

    std::cout << '\n';
    for (int i = 0; i < 5; i++){
        if (voteCount[i] > max){
            max = voteCount[i];
            winner = i;
        }
        std::cout << i+1 <<"s counted: " << voteCount[i] << '\n';
    }
    return winner;
}