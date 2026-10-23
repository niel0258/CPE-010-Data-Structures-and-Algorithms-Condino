#include <iostream>
#include "queueArr.h"

//main driver
int main(){
    QueueArray<int> q_Arr (5);
    std::cout << "Queue size is " << q_Arr.Size() << '\n';

    std::cout << "Current front: " << q_Arr.Front() << '\n';
    std::cout << "Current back: " << q_Arr.Back() << '\n';

    //put elements in queue
    for (int i = 1; i <= 6;i++){
        std::cout << "Tried to Enqued: " << i << '\n';
        q_Arr.Enqueue(i);
        std::cout << "Current front: " << q_Arr.Front() << '\n';
        std::cout << "Current back: " << q_Arr.Back() << '\n';
    }
    std::cout << "Queue size is " << q_Arr.Size() << '\n';

    std::cout << "Current front: " << q_Arr.Front() << '\n';
    std::cout << "Current back: " << q_Arr.Back() << '\n';

    std::cout << "Dequeing: " << q_Arr.Dequeue() << '\n';

    std::cout << "Current front: " << q_Arr.Front() << '\n';
    std::cout << "Current back: " << q_Arr.Back() << '\n';

    //Clear array
    q_Arr.Clear();

    std::cout << "Is array empty: " << (q_Arr.Empty()? "yes": "no") << '\n' ;

    return 0;
}