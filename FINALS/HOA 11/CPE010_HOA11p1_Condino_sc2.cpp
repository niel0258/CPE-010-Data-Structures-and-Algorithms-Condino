#include <iostream>
#include <chrono>

void populArr(int arr[],int size){
    for(int i = 0; i < size; i++){
        arr[i] = i;
    }
}

bool isUnique(int arr[],int size){
    for (int i = 0; i < size;i++){
        for (int j = i+1; j < size;j++){
            if (arr[i] == arr[j]){
                return false;
            } 
        }   
    }
    return true;
}

void runTest(int size){
    int* array = new int[size];
    populArr(array, size);

    auto begin = std::chrono::steady_clock::now();
    bool unique = isUnique(array, size);
    auto end = std::chrono::steady_clock::now();

    std::cout << "Time taken to search array size " << size << " = "
              << std::chrono::duration_cast<
                     std::chrono::microseconds
                 >(end - begin).count()
              << " microseconds\n";
    std::string mess = unique ? "Array has unique elements" : "Array does not have unique elements";
    std::cout << mess << '\n';
    delete[] array;
}

int main(){
    const int sizes[3] = {100,1000,100000};
    for (int i = 0;i < 3;i++){
        runTest(sizes[i]);
    }
    return 0;
}