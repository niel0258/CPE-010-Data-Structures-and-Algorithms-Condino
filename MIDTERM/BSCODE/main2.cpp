#include "genTree.h"

int main(){
    GeneralTree<char>* root = new GeneralTree('A');
    root->addChild('B');//getfirst child returns this node
    root->addChild('C');//First elem in the sibling vector for B
    root->addChild('D');//Second
    root->addChild('E');//3rd
    root->addChild('F');//4th
    root->addChild('G');//Fifth
    root->getFirstChild()->getSiblings()[1]->addChild('H');//Adds to D
    root->getFirstChild()->getSiblings()[2]->addChild('I');//Adds to E
    root->getFirstChild()->getSiblings()[2]->addChild('J');//Adds to E
    root->getFirstChild()->getSiblings()[3]->addChild('K');//Adds to F
    root->getFirstChild()->getSiblings()[3]->addChild('L');//Adds to F
    root->getFirstChild()->getSiblings()[3]->addChild('M');//Adds to F
    root->getFirstChild()->getSiblings()[4]->addChild('N');//Adds to G
    root->getFirstChild()->getSiblings()[2]->getFirstChild()->getSiblings()[0]->addChild('P');//Adds to J
    root->getFirstChild()->getSiblings()[2]->getFirstChild()->getSiblings()[0]->addChild('Q');//Adds to J
    root->printTree();

    std::cout << "\nPre-Order:\n";
    root->preOrder();
    std::cout << "\nIn-Order:\n";
    root->inOrder();
    std::cout << "\nPostOrder:\n";
    root->postOrder();

    //find data test
    std::cout << '\n';
    root->findData(2, 'Q');
    root->findData(1, 'Z');
    root->findData(4, 'D');

    //add O as a child of G
    root->getFirstChild()->getSiblings()[4]->addChild('O');
    root->findData(3, 'O');

    delete root;
    return 0;
}