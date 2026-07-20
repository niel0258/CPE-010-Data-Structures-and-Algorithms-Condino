#include <iostream>
#include <map>
#include <string>
#include <array>
#include <span>

//Base Class
class Consumable{
    protected:
        std::string name;
        int addedQuantity;
        float price;
    public:
        virtual ~Consumable() = default;
        virtual float getItemPrice() = 0;
        virtual void printDetails() = 0;
        virtual std::string getName() = 0;
        virtual int getQuantity() const = 0;
};

//Implement templating for individual quantity map
template <typename Foods>
class Food:public Consumable {
        public:
            static std::map<std::string, int> quantity;
            float getItemPrice() override;
            void  printDetails() override;
            std::string getName() override;
            int getQuantity() const override;
};

//FRUIT AND VEGETABLE CLASSES

class Fruit : public Food<Fruit> {
    public:
        Fruit(std::string foodName="Unknown",float foodPrice=0,int foodQuantity=1);
        ~Fruit() override;
        Fruit(const Fruit &copyFruit);
        Fruit& operator=(const Fruit &copyFruit);
};

class Vegetable: public Food<Vegetable>{
    public:
        Vegetable(std::string Foodname="Unknown",float Food_price=0,int Food_quantity=1);
        ~Vegetable() override;
        Vegetable(const Vegetable &copyVegetable);
        Vegetable& operator=(const Vegetable &copyVegetable);
};

//Function prototype

int getTotalSum(std::span<Consumable*> GroceryList);

//=================================== MAIN ==================================

int main() {
    const int arr_size = 4;
    //Problem number 1
    Fruit *apple = new Fruit("Apple",10,7);
    Fruit *banana = new Fruit("Banana",10,8);
    Vegetable *broccolli = new Vegetable("Broccolli",60,12);
    Vegetable *lettuce = new Vegetable("Lettucce",50,10);  
    
    std::cout << "\nOriginal List\n";
    
    //Problem number 2
    std::array<Consumable*,arr_size> GroceryList = {apple,banana,broccolli,lettuce};

    for (const auto& item:GroceryList){
        item->printDetails();
    }

    //Problem number 3
    int totalSumObj = getTotalSum(GroceryList);

    std::cout << "Number of objects in the array: " << totalSumObj << "\n";

    //Problem number 4
    delete lettuce;
    lettuce = nullptr;
    GroceryList[3] = nullptr;

    std::cout << "\nNew List\n";

    for (const auto& item:GroceryList){
        if (item == nullptr) continue;
        item->printDetails();
    }

    int totalSumObj2 = getTotalSum(GroceryList);//Check the total objects now

    std::cout << "Number of objects in the array: " << totalSumObj2 << "\n";

    return 0;
}

//================================= DEFINITION ====================================

//Declare outside class
template <typename Foods>
std::map<std::string, int> Food<Foods>::quantity;

template <typename Foods>
float Food<Foods>::getItemPrice(){
    return price*quantity[name];
}
template <typename Foods>
void Food<Foods>::printDetails(){
    std::cout << "Name: "<< name << " Price: " << price << " Quantity: " << quantity[name] <<"\n";
}
template <typename Foods>
std::string Food<Foods>::getName(){
    return name;
}
template <typename Foods>
int Food<Foods>::getQuantity() const{
    return quantity[name];
}

//============================================= Fruit METHODS =============================================

Fruit::Fruit(std::string foodName,float foodPrice,int foodQuantity){
    name = foodName;
    price = foodPrice;
    addedQuantity = foodQuantity;
    quantity[foodName] += foodQuantity;
}

Fruit::~Fruit(){
    quantity[name]-= addedQuantity;
}

Fruit::Fruit(const Fruit &copyFruit){
    name = copyFruit.name;
    price = copyFruit.price;
    addedQuantity = copyFruit.addedQuantity;
    quantity[name] += copyFruit.addedQuantity;
}

//=============================================== VEGETABLE METHODS =======================================

Vegetable::Vegetable(std::string foodName,float foodPrice,int foodQuantity){
    name = foodName;
    price = foodPrice;
    addedQuantity = foodQuantity;
    quantity[name]+= foodQuantity;
}

Vegetable::~Vegetable(){
    quantity[name] -= addedQuantity;
}

Vegetable::Vegetable(const Vegetable &copyVegetable){
    name = copyVegetable.name;
    price = copyVegetable.price;
    addedQuantity = copyVegetable.addedQuantity;
    quantity[name] = copyVegetable.addedQuantity;
}

//Problem 3 Solution
int getTotalSum(std::span<Consumable*> GroceryList){
    int totalSum = 0;

    for (const Consumable* item: GroceryList){
        if (item == nullptr) continue;
        totalSum += item->getQuantity();
    }

    return totalSum;
}