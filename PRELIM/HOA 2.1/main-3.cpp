#include <iostream>
#include <string.h>

class Student{
    private:
        std::string studentName;
        int studentAge;
    public:
        Student(std::string newName = "John Doe",int newAge=18){
            studentName = std::move(newName);
            studentAge = newAge;
            std::cout << "Constructor Called.\n";
        };
        ~Student(){
            std::cout << "Destructor Called.\n";
        };
        Student(const Student &copyStudent){
            std::cout << "Copy Constructor Called\n";
            studentName = copyStudent.studentName;
            studentAge = copyStudent.studentAge;
        }
        Student& operator=(const Student &copyStudent){
            std::cout << "Assignment operator called\n";
            if (this != &copyStudent) {
                studentName = copyStudent.studentName;
                studentAge = copyStudent.studentAge;
            };
            
            return *this;
        }

        void printDetails(){
            std::cout << this->studentName << " " << this->studentAge << std::endl;
        }
};

int main(){
    const size_t j = 5;
    Student studentList[j] = {};
    std::string namesList[j] = {"Carly", "Freddy", "Sam", "Zack", "Cody"};
    int ageList[j] = {15, 16, 18, 19, 16};

    for (size_t i = 0; i < j; i++ ){
        Student *ptr = new Student(namesList[i],ageList[i]);
        studentList[i] = *ptr;
        delete ptr;
        ptr = nullptr;
    }

    for (size_t a = 0; a < j; a++){
        studentList[a].printDetails();
    }

    return 0;
}