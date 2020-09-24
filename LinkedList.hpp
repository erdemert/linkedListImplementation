#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>

#include "Node.hpp"

template <class T>
class LinkedList {
public: // DO NOT CHANGE THIS PART.
    LinkedList();
    LinkedList(const LinkedList &obj);

    ~LinkedList();

    int getSize() const;
    bool isEmpty() const;

    void insertAtTheFront(const T &data);
    void insertAtTheEnd(const T &data);
    void insertBeforeNode(const T &data, Node<T> *node);

    void deleteNode(Node<T> *node);
    void deleteAllNodes();

    Node<T> *getFirstNode() const;
    Node<T> *getLastNode() const;
    Node<T> *getNodeWithData(const T &data) const;

    void traverseAllNodes();
    void traverseAllNodes(Node<T> *node);

    LinkedList &operator=(const LinkedList &rhs);

private: // YOU MAY ADD YOUR OWN UTILITY MEMBER FUNCTIONS HERE.
    bool isNodeInTheList(Node<T> *node);


private: // DO NOT CHANGE THIS PART.
    int size;

    Node<T> *head;
    Node<T> *tail;
};

template <class T>
LinkedList<T>::LinkedList() {
    head = NULL;
    tail = NULL;
    size = 0;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList &obj) {

  *this = obj;
  /* todo */
}

template <class T>
LinkedList<T>::~LinkedList() {
    /* TODO */
    deleteAllNodes();
    delete head;
    delete tail;

}

template <class T>
int LinkedList<T>::getSize() const {
    /* TODO */
    return size;
}

template <class T>
bool LinkedList<T>::isEmpty() const {
    /* TODO */
     if(head == NULL) return true;
     else return false;
}

template <class T>
void LinkedList<T>::insertAtTheFront(const T &data) {
    /* TODO */

    if(!isEmpty()){
        Node<T> *ptr = new Node<T>;
        ptr->data = data;
        ptr->next = head;
        head->prev = ptr;
        head = ptr;
        size++;
    } else{
        Node<T> *ptr = new Node<T>;
        ptr->data = data;
        head = ptr;
        tail = ptr;
        size++;
    }
}

template <class T>
void LinkedList<T>::insertAtTheEnd(const T &data) {
    /* TODO */

    if(!isEmpty()){
        Node<T> *ptr = new Node<T>;
        ptr->data = data;
        ptr->prev = tail;
        tail->next = ptr;
        tail = ptr;
        size++;
    } else{
        Node<T> *ptr = new Node<T>;
        ptr->data = data;
        head = ptr;
        tail = ptr;
        size++;
    }
}

template <class T>
void LinkedList<T>::insertBeforeNode(const T &data, Node<T> *node) {
    /* TODO */
    if(!isEmpty()){
        int check = 0;
        Node<T> *ptr = head;
        while(ptr != NULL){
            if(ptr == node){
                check = 1;
                break;
            }
            ptr = ptr->next;
        }
        ptr = NULL;
        delete ptr;
        if(check){
            Node<T> *nodd = new Node<T>;
            if(node->prev == NULL){
                nodd->data = data;
                node->prev = nodd;
                nodd->next = node;
                head = nodd;
            } else{
                nodd->data = data;
                node->prev->next = nodd;
                nodd->prev = node->prev;
                node->prev = nodd;
                nodd->next = node;
            }
            size++;
        }
    }
}

template <class T>
void LinkedList<T>::deleteNode(Node<T> *node) {
    /* TODO */

    if(node->prev == NULL && node->next == NULL){
        Node<T> *ptr = head;
        delete ptr;
        head = NULL;
        tail = NULL;
    } else if (node->prev == NULL){
        Node<T> *ptr = head;
        ptr->next->prev = NULL;
        head = ptr->next;
        delete ptr;
    } else if (node->next == NULL){
        Node<T> *ptr = tail;
        ptr->prev->next = NULL;
        tail = ptr->prev;
        delete ptr;
    } else{
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }
    size--;
}

template <class T>
void LinkedList<T>::deleteAllNodes() {
    /* TODO */

    while(!isEmpty()) deleteNode(head);

    /* trash
    if(!isEmpty()){
        while(!isEmpty()){
            Node<T>* temp = head;
            temp->next->prev = head;
            head = temp->next;
            delete temp;
        }
    size = 0;
    }
    */

}

template <class T>
Node<T> * LinkedList<T>::getFirstNode() const {
    /* TODO */
    if (isEmpty()) return NULL;
    else return head;
}

template <class T>
Node<T> * LinkedList<T>::getLastNode() const {
    /* TODO */
    if (isEmpty()) return NULL;
    else return tail;
}

template <class T>
Node<T> * LinkedList<T>::getNodeWithData(const T &data) const {
    /* TODO */
    if(isEmpty()) return NULL;
    Node<T> *ptr = head;
    int match = 0;
    while(ptr != NULL){
        if(ptr->data == data){
            match = 1;
            break;
        }
        ptr = ptr->next;
    }
    if(match) return ptr;
    else return NULL;
}

template <class T>
void LinkedList<T>::traverseAllNodes() {
    if (head == NULL) {
        std::cout << "empty" << std::endl;
        return;
    }

    Node<T> *temp = head;

    while (temp) {
        std::cout << *temp << " ";
        temp = temp->next;
    }

    std::cout << std::endl;
}

template <class T>
void LinkedList<T>::traverseAllNodes(Node<T> *node) {
    /* TODO */
    if (head == NULL) {
        std::cout << "empty" << std::endl;
        return;
    }
    
    Node<T> *temp = node;

    while (temp) {
        std::cout << *temp << " ";
        temp = temp->next;
    }
    temp = head;
    while(temp != node){
        std::cout << *temp << " ";
        temp = temp->next;
    }

    std::cout << std::endl;
}

template <class T>
LinkedList<T> & LinkedList<T>::operator=(const LinkedList &rhs) {
    /* TODO */ 
    if(this != &rhs){ int count = 0;
        deleteAllNodes();
        Node<T> *ptr = rhs.head;
        while(ptr != NULL){count++;
                  /*  if(count==1) {Node<T> *pointer = new Node<T>; pointer->data = ptr->data; head=pointer; pointer->next=ptr->next; ptr=ptr->next; continue;  }
                    if(count == size) {Node<T> *pointer2 = new Node<T>; pointer2->data = ptr->data; tail = pointer2; pointer2->prev = ptr->prev; break;}  */
                insertAtTheEnd(ptr->data);
                    
                            
    
                ptr = ptr->next;
        }
    }
    return *this;
}


template <class T>
bool LinkedList<T>::isNodeInTheList(Node<T> *node) {
    if (node) {
        Node<T> *temp = head;

        while (temp) {
            if (temp == node) return true;
            temp = temp->next;
        }
    }

    return false;
}

#endif //LINKED_LIST_HPP

