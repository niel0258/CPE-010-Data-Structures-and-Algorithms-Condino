#include <iostream>
#include <cmath>

class Triangle{
    private:
        double totalAngle,angleA,angleB,angleC,sideA,sideB,sideC;
    public:
        Triangle(double A, double B, double C,double side1,double side2,double side3);
        void setAngles(double A, double B, double C);
        void setSides(double side1,double side2,double side3);
        const bool validateTriangle();
        const std::string checkTypeByAngle();
        const double computePerimeter();
        const double computeArea();
};

int main(){ 
    Triangle set1(40, 30, 110,20,20,20);

    std::cout << "area is " << set1.computeArea() << "\n";
    std::cout << "perimeter is " << set1.computePerimeter() << "\n";
    std::cout << "is a " << set1.checkTypeByAngle() << " triangle\n";

    if(set1.validateTriangle()){
        std::cout << "The shape is a valid triangle.\n";
    } 
    else {
        std::cout << "The shape is NOT a valid triangle.\n";
    }

    return 0;
}

Triangle::Triangle(double A, double B, double C,double side1,double side2,double side3) {
    angleA = A;
    angleB = B;
    angleC = C;
    sideA = side1;
    sideB = side2;
    sideC = side3;

    totalAngle = A+B+C;
}

void Triangle::setAngles(double A, double B, double C) {
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A+B+C;
}

const bool Triangle::validateTriangle() {
    return (totalAngle <= 180);
}

const double Triangle::computePerimeter(){
    return sideA + sideB + sideC;
}

const double Triangle::computeArea(){
    double semiPerimeter = Triangle::computePerimeter()/2.0;
    return sqrt(semiPerimeter*(semiPerimeter-sideA)*(semiPerimeter-sideB)*(semiPerimeter-sideC));//Heron's Formula
}

const std::string Triangle::checkTypeByAngle(){
    if (angleA > 90 || angleB > 90 || angleC > 90 ){
        return "Obtuse-Angled";
    }
    else if (angleA == 90 || angleB == 90 || angleC == 90){
        return "Others";
    }
    else{
        return "Acute-Angled";
    }
}