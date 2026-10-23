#ifndef PRINTERJOB_H
#define PRINTERJOB_H

#include <iostream>
#include "../ILOB/queueLL.h"

class Job{
    private:
        std::string name;
        int pages;
    public:
        int ID;

        Job(std::string nameOfJob= " ", int jobPages=0){
            name = nameOfJob;
            pages = jobPages;
        }

        std::string getName(){
            return name;
        }

        int getPages(){
            return pages;
        }
};

class Printer{
    private:
        qNode<Job>* front = nullptr;
        qNode<Job>* back = nullptr;

        int trackingID = 0;
        int jobLeft = 0;
        
    public:
    Printer(){
        std::cout << "================================== Printer Initialized =================================\n";
    }
    //remove remaining data in queue if it is not dequeued
    ~Printer(){
        std::cout << "=================================== Printer Closed ========================================\n";
        while (!isQEmpty(front,back)){
            dequeue(&front,&back);
        }
    }

    //Add Job
    void queueJob(Job sentJob){
        sentJob.ID = ++trackingID;
        enqueue(sentJob, &front, &back);
        jobLeft++;
        std::cout << " ====================== Queued Job ================================\n";
    }

    //Do Job
    void performJob(){
        //check if there are jobs left
        if (jobLeft == 0) {
            std::cout << "No more jobs left\n";
            return;
        }

        Job jobToBePerformed = dequeue(&front, &back);
        jobLeft--;
        std::cout << "============== PRINTING ============================\n";
        std::cout << "Printed Job:\n";
        std::cout << "ID: " << jobToBePerformed.ID << '\n';
        std::cout << "Job sent by: " << jobToBePerformed.getName() << '\n';
        std::cout << "Job Pages: \n" << jobToBePerformed.getPages() << '\n';
        std::cout << "-----------------------------------------------------\n";
    }

    void performAllJob(){
        while (!isQEmpty(front, back)){
            performJob();
        }
    }
    void showJobQueue(){
        std::cout << "Jobs left: " << jobLeft << '\n';
    }
};

#endif