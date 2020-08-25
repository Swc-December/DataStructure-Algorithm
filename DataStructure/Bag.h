//
// Created by ShiJJ on 2020/8/25.
//

#ifndef DATASTRUCTURE_ALGORITHM_BAG_H
#define DATASTRUCTURE_ALGORITHM_BAG_H

template <class T>
class Bag {
private:
    struct node{
        T obj;
        node *next;
    };
    node *first;
public:
    int size;
    class Iterator;
    Bag();
    ~Bag();
    void add(T obj);
    Iterator begin();
    Iterator end();
    class Iterator{
        friend class Bag;

    private:
        node *cur_node;
    public:
        Iterator();
        Iterator(node *p);
        bool operator == (const Iterator &iterator) const ;
        bool operator != (const Iterator &iterator) const ;
        T& operator *() const;
        Iterator& operator++();
        Iterator& operator++(int);
    };
};

template <class T>
Bag<T>::Bag() {
    size = 0;
    first = nullptr;
}

template <class T>
Bag<T>::~Bag() {
    for(Iterator it = this->begin(); it != this->end(); it++){
        delete it.cur_node;
    }
}

template <class T>
typename Bag<T>::Iterator Bag<T>::begin() {
    return Iterator(this->first);
}

template <class T>
typename Bag<T>::Iterator Bag<T>::end() {
    return Iterator(nullptr);
}

template <class T>
void Bag<T>::add(T obj) {
    node *temp = first;
    first = new node();
    first->obj = obj;
    first->next = temp;
    size++;
}

template <class T>
Bag<T>::Iterator::Iterator() {
    cur_node = nullptr;
}

template <class T>
Bag<T>::Iterator::Iterator(node *p) {
    cur_node = p;
}

template <class T>
bool Bag<T>::Iterator::operator==(const Bag<T>::Iterator &iterator) const {
    return cur_node == iterator.cur_node;
}

template <class T>
T & Bag<T>::Iterator::operator*() const {
    return cur_node->obj;
}

template <class T>
bool Bag<T>::Iterator::operator!=(const Iterator &iterator) const{
    return cur_node != iterator.cur_node;
}

template <class T>
typename Bag<T>::Iterator & Bag<T>::Iterator::operator++() {
    cur_node = cur_node->next;
    return *this;
}

template <class T>
typename Bag<T>::Iterator & Bag<T>::Iterator::operator++(int) {
    cur_node = cur_node->next;
    return *this;
}
#endif //DATASTRUCTURE_ALGORITHM_BAG_H
