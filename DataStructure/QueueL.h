//
// Created by ShiJJ on 2020/8/25.
//

#ifndef DATASTRUCTURE_ALGORITHM_QUEUEL_H
#define DATASTRUCTURE_ALGORITHM_QUEUEL_H

template <class T>
class QueueL {
private:
    struct node{
        T obj;
        node *next;
    };
    node *top;
    node *end;
    int size;
public:
    QueueL();
    ~QueueL();
    void push(T obj);
    void pop();
    int getSize();
    T getTop();
    T getEnd();
    bool empty();

};

template <class T>
QueueL<T>::QueueL() {
    top = nullptr;
    end = nullptr;
    size = 0;
}

template <class T>
void QueueL<T>::push(T obj) {
    if(!top && !end){
        top = new node();
        top->obj = obj;
        top->next = nullptr;
        end = top;
    } else {
        node *temp = new node();
        temp->obj = obj;
        temp->next = nullptr;
        end->next = temp;
        end = temp;
    }
    size++;
}

template <class T>
void QueueL<T>::pop() {
    node *temp = top->next;
    delete top;
    top = temp;
    size--;

}

template <class T>
T QueueL<T>::getTop() {
    return top->obj;
}

template <class T>
T QueueL<T>::getEnd() {
    return end->obj;
}

template <class T>
int QueueL<T>::getSize() {
    return size;
}

template <class T>
bool QueueL<T>::empty() {
    return !size;
}

template <class T>
QueueL<T>::~QueueL() {
    while (top != nullptr){
        node *temp = top->next;
        delete top;
        top = temp;
    }
}
#endif //DATASTRUCTURE_ALGORITHM_QUEUEL_H
