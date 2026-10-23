/*
Algorithm
1. Initialize itemTotal and userPayment to 0 and itemNames array with size 3
2. Display welcome message
3. Initialize map for items
4. Print items
5. Loop until user bought 3 items
6. Compute total
7. Accept payment
8. Compute Change
9. Print leaving message

PseudoCode
BEGIN
    INITIALIZE itemTotal and userPayment to 0, itemNames array
    PRINT welcome message
    INITIALIZE map of items with names and prices
    INVOKE printItems()
    FOR i = 0 to 2
        INPUT item name
        GET item price
        ADD item price to item total
        PRINT added the price to total payment
    ENDFOR
    DISPLAY itemTotal
    INPUT userPayment
    IF userPayment > or = to itemTotal
        PRINT change
    ELSE
        PRINT "User has not enough money"
END
*/

#include <iostream>
#include <map>
#include <string>

void printItems(const std::map<std::string,int> &items){
    std::cout << "{ITEMS FOR SELL\n\tName:\tPrice\n";
    for (const auto& item: items){
        std::cout << "\t["<< item.first << ":\t" << item.second << "]\n";
    }
    std::cout << "}\n\n";
}

int getItemAndPrice(const std::map<std::string,int> &items,std::string *itemNames,int currentIndex){
    std::string itemName;
    std::cout << "Enter name of item :";
    std::getline(std::cin,itemName);

    if (items.find(itemName) != items.end()){
        std::cout << "Purchased " << itemName << "\n";
        itemNames[currentIndex] = itemName;
        return items.at(itemName);
    }
    else{
        std::cout << "Item not found, please try again\n";
        return getItemAndPrice(items,itemNames,currentIndex);
    }
} 

int main(){
    int itemTotal = 0;
    int userPayment = 0;
    std::string itemNames[3] = {};

    std::cout << "Kendo Gun Shop\n";

    std::map<std::string,int> items = {
        {"Glock 19",500},
        {"Smith & Wesson Shield Plus",450},
        {"Mossberg 500",500},
        {"Ruger 10/22",350},
        {"AR-15",700},
    };

    printItems(items);
    
    for (int i = 0; i < 3; i++){
        int itemPrice = getItemAndPrice(items,itemNames,i);
        itemTotal += itemPrice;
        std::cout << "Added $" << itemPrice << " to total\n";
    }

    std::cout << "---------------------------\nItems bought:\n";

    for (int i = 0;i < 3; i++){
        std::cout << itemNames[i] << "\t\t $" << items.at(itemNames[i]) << "\n";
    }

    std::cout << "---------------------------------------\n";
    std::cout << "Total price is $" << itemTotal << "\n" ;
    std::cout << "Input payment:$";
    std::cin >> userPayment;

    if (userPayment >= itemTotal){
        std::cout << "User paid $" << userPayment << ". User's change is $" << userPayment - itemTotal;
    }
    else {
        std::cout << "User does not have enough money, Items were returned";
    }

    return 0;
}