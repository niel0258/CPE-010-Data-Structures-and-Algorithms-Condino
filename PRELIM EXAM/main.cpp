#include <iostream>
#include "stackArr.h"
#include "queueLL.h"

    /*
================ PROTOTYPE ALGORITHM ===============
Input is a string

Count the number of characters

if there is a midpoint stop collecting there

else immidietly find closing

loop until midpoint

push into the stack

loop for the last time

if there the opening and closing does not match return false

else return true
*/
bool isSymmetricStack(std::string input){
    std::size_t inputSize = input.size();
    int remainingIndex = 0;
    int midpoint = inputSize/2;

    if (inputSize <= 1){
        std::cout << input <<" is symmetric\n";
        return true;
    }

    Stack<char> symmetricStack;

    for (int i = 0;i < midpoint;i++){
        symmetricStack.push(input[i]);
        remainingIndex++;
    }

    if (inputSize % 2) {
        remainingIndex++; //skip middle for odd size
    }

    for (int i = remainingIndex;i < inputSize ; i++){
        char item = symmetricStack.top();
        symmetricStack.pop();
        if (item != input[i]){
            std::cout << input << " Not symmetric\n";
            return false;
        }
    }

    std::cout << input <<" is symmetric\n";
    return true;
}

/*
================ PROTOTYPE ALGORITHM ===============
Input is a string

Count the number of characters

loop until midpoint, start from the back

enqueue it

loop for the last time, start where you last left off

skip one if odd number size

if there the opening and closing does not match
return false

else return true
*/

bool isSymmetricQueue(std::string input){
    std::size_t inputSize = input.size();
    int midpoint = inputSize/2;

    if (inputSize <= 1){
        std::cout << input <<" is symmetric\n";
        return true;
    }

    //shift midpoint if even
    if ((inputSize % 2) == 0){
        midpoint--;
    }
    
    qNode<char>* front = nullptr;
    qNode<char>* back = nullptr;

    //inputsize - 1 to skip null terminators
    for (int i = inputSize-1;i > midpoint;--i){
        enqueue(input[i],&front,&back);
    }

    for (int i = 0;i < midpoint;i++){
        char item = dequeue(&front,&back);
        if (item != input[i]){
            std::cout << input << " Not symmetric\n";
            //prevent memory leak
            while (!isQEmpty(front,back)){
                dequeue(&front,&back);
            }
            return false;
        }
    } 

    std::cout << input <<" is symmetric\n";
    return true;
}

int main(){
    const int cases = 6;
    std::string testCases[cases] = {"12321","12345","1221","7","123321","1234325"};
    std::cout << "=============== ARRAY STACK ==============\n";
    for (int i = 0;i < cases;i++){
        isSymmetricStack(testCases[i]);
    }
    std::cout << "===================================================\n";
    std::cout << "=============== QUEUE LINKED LIST ==============\n";
    for (int i = 0;i < cases;i++){
        isSymmetricQueue(testCases[i]);
    }
    std::cout << "===================================================\n";
    return 0;
}
