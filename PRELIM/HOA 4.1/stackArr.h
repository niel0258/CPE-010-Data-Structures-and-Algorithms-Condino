#include <iostream>

const int maxCap = 10;

template <typename T>
class Stack {
    protected:
        T stackArr[maxCap];
        int topStack;
        T newData;
        
    public:
        Stack() {
            topStack = -1;
        }

        void push();
        void pop();
        void top();
        bool isEmpty();
        bool isFull();
        void displayStack();
};

template <typename T>
bool Stack<T>::isEmpty() {
    return (topStack == -1);
}

template <typename T>
bool Stack<T>::isFull() {
    return (topStack == maxCap - 1);
}

template <typename T>
void Stack<T>::push() {
    if (isFull()) {
        std::cout << "stack overflow\n";
        return;
    }
    std::cout << "Enter a value: ";
    std::cin >> newData;
    stackArr[++topStack] = newData;
}

template <typename T>
void Stack<T>::pop() {
    if (isEmpty()) {
        std::cout << "stack underflow\n";
        return;
    }
    top();
    topStack--;
}

template <typename T>
void Stack<T>::top() {
    if (isEmpty()) {
        std::cout << "no stack elements\n";
        return;
    }
    std::cout << "Top value is: " << stackArr[topStack] << std::endl;
}

template <typename T>
void Stack<T>::displayStack() {
    if (isEmpty()) {
        std::cout << "Stack is empty.\n";
        return;
    }
    std::cout << "Stack elements (top to bottom): ";
    for (int i = topStack; i >= 0; i--) {
        std::cout << stackArr[i] << (i == 0 ? "" : ",");
    }
    std::cout << '\n';
}