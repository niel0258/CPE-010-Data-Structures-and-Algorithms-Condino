#include <iostream>
#include "Printer&Job.h"

//main driver
int main(){
    Printer myPrinter;

    //simulate a scenario where multiple people are adding jobs to the printer, and the printer is processing them one by one
    for (int i = 1; i <= 15; i++){
        std::cout << "Person " << i << " sent a job\n";
        std::string jobName = "Job " + std::to_string(i);
        Job newJob(jobName,i);
        myPrinter.queueJob(newJob);
    }

    myPrinter.showJobQueue();

    myPrinter.performJob();

    myPrinter.showJobQueue();

    myPrinter.performAllJob();
    
    myPrinter.showJobQueue();

    myPrinter.performJob();

    myPrinter.showJobQueue();

    return 0;
}
