#include <iostream>
#include <cmath>

float calcDistance(float x1,float x2, float y1, float y2);

int main(){
    std::cout << "Enter points\n";
    float x1,x2,y1,y2;
    std::cout << "Enter the first point in the x axis:";
    std::cin >> x1;
    std::cout << "Enter the second point in the x axis:";
    std::cin >> x2;
    std::cout << "Enter the first point in the y axis:";
    std::cin >> y1;
    std::cout << "Enter the second point in the y axis:";
    std::cin >> y2;

    std::cout << "Distance is " << calcDistance(x1,x2,y1,y2) << " units";
}

float calcDistance(float x1,float x2, float y1, float y2){
    return (sqrt(pow(x1-x2,2)+pow(y1-y2,2)));
}
