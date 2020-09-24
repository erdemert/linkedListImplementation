#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>

// DO NOT CHANGE THIS FILE.

template <class T>
class Node {
public:
    T data;
    Node<T> *prev;
    Node<T> *next;

    Node();
    Node(T data, Node<T> *prev, Node<T> *next);
    Node(const Node<T> &obj);

    friend std::ostream &operator<<(std::ostream &os, const Node<T> &obj) {
        os << obj.data;
        return os;
    }
};

template <class T>
Node<T>::Node() {
    this->prev = NULL;
    this->next = NULL;
}

template <class T>
Node<T>::Node(T data, Node<T> *prev, Node<T> *next) {
    this->data = data;
    this->prev = prev;
    this->next = next;
}

template <class T>
Node<T>::Node(const Node<T> &obj) {
    this->data = obj.data;
    this->prev = obj.prev;
    this->next = obj.next;
}

#endif //NODE_HPP

