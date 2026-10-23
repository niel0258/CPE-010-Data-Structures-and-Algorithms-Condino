#include <iostream>
#include <chrono>

int rpower(int x,int n){
    if (n == 0) return 1;
    else return x*rpower(x, n-1);
}

int brpower(int x,int n){
    if (n==0) return 1;
    if (n%2){
        int y = brpower(x, (n-1)/2);
        return x*y*y;
    }
    else{
        int y = brpower(x, n/2);
        return y*y;
    }
}

void runTest(std::string funcName,int x,int n,int (*func)(int,int)){

    auto begin = std::chrono::steady_clock::now();
    func(x,n);
    auto end = std::chrono::steady_clock::now();

    std::cout << "Time taken to execute " << funcName << " = "
              << std::chrono::duration_cast<
                     std::chrono::nanoseconds
                 >(end - begin).count()
              << " nanoseconds\n";
}

int main(){
    const int sizes[3] = {100,1000,100000};
    for (int i = 0;i < 3;i++){
        runTest("rpower",sizes[i],sizes[i],rpower);
    }

    for (int i = 0;i < 3;i++){
        runTest("brpower",sizes[i],sizes[i],brpower);
    }
    return 0;
}