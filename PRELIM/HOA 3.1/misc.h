#ifndef MISC_H
#define MISC_H

#include <cstdlib>
#include <thread> // for wait function
#include <chrono> // for wait function	
#include <iostream>

inline void waitS(int time) {
	std::this_thread::sleep_for(std::chrono::seconds(time));

}

inline std::string getNoneEmptyString(std::string message){
    std::string returnString = "";
    while (returnString.empty()){
        std::cout << message;
        getline(std::cin,returnString);
        if (returnString.empty()) {
            std::cout << "Input cannot be empty\n";
            waitS(2);
            system("clear");
        }
    }
    return returnString;
}

inline void clearScreen(){
	if (system("cls")){
		system("clear");
	}
}

#endif