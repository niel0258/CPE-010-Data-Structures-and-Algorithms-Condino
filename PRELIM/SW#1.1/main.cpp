 #include <iostream>

int main(){
    std::cout << "============== Quiz Grade calculator ==============\n\n";
    float sumQuizzes = 0;
    int totalQuizzes = 0;

    std::cout << "Input number of quizzes:";
    std::cin >> totalQuizzes;

    system("clear");

    std::cout << "Input the grades of the Quizzes below:\n\n";
    for (int i = 0; i < totalQuizzes; i++){
        std::cout << "Input the grades for Quiz " << i+1 << "\n";
        int grade;
        std::cin >> grade;
        sumQuizzes += grade;
    }
    system("clear");

    std::cout << "---------------------------------------------\n";
    std::cout << "Sum of Grades is " << sumQuizzes << "\n";
    std::cout << "Average of Quizzes is " << sumQuizzes/totalQuizzes << "\n";

    return 0;
}