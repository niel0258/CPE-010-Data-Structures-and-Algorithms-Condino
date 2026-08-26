#include <iostream>

const int maxCap = 100;

template <typename T>
class Stack {
    protected:
        T stackArr[maxCap];
        int topStack;
        
    public:
        Stack() {
            topStack = -1;
        }

        void push(T newData);
        void pop();
        T top();
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
void Stack<T>::push(T newData) {
    if (isFull()) {
        std::cout << "stack overflow\n";
        return;
    }
    stackArr[++topStack] = newData;
}

template <typename T>
void Stack<T>::pop() {
    if (isEmpty()) {
        std::cout << "stack underflow\n";
        return;
    }
    topStack--;
}

template <typename T>
T Stack<T>::top() {
    if (isEmpty()) {
        std::cout << "no stack elements\n";
        return T();
    }
    return stackArr[topStack];
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
