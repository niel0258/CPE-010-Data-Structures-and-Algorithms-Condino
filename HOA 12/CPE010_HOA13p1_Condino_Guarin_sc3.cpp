#include <cstring>
#include <iostream>

const int rowSize = 4;
const int columnSize = 4;

const int cost = 25;

int memo[rowSize][columnSize][cost +1] = {0};

int matrix[rowSize][columnSize] = {
    {4,7,1,6},
    {6,7,3,9},
    {3,8,1,2},
    {7,1,7,3},
};

int findPaths(int yCoord, int xCoord, int remaining){
    //Out of bounds check
    if (yCoord == rowSize || xCoord == columnSize){
        return 0; 
    }

    int currentCost = matrix[yCoord][xCoord];

    //Insufficient currency check
    if (currentCost > remaining){
        return 0;
    }

    remaining -= currentCost;

    //Reached the bottom-right destination
    if (yCoord == rowSize - 1 && xCoord == columnSize - 1){
        if (remaining== 0){
            return 1;
        }
        else return 0;
    }

    //Memoization lookup
    if (memo[yCoord][xCoord][remaining] != -1){
        return memo[yCoord][xCoord][remaining]; 
    }

    int downTraverse = findPaths(yCoord + 1, xCoord, remaining);
    int rightTraverse = findPaths(yCoord, xCoord + 1, remaining);

    //Save result to memo table and return
    memo[yCoord][xCoord][remaining] = downTraverse + rightTraverse;

    return memo[yCoord][xCoord][remaining];
}

int main(){
    memset(memo, -1, sizeof(memo));//Initialize memo to -1
    std::cout << "With a "<< cost <<" cost, There are "<< findPaths(0, 0, cost) << " paths \n";
    return 0;
}
