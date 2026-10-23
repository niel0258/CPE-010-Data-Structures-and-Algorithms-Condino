#include <iostream>

double changeKtoF(double inputTemp);

int main(){
    double input;
    std::cout << "Kelvin to Fahrenheit converter\n----------------------------------------\n";
    std::cout << "Input temperature in Kelvin: ";
    std::cin >> input;
    double temp = changeKtoF(input);
    std::cout << input << " K in fahrenheit is " << temp << " F";
    return 0;
}

double changeKtoF(double inputTemp){
    return ((inputTemp - 273) * 9/5) + 32;
}