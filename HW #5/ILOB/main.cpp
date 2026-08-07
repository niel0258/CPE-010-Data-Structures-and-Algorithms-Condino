#include <iostream>
#include "queueLL.h"

//main driver
int main(){
    qNode<char>* front = nullptr;
    qNode<char>* back = nullptr;

    std::cout << "Testing enqueue:\n";
    enqueue('N',&front,&back);
    std::cout <<"front: " <<front->data << " back: " << back->data << '\n';
    enqueue('I',&front,&back);
    std::cout <<"front: " <<front->data << " back: " << back->data << '\n';
    enqueue('E',&front,&back);
    std::cout <<"front: " <<front->data << " back: " << back->data << '\n';
    enqueue('L',&front,&back);
    std::cout <<"front: " <<front->data << " back: " << back->data << '\n';

    std::cout << "Display queue: \n";
    displayQ(front);
    std::cout << "Testing dequeue: \n";
    dequeue(&front,&back);
    std::cout <<"front: " <<front->data << " back: " << back->data << '\n';
    dequeue(&front,&back);
    std::cout <<"front: " <<front->data << " back: " << back->data << '\n';
    dequeue(&front,&back);
    std::cout <<"front: " <<front->data << " back: " << back->data << '\n';
    dequeue(&front,&back);
    //List is empty from the line above
    dequeue(&front,&back);
    std::cout << "Is q empty: " << isQEmpty(front,back);
    //std::cout <<"front: " <<front->data << " back: " << back->data << '\n';
    return 0;
}