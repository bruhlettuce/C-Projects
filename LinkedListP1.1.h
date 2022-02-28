//
// Created by Lorne Huxtable on 2/8/2022.
//

#ifndef PROJECT1_LINKEDLISTP1_H
#define PROJECT1_LINKEDLISTP1_H
#endif //PROJECT1_LINKEDLISTP1_H
#include <iostream>
using namespace std;


template <typename T>
class LinkedList {

public:

    struct Node {
        T _data;
        Node* next;
    };

    Node node;
    //Big Three
    LinkedList();
    LinkedList(const LinkedList<T>& list);
    ~LinkedList();

    //Accessors
    unsigned int NodeCount() const;

    //Insertion
    void AddHead(const T &data);
    void AddTail(const T &data);
    void AddNodesHead(const T *data, unsigned int count);
    void AddNodesTail(const T *data, unsigned int count);

    //Behaviors
    void PrintForward() const;
    void PrintReverse() const;
private:
    Node* next;
    Node* head;
    Node* tail;
};

template <typename T>
LinkedList<T>::LinkedList() {
    data = 0;
    head = nullptr;
    tail = nullptr;
}

//
template <typename T>
void LinkedList<T>::AddNodesHead(const T *data, unsigned int count) {

}

template <typename T>
void LinkedList<T>::AddNodesTail(const T *data, unsigned int count) {

}

//Behaviors
template <typename T>
void LinkedList<T>::PrintForward() const {
for (int i = 0; )
    cout <<
}
}

template <typename T>
void LinkedList<T>::PrintReverse() const {

}