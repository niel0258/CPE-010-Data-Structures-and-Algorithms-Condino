#include <iostream>

//global declarations
#define maxCap 10
int stackArr[maxCap];
int topArr = -1, newData;

//prototype function
void push();
void pop();
void top();
bool isEmpty();
bool isFull();
void displayStack();

int main(){
    bool continueLoop = true;

    while (continueLoop){
        int choice = 0;
        std::cout << "=========================================\n";
        std::cout << "Stack Operations\n";
        std::cout << "1.Push\n2.Pop\n3.Top\n4.isEmpty\n5.isFull\n6.Display stack\n7.Exit";
        std::cout << "\n=========================================\n";

        std::cout << "Enter choice:";
        std::cin >> choice;

        switch (choice){
            case 1:
            {
                push();
                break;
            }
            case 2:{
                pop();
                break;
            }
            case 3:{top();
            break;}
            case 4: std::cout << "Is Empty: " << isEmpty() << std::endl;
            break;
            case 5: std::cout << "Is Full : " << isFull() << std::endl;
            break;
            case 6: displayStack();
            case 7: continueLoop = false;
            break;
            default:std::cout << "invalid choice";break;
        }
    }
    //main driver
    return 0;
}

//definiton

bool isEmpty(){
    if (topArr == -1){
        return true;
    }
    return false;
}

bool isFull(){
    if (topArr == maxCap - 1) return true;
    return false;
}

void push(){
    //err check
    if (isFull()){
        std::cout << "stack overflow\n";
        return;
    }
    //pushing
    std::cout << "Enter a value: \n";
    std::cin >> newData;
    //insert in the stack
    stackArr[++topArr] = newData;
}

void pop(){
    //err check
    if (isEmpty()){
        std::cout << "stack underflow\n";
        return;
    }

    //display the popped value
    top();

    //decrement the top value from the class
    topArr--;
}

void top(){
    //err
    if (isEmpty()){
        std::cout << "no stack elements\n";
        return;
    }
    std::cout << "Top value is: " << stackArr[topArr] << std::endl;
}

void displayStack(){
    for (int i = topArr; i >= 0; i--){
        std::cout << stackArr[i] << ",";
    }
    std::cout << '\n';
}