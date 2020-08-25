//
// Created by ShiJJ on 2020/8/25.
//

#ifndef DATASTRUCTURE_ALGORITHM_STACKL_H
#define DATASTRUCTURE_ALGORITHM_STACKL_H

template <class T>
class StackL {
private:
    struct node{
        T obj;
        node *next;
    };
    int size;
    node *top;
public:
    StackL();
    ~StackL();
    void push(T obj);
    void pop();
    bool empty();
    int getSize();
    T getTop();
};

template <class T>
StackL<T>::StackL() {
    top = nullptr;
    size = 0;
}

template <class T>
void StackL<T>::push(T obj) {
    node *temp = new node();
    temp->obj = obj;
    temp->next = top;
    top = temp;
    size++;
}

template <class T>
void StackL<T>::pop() {
    node *temp = top->next;
    delete top;
    top = temp;
    size--;
}

template <class T>
int StackL<T>::getSize() {
    return size;
}

template <class T>
bool StackL<T>::empty() {
    return !size;
}

template <class T>
StackL<T>::~StackL() {
    while (top != nullptr){
        node *temp = top->next;
        delete top;
        top = temp;
    }
}

template <class T>
T StackL<T>::getTop() {
    return top->obj;
}
#endif //DATASTRUCTURE_ALGORITHM_STACKL_H
