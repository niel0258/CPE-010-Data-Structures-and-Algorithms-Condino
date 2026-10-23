#ifndef SIMPLE_MENU_H
#define SIMPLE_MENU_H

#include <iostream>
#include <string>
#include <ncurses.h>

//Better implementation of menu from the calendar program hahahahaha

class Menu{
    protected:
        std::string* menuItems = nullptr;
        std::string menuTitle = "";
        int menuSize = 0;
        int currentRow = 0;

        void PrintMenu(){
            clear();

            printw("\n====================================\n");
            printw("%19s",menuTitle.c_str());
            printw("\n====================================\n");
            for (int i = 0; i < menuSize; i++) {
                if (i == currentRow){
                    printw(" > %s\n",menuItems[i].c_str());
                }
                else{
                    printw("   %s\n",menuItems[i].c_str());
                }    
            }
            printw("\nUse UP/DOWN arrows to navigate. Press ENTER to select.\n\n");
            refresh();
        }

    public:
        Menu(int givenMenuSize,std::string menuTitleGiven){
            menuSize = givenMenuSize;
            menuItems = new std::string[givenMenuSize];
            menuTitle = menuTitleGiven;
        };

        ~Menu(){
            delete[] menuItems;
        }
        
        void EditMenu(int index,std::string menuDescription){
            menuItems[index] = menuDescription;
        }

        /*
        Returns an int, best use for switch case and call the function 
        you want
        */
        int NavigateMenu(bool initializeScreen = true){
            if (initializeScreen){
                initscr(); //Initialize ncurses screem
                cbreak(); // Disable line buffering, pass key directly
                noecho(); //Don't print typed key
                keypad(stdscr,true);//Enables easier detection of keys
            } 

            int returnedRow;

            int ch = -2;

            while (ch != -1){
                PrintMenu();
                ch = getch();
                switch(ch){
                    case KEY_UP:{
                        currentRow--;
                        //Preventing going out of scope
                        if (currentRow < 0){
                            currentRow = menuSize - 1;
                        } 
                        break;
                    }
                    case KEY_DOWN:{
                        currentRow++;
                        //Preventing going out of scope
                        if (currentRow == menuSize){
                            currentRow = 0;
                        }
                        break;
                    }
                    case KEY_ENTER:
                    case 10://For some reason ENTER is 10
                        returnedRow = currentRow;
                        currentRow = 0;
                        ch = -1;//breaks loop
                        break;
                    
                }
            }
            
            if (initializeScreen) endwin(); //End ncurses screen
            return returnedRow;
        }
};

#endif