#include <iostream>

int sumOfTwoNum(int num1, int num2);
bool isGreaterThan(float num1,float num2);
bool boolCompare(bool bool1,bool bool2);

int main(){
    std::cout << "1+1 ="<< sumOfTwoNum(1,1) << "\n";
    std::string isBigger = isGreaterThan(3,4) ? " True": "False";
    std::cout << "3 is greater than 4:"<< isBigger<< "\n";
    std::cout << boolCompare(true,false);
    return 0;
}

int sumOfTwoNum(int num1,int num2){
    return num1 + num2;
}

bool isGreaterThan(float num1,float num2){
    return num1 > num2;
}

bool boolCompare(bool bool1,bool bool2){

    std::cout << "using and: "<< (bool1 && bool2) << std::endl;
    std::cout << "using or: " << (bool1 || bool2) << std::endl;
    std::cout << "using not on bool1: " << !bool1 << std::endl;
    std::cout << "using not on bool2: " << !bool2 << std::endl;
    return true;
}