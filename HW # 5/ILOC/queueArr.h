#ifndef QueueArray_H
#define QueueArray_H

//Circular Queue
#include <cstddef>
#include <iostream>

template<typename T>
class QueueArray{
    private:
        //pointer to dynamically allocate array
        T* q_arr;
        //maximum num of elem
        std::size_t q_capacity;
        //current number of elements
        std::size_t q_size;
        //Index of front
        int q_front;
        //index of back
        int q_back;
    public:
    //Constructor
    QueueArray(std::size_t capacity = 10);
    //Destructor
    ~QueueArray();
    //Copy const
    QueueArray(const QueueArray& other);
    //Copy assignment operator
    QueueArray& operator=(const QueueArray& other);
    //q operations
    bool Full();
    bool Empty();
    size_t Size();
    void Clear();
    T Front();
    T Back();
    void Enqueue(T value);
    T Dequeue(); 
};

//Constrictor & Destructor
template<typename T>
QueueArray<T>::QueueArray(std::size_t capacity){
    q_arr = new T[capacity];
    q_capacity = capacity;
    //default size,front,and back
    Clear();
}

template<typename T>
QueueArray<T>::~QueueArray(){
    delete[] q_arr;
}

template<typename T>
QueueArray<T>::QueueArray(const QueueArray &other){
    q_capacity = other.q_capacity;
    q_size = other.q_size;
    q_front = other.q_front;
    q_back = other.q_back;

    // Allocate new array memory
    q_arr = new T[q_capacity];

    // Deep copy existing elements
    for (std::size_t i = 0; i < q_capacity; i++) {
        q_arr[i] = other.q_arr[i];
    }
}

template<typename T>
QueueArray<T>& QueueArray<T>::operator=(const QueueArray &other){
    //Prevent copying self
    if (this == &other){
        return *this;
    }

    //Delete old pointer to prevent memory leaks
    delete[] q_arr;

    q_capacity = other.q_capacity;
    q_size = other.q_size;
    q_front = other.q_front;
    q_back = other.q_back;

    // Allocate new array memory
    q_arr = new T[q_capacity];

    // Deep copy existing elements
    for (std::size_t i = 0; i < q_capacity; i++) {
        q_arr[i] = other.q_arr[i];
    }

    return *this;
}

//Operations
template <typename T>
bool QueueArray<T>::Full(){
    return q_size == q_capacity;
} 

template <typename T>
bool QueueArray<T>::Empty(){
    return q_size == 0;
}

template <typename T>
size_t QueueArray<T>::Size() {
    // RETURN CURRENT SIZE OF QUEUE
    return q_size;
}

template <typename T>
T QueueArray<T>::Front() {
    // Check if the queue is empty
    if (Empty()) {
        std::cout << "Queue is Empty\n";
        return T();
    }
    // Return the front
    return q_arr[q_front];
}

template <typename T>
T QueueArray<T>::Back() {
    // Check if the queue is empty
    if (Empty()) {
        std::cout << "Queue is Empty\n";
        return T();
    }
    // Return the back
    return q_arr[q_back];
}

// Clear()
template <typename T>
void QueueArray<T>::Clear() {
    // Reset the queue to its initial state
    q_size = 0;
    q_front = 0;
    q_back = -1; // Set back to -1 since there are no elements
}

// Enqueue()
template <typename T>
void QueueArray<T>::Enqueue(T value) {
    // Check if the queue is full
    if (Full()) {
        std::cout << "Queue is Full\n";
        return;
    }
    // Increment the back
    q_back = (q_back + 1) % q_capacity;
    // Add the new value to the back of the queue
    q_arr[q_back] = value;
    // Increment the size of the queue
    q_size++;
}

// Dequeue()
template <typename T>
T QueueArray<T>::Dequeue() {
    // Check if the queue is empty
    if (Empty()) {
        std::cout << "Queue is Empty\n";
        return T();
    }
    // Store the front value
    T value = q_arr[q_front];
    // Increment the front index in a circular manner
    q_front = (q_front + 1) % q_capacity;
    // Decrement the size of the queue
    q_size--;
    //reset index if empty
    if (Empty()){
        Clear();
    }
    // Return the dequeued value
    return value;
}

#endif