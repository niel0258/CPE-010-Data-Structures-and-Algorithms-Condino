#include <iostream>

void swapVar(int &var1,int &var2);

int main(){
    int a = 1;
    int b = 4;
    std::cout << "a is " << a << " and b is " << b << '\n';
    swapVar(a,b);
    std::cout << "a is "<< a << " and b is " << b << '\n';
    return 0;
}

void swapVar(int &var1,int &var2){
    int temp = 0;
    temp = var1;
    var1= var2;
    var2 = temp;
    std::cout<< "Swapped!\n";
}
