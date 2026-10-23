#include <iostream>
#include "singly_ll.h"
#include "doubly_ll.h"

void runSLCode();
void runDLCode();

int main(){

    return 0;
}

void runSLCode(){        //Creation of node in the stack
    SingleList<char>* head = nullptr;
    SingleList<char>* sec = nullptr;
    SingleList<char>* thrd = nullptr;
    SingleList<char>* frth = nullptr;
    SingleList<char>* ffth = nullptr;
    SingleList<char>* last = nullptr;

    //allocates memory in the heap
    head = new SingleList<char>;
    sec = new SingleList<char>;
    thrd = new SingleList<char>;
    frth = new SingleList<char>;
    ffth = new SingleList<char>;
    last = new SingleList<char>;


    //Initializing of the data in the list
    head->data = 'C';
    sec->data = 'P';
    thrd->data = 'E';
    frth->data = '1';
    ffth->data = '0';
    last->data = '1';

    //Link the list
    head->next = sec;
    sec->next = thrd;
    thrd->next = frth;
    frth->next = ffth;
    ffth->next = last;

    std::cout << "Testing travesal\n";

    singleListTravesal(head);
    std::cout << std::endl;

    std::cout << "Testing of sllinsertHead\n";
    sllinsertHead('G', &head);
    singleListTravesal(head);
    std::cout << std::endl;

    std::cout << "Testing of sllGeneralInsert\n";
    sllGeneralInsert('E', head->next->next);
    singleListTravesal(head);
    std::cout << std::endl;

    std::cout << "Testing deleting node with C\n";
    sllDeleteNode('C', &head);
    singleListTravesal(head);
    std::cout << std::endl;

    std::cout << "Testing deleting node with P\n";
    sllDeleteNode('P', &head);
    singleListTravesal(head);
    std::cout << std::endl;

    std::cout << "Showing the elements in the list\n";
    singleListTravesal(head);
}

void runDLCode(){
    DoubleList<char>* head = createNewNode('C');
    DoubleList<char>* sec = createNewNode('P');
    DoubleList<char>* thrd = createNewNode('E');

    head->next = sec;
    sec->prev = head;

    sec->next = thrd;
    thrd->prev = sec;
    //Traversal
    std::cout << "Testing traversal\n";
    dllTraverse(head);

    //Insert new head
    std::cout << "Testing insertion\n";
    dllInsertHead('X',&head);
    dllTraverse(head);
    std::cout << "New head is: " << head->data;

    //Insert at end
    std::cout <<"Testing insertion at end\n";
    dllInsertEnd('0',head);
    dllTraverse(head);

    //Insert at a given location
    std::cout<<"Testing general insertion\n";
    dllGenInsert('7',head->next);
    dllTraverse(head);

    //Delete node
    std::cout<<"Testing deleting node\n";
    dllDeleteNode('7',&head);
    dllTraverse(head);

    //Delete List
    std::cout <<"Deleting list\n";
    dllDeleteList(&head);
    dllTraverse(head);
}
