//
// Created by Alex on 10/9/2018.
//

#ifndef ASSIGNMENT2CS300_OREDEREDLINKLIST_H
#define ASSIGNMENT2CS300_OREDEREDLINKLIST_H

#include "LinkedList.h"
#include <string>
#include <iostream>


int INDEX = 0;
using namespace std;


template<class T>
class OrderedLinkedList : public LinkedList<T> {
//friend class LinkedList;
private:
    OrderedLinkedList(const OrderedLinkedList &) = delete; //copy constructor
//protected:
//    int count;
//    node<T> *head, *last;
public:
    OrderedLinkedList();

    void insertSorted(T &);

    bool search(T &);

    void deleteNode(T &);

    void displayList();

    ~OrderedLinkedList();

};

template<class T>
OrderedLinkedList<T>::OrderedLinkedList() {
    this->head = this->last = NULL;
    this->count = 0;
}

template<class T>
void OrderedLinkedList<T>::insertSorted(T &element) {
    //OrderedLinkedList<T> *p = new OrderedLinkedList();
    node<T> *newNode = new node<T>;
    newNode->data = element;
if (this->head == NULL) { // I have segmentation fault here.
        this->head = this->last = newNode;
        newNode->next = NULL;
    } else if (element < this->head->data) {
        newNode->next = this->head;
        this->head = newNode;
    } else if (this->last->data < element) {
        this->last->next = newNode;
        this->last = newNode;
    } else if (element > this->head->data) {
        if (this->head->next == NULL) {
            this->head->next = newNode;
            this->last = newNode;
        } else {
            node<T> *p = this->head;
            while (p->next->data < element && p->next != NULL) {
                p = p->next;
            }
            if (p->next == NULL) {
                p->next = newNode;
                this->last = newNode;
            } else {
                newNode->next = p->next;
                p->next = newNode;
            }
        }
    }
    this->count++;

}

template<class T>
bool OrderedLinkedList<T>::search(T &item) {
    node<T> *p = this->head;
    while (p != NULL && p->data < item) {
        p = p->next;
    }
    if (p != NULL) {
        if (p->data == item) {
            cout << p->data <<endl;
            return true;
        }
    }
        return false;

}

template<class T>
void OrderedLinkedList<T>::deleteNode(T &index) {
    if(this->head == NULL){ // if isempty function
        //throw empty list exception. // case one checked
    }
    if(this->head->data == index){ //delete front element
        node<T> * t = this->head;
        this->head = this->head->next;
        delete t;
        this->count--;
        if(this->head == NULL){ // checks for only one node.
            this->last = NULL;
        }

    } else { //go through all eleements
        node<T> *p, *q;
        p = this->head;
        q = this->head->next;
        while(!(q==NULL) && !(q->data == index)){
            p = q;
            q = q->next;
        }
        if(q==NULL){
          //  throw ItemNotFoundException(); //catches item not found
        } else {
            p->next = q->next; //why??*********
            if(q->next == NULL){ // checks to see if node is at the end
                this->last = p;
                delete q;//deletes from middle
                this->count--;
            }
        }
    }
}

template<class T>
void OrderedLinkedList<T>::displayList() {
    node<T> *p = this->head;
    while (p != NULL) {
        cout << p->data << " " << endl;
        p = p->next;
    }
}


template<class T>
OrderedLinkedList<T>::~OrderedLinkedList() {

}


#endif //ASSIGNMENT2CS300_OREDEREDLINKLIST_H
