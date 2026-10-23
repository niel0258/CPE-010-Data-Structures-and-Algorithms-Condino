#include <iostream>
#include <algorithm>

int getMinSteps(int n,int memo[]){
        if ( n == 1 ){
            std::cout << "Base case reached\n";
            return 0;
        } // base case
        if( memo[n] != -1 ) {
            std::cout << "Already solved it, ";
            std::cout << "Solution for " << n << " is " << memo[n] << '\n';
            return memo[n];
        } // we have solved it already :)
        int r = 1 + getMinSteps(n - 1,memo); // '-1' step . 'r' will contain the optimal answer finally
        if( n%2 == 0 ) r = std::min( r , 1 + getMinSteps( n / 2,memo  )) ; // '/2' step
        if( n%3 == 0 ) r = std::min( r , 1 + getMinSteps( n / 3,memo )) ; // '/3' step
        memo[n] = r ; // save the result. If you forget this step, then its same as plain recursion.
        return r;
}

int main(){
    const int n = 10;
    int memo[n+1];
    //populate
    for (int i=0;i<=n;i++){
        memo[i] = -1;
    }
    std::cout << getMinSteps(n,memo) << '\n';
    //added shit
    std::cout << "Memo values {";
    for (int i=0;i<=n;i++){
        std::cout << memo[i]<<",";
    }

    std::cout << "}\n";

    return 0;
}