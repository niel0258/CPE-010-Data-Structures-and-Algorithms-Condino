#include <iostream>
#include <thread>

int total = 0;

void add(int value){
    total += value;
}

int main(){
    std::cout<<"Total: " << total <<std::endl;

    std::thread T1(add, 10);
    std::thread T2(add, 20);
    std::thread T3(add, 30);

    std::cout<<"T1 join: " << total <<std::endl;
    T1.join();
    
    std::cout<<"T2 join: " << total <<std::endl;
    T2.join();
    
    std::cout<<"T3 join: " << total <<std::endl;
    T3.join();
    
    std::cout<<"Total at the end: " << total <<std::endl;

    return 0;
}