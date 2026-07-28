#include <iostream>
#include <string>
#include "doubly_ll.h"
#include "simple_menu.h"
#include "misc.h"

void appStart();
void appMain(DoubleList<std::string>** headPtr);
int actionMenu(DoubleList<std::string>** headPtr);
void insertSongs(DoubleList<std::string>** headPtr);
void playSongsOneByOne(DoubleList<std::string>** headPtr);
int songActionMenu(DoubleList<std::string>** currentNode);
void playLoopedSongs( DoubleList<std::string>* headPtr);

int main(){
    appStart();
    return 0;
}

void appStart(){
    Menu mainMenu = Menu(2,"IPlayMusic");
    mainMenu.EditMenu(0, "Playlist 1");
    mainMenu.EditMenu(1,"Exit");

    DoubleList<std::string>* playlistHead = nullptr;
    //DoubleList<std::string>* originalHead = playlistHead;

    int menuChoice = mainMenu.NavigateMenu();

    if (menuChoice == 0){
        appMain(&playlistHead);
    }

    clearScreen();

    std::cout << "App exited";

    dllDeleteList(&playlistHead);
}

void appMain(DoubleList<std::string>** headPtr){
    bool hasExited = false;

    clearScreen();

    while (!hasExited){
            //Insert first song
        if (*headPtr == nullptr){
            std::string songName = getNoneEmptyString("Please enter first song name:");

            *headPtr = createNewNode(songName);

        }
        if (actionMenu(headPtr) == 0){
            hasExited = true;
        }
    }
}

int actionMenu(DoubleList<std::string>** headPtr){
    Menu actions = Menu(5,"Choose Action");
    actions.EditMenu(0, "Insert more songs");
    actions.EditMenu(1,"Delete songs");
    actions.EditMenu(2,"Play songs");
    actions.EditMenu(3,"Loop Songs");
    actions.EditMenu(4, "Go back");

    int choice = actions.NavigateMenu();

    switch(choice){
        case 0:{
            insertSongs(headPtr);
            break;
        }
        case 1:{
            clearScreen();
            std::string toBeRemoved = getNoneEmptyString("Enter the name of the song you want to remove:");
            dllDeleteNode(toBeRemoved, headPtr,"Song Not Found\n","Song successfully deleted");
            waitS(2);
            clearScreen();
            break;
        }
        case 2:{
            playSongsOneByOne(headPtr);
            break;
        }
        case 3:{
            playLoopedSongs(*headPtr);
            break;
        }
        case 4:{
            return 0;
        }
    }
    return 1;
}

void insertSongs(DoubleList<std::string>** headPtr){
    clearScreen();
    Menu insertSongMenu = Menu(3,"Where to insert song");
    insertSongMenu.EditMenu(0, "Start");
    insertSongMenu.EditMenu(1, "Pick a place");
    insertSongMenu.EditMenu(2, "End");

    int choice = insertSongMenu.NavigateMenu();

    std::string songName = getNoneEmptyString("Enter song name:");

    switch (choice) {
        case 0:
        {
            dllInsertHead(songName,headPtr);
            break;
        }
        case 1:{
            DoubleList<std::string>* foundNode = nullptr;
            int tries = 3;
            do{
                std::string besideSongName = getNoneEmptyString("Put next to what song:");

                foundNode = dllFindValue(*headPtr, besideSongName);

                clearScreen();
                //Error correction
                if (foundNode == nullptr) std::cout << "Song not found, please retype\n";
                std::cout << "Tries left " << --tries << '\n';

            } while (foundNode == nullptr && tries > 0);
            clearScreen();
            dllGenInsert(songName, foundNode);
            break;
        }
        case 2:{
            dllInsertEnd(songName, *headPtr);
        }
    }
}

void playSongsOneByOne(DoubleList<std::string>** headPtr){
    DoubleList<std::string>* currentNode = *headPtr;
    
    if (currentNode == nullptr) return;

    while (currentNode != nullptr) {
        if (!songActionMenu(&currentNode)) break;
    }
}

int songActionMenu(DoubleList<std::string>** currentNode){
    if ((*currentNode)->next == nullptr && (*currentNode)->prev == nullptr){
        Menu songMenu = Menu(1,"Song: " + (*currentNode)->data);
        songMenu.EditMenu(0,"Go back");

        songMenu.NavigateMenu();

        return 0;
    }
    else if ((*currentNode)->next == nullptr){
        Menu songMenu = Menu(2,"Song: " + (*currentNode)->data);
        songMenu.EditMenu(0,"Play previous song");
        songMenu.EditMenu(1,"Go back");
        
        int choice = songMenu.NavigateMenu();

        if (choice == 0){
            (*currentNode) = (*currentNode)->prev;
        }
        else {
            return 0;
        }
    }
    else if ((*currentNode)->prev == nullptr){
        Menu songMenu = Menu(2,"Song: " + (*currentNode)->data);
        songMenu.EditMenu(0,"Play next song");
        songMenu.EditMenu(1,"Go back");

        int choice = songMenu.NavigateMenu();
        
        if (choice == 0){
            (*currentNode) = (*currentNode)->next;
        }
        else {
            return 0;
        }
    }
    else{
        Menu songMenu = Menu(3,"Song: " + (*currentNode)->data);
        songMenu.EditMenu(0,"Play next song");
        songMenu.EditMenu(1,"Play previous song");
        songMenu.EditMenu(2,"Go back");

        int choice = songMenu.NavigateMenu();
        
        if (choice == 0){
            (*currentNode)= (*currentNode)->next;
        }
        else if (choice == 1) {
            (*currentNode) = (*currentNode)->prev;
        }
        else {
            return 0;
        }
    }

    return 1;
}

void playLoopedSongs(DoubleList<std::string>* headPtr){
    clearScreen();
    DoubleList<std::string>* tail = headPtr;
    
    //Connect the list tail to its head to allow circular access
    while (tail->next != nullptr) {
        tail = tail->next;
    }

    headPtr->prev = tail;
    tail->next = headPtr;

    DoubleList<std::string>* currentNode = headPtr;

    bool continueLoop = true;

    while (continueLoop){
        Menu songMenu = Menu(3,"Song: " + currentNode->data);
        songMenu.EditMenu(0,"Play next song");
        songMenu.EditMenu(1,"Play previous song");
        songMenu.EditMenu(2,"Exit Loop");

        int choice = songMenu.NavigateMenu();
        
        if (choice == 0){
            currentNode= currentNode->next;
        }
        else if (choice == 1) {
            currentNode = currentNode->prev;
        }
        else {
            //Revert back to normal
            headPtr->prev = nullptr;
            tail->next = nullptr;
            continueLoop = false;
        }
    }
}