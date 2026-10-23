#include <iostream>
#include <string>
#include <unordered_map>
#include "stackList.h"

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

void balanceSign(std::string input);

//main driver
int main(){
    //balanceSign("(A+B)+(C-D)");
    //balanceSign("((A+B)+(C-D)");
    //balanceSign("((A+B)+[C-D])");
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
                if (isEmpty<char>()){
                    std::cout << input << " : " << "Error (Not Valid): Stack is empty\n";
                    return;
                }
                else if (Top<char>() == symbols.at(character)){
                    pop<char>();
                }
                else{
                    std::cout << input << " : " << "Error (Not Valid): closing "
                    "symbol does not match opening symbol\n";
                    return;
                }
            }
        }
    }

    if (!isEmpty<char>()){
        std::cout << input << " : " << "Error (Not Valid): stack has not been emptied\n";
    }
    else{
        std::cout << "Checking complete: "<< input << " is valid\n";
    }
}