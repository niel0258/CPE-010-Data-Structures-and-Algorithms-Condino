#include <iostream>
#include <queue>

void display(std::queue<char> copyQ);

//main driver
int main(){

    //create obj
    std::queue<char> bbq;

    //use the enqueue operation
    bbq.push('N');
    bbq.push('I');
    bbq.push('E');
    bbq.push('L');


    //call front
    std::cout<< "current front is: " << bbq.front() << std::endl;

    //call back
    std::cout << "current back is: " << bbq.back() << std::endl;

    //display
    display(bbq);
    std::cout<< "is orig list empty: " << bbq.empty() << std::endl;

    //use dequeue operation
    bbq.pop();
    display(bbq);
    bbq.pop();
    display(bbq);
    bbq.pop();
    display(bbq);
    bbq.pop();
    display(bbq);

    //check if queue is empty
    std::cout<< "is orig list empty: " << bbq.empty() << std::endl;

    return 0;
}

void display(std::queue<char> copyQ){
    //create copy of queue
    //Argument already creates a copy unless the parameter is uses reference, saves memory not creating another copy
    //loop until empty
    while (!copyQ.empty()){
        //display the copy front
        std::cout<< "current element:" << copyQ.front() << std::endl;
        //pop the front
        copyQ.pop();
    }
    //new line
    std::cout << '\n';
}