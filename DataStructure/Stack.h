//
// Created by ShiJJ on 2020/8/24.
//

#ifndef DATASTRUCTURE_ALGORITHM_STACK_H
#define DATASTRUCTURE_ALGORITHM_STACK_H

#include <iostream>
#include <cstring>
#include "Stack.h"
template <class T>class Stack {
private:
    T *container = nullptr;
    int top;
    int size;
    int capacity;
    void reserve(int n);
public:
    Stack();
    Stack(int n);
    ~Stack();
    void push(T obj);
    T pop();
    T getTop();
    int getSize();
    bool empty()const;
};


template <class T>
Stack<T>::Stack() {
    size = 0;
    capacity = 0;
    top = -1;
    container = new T(capacity);
}

template <class T>
Stack<T>::Stack(int n) {
    size = 0;
    capacity = n;
    top = -1;
    container = new T(capacity);
}

template <class T>
Stack<T>::~Stack() {
    if(container){
        delete[] container;
    }

}

template <class T>
void Stack<T>::reserve(int n) {
    if(n > capacity){
        capacity = 1;
        if(n > capacity){
            capacity = 2;
            while (n > capacity){
                capacity *= 2;
            }
        }

        delete[] container;
        container = new T[capacity];
    }
}

template <class T>
void Stack<T>::push(T obj) {

    if(size >= capacity){
        T *temp = new T[size];
        for(int i = 0; i < size; i++){
            temp[i] = container[i];
        }
        reserve(size+1);
        for(int i = 0; i < size; i++){
            container[i] = temp[i];
        }
        delete[] temp;
    }
    container[++top] = obj;
    size++;
}

template <class T>
T Stack<T>::pop() {
    size--;
    return container[top--];
}

template <class T>
bool Stack<T>::empty() const {
    return !size;
}

template <class T>
T Stack<T>::getTop() {
    if(!size){
        return 0;
    } else {
        return container[top];
    }
}

template <class T>
int Stack<T>::getSize() {
    return size;
}

#endif //DATASTRUCTURE_ALGORITHM_STACK_H
