//
// Created by Lorne Huxtable on 2/1/2022.
//

#ifndef LAB3_ABQ_H
#define LAB3_ABQ_H
#include <exception>
#include <iostream>
using namespace std;


#endif //LAB3_ABQ_H
template <typename T>
class ABQ {
    unsigned int _capacity;
    unsigned int _size;
    T* abqArray;


public:
    ABQ();
    ABQ(int capacity);
    ABQ(const ABQ &d);
    ABQ &operator=(const ABQ &d);
    ~ABQ();
    void enqueue(T data);
    T dequeue();
    T peek();
    unsigned int getSize();
    unsigned int getMaxCapacity();
    T* getData();
};
using namespace std;

template<typename T>
ABQ<T>::ABQ() {
    _capacity = 1;
    _size = 0;
    abqArray = new T[_capacity];
}

template<typename T>
ABQ<T>::ABQ(int capacity) {
    _capacity = capacity;
    _size = 0;
    abqArray = new T[_capacity];
}

template<typename T>
ABQ<T>::ABQ(const ABQ &d) {
    this->_capacity = d._capacity;
    this->_size = d._size;

    abqArray = new T[_capacity];
    for (unsigned int i = 0; i < _capacity; i++) { //maybe change capacity to size
        abqArray[i] = d.abqArray[i];
    }
}

template<typename T>
ABQ<T> &ABQ<T>::operator=(const ABQ<T> &d) {
    _capacity = d._capacity;
    _size = d._size;
    d.abqArray = new T[_capacity];

    for (unsigned int i = 0; i < _capacity; i++) { //maybe change capacity to size
        d.abqArray[i] = abqArray[i];
    }
    return *this;
}

template<typename T>
ABQ<T>::~ABQ() {
    delete[] abqArray;
    abqArray = nullptr;
}

template<typename T>
void ABQ<T>::enqueue(T data) {
    if (_size == _capacity && _size > 0) {
        _capacity *= 2;
    }
        T* tempArray = new T[_capacity]; // copy old array elements make a new one and put them in
        for (unsigned int i = 1; i <= _size; i++) {
            tempArray[i] = abqArray[i-1];
        }
        delete[] abqArray;
        abqArray = tempArray;
        abqArray[0] = data;
        _size++;
}
template<typename T>
T ABQ<T>::dequeue() {
    if (_size == 0)  {
        throw runtime_error("Runtime Error: ");
    }
    T temp = abqArray[_size-1];
    if (_size == _capacity/2 || (_capacity == 5 && _size == 3)) {
        _capacity = _capacity/2;
        T *tempArray = new T[_capacity]; // copy old array elements make a new one and put them in
        _size--;
        for (unsigned int i = 0; i < _size; i++) {
            tempArray[i] = abqArray[i];
        }
        delete[] abqArray;
        abqArray = tempArray;
        return temp;
    }
    else {
        T *tempArray = new T[_capacity]; // copy old array elements make a new one and put them in
        _size--;
        for (unsigned int i = 0; i < _size; i++) {
            tempArray[i] = abqArray[i];
        }
        delete[] abqArray;
        abqArray = tempArray;
        return temp;
    }
}

template<typename T>
T ABQ<T>::peek() {
    if (_size > 0) {
        return abqArray[_size-1];
    }
    else {
        throw runtime_error("Runtime Error: ");
    }
}

template<typename T>
unsigned int ABQ<T>::getSize() {
    return _size;
}

template<typename T>
unsigned int ABQ<T>::getMaxCapacity() {
    return _capacity;
}

template<typename T>
T *ABQ<T>::getData() {
    return abqArray;
}
