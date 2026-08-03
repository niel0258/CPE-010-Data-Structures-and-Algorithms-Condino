#include <iostream>
#include <string>
#include <unordered_map>

//global declarations
#define maxCap 50
char stackArr[maxCap];
int topArr = -1;

std::unordered_map<char, char> symbols ={
//Closing symbols
{']','['},
{')','('},
{'}','{'},
//Opening symbols
{'{','\0'},
{'[','\0'},
{'(','\0'},
};

//prototype function
void push(char givenData);
void pop();
char top();
bool isEmpty();
bool isFull();
void displayStack();
void balanceSign(std::string input);

//main driver
int main(){
    //balanceSign("(A+B)+(C-D)");
    //balanceSign("((A+B)+(C-D)");
    //balanceSign("(A+B)+[C-D])");
    balanceSign("((A+B]+[C-D]}");
    return 0;
}

void balanceSign(std::string input){
    for (auto character: input){
        if (symbols.contains(character)){
            //check if opening symbol
            if (symbols.at(character) == '\0'){
                push(character);
            }
            else{
                if (isEmpty()){
                    std::cout << input << " : " << "Error (Not Valid): Stack is empty\n";
                    return;
                }
                else if (top() == symbols.at(character)){
                    pop();
                }
                else{
                    std::cout << input << " : " << "Error (Not Valid): closing "
                    "symbol does not match opening symbol\n";
                    return;
                }
            }
        }
    }

    if (!isEmpty()){
        std::cout << input << " : " << "Error (Not Valid): stack has not been emptied\n";
    }
    else{
        std::cout << "Checking complete: "<< input << " is valid\n";
    }
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

void push(char givenData){
    //err check
    if (isFull()){
        std::cout << "stack overflow\n";
        return;
    }
    //insert in the stack
    stackArr[++topArr] = givenData;
}

void pop(){
    //err check
    if (isEmpty()){
        std::cout << "stack underflow\n";
        return;
    }

    //decrement the top value from the class
    topArr--;
}

char top(){
    //err
    if (isEmpty()){
        std::cout << "no stack elements\n";
        return '\0';
    }
    return stackArr[topArr];
}

void displayStack(){
    for (int i = topArr; i >= 0; i--){
        std::cout << stackArr[i] << ",";
    }
    std::cout << '\n';
}