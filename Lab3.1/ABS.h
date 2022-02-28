//
// Created by Lorne Huxtable on 2/1/2022.
//

#ifndef LAB3_ABS_H
#define LAB3_ABS_H
#include <exception>
#include <iostream>
#include <stdexcept>
using namespace std;


#endif //LAB3_ABS_H
template <typename T>
class ABS {
    unsigned int _capacity;
    unsigned int _size;
    T* absArray;


public:
    ABS();
    ABS(int capacity);
    ABS(const ABS &d);
    ABS &operator=(const ABS &d);
    ~ABS();
    void push(T data);
    T pop();
    T peek();
    unsigned int getSize();
    unsigned int getMaxCapacity();
    T* getData();
};
using namespace std;

template<typename T>
ABS<T>::ABS() {
    _capacity = 1;
    _size = 0;
    absArray = new T[_capacity];
}

template<typename T>
ABS<T>::ABS(int capacity) {
    _capacity = capacity;
    _size = 0;
    absArray = new T[_capacity];
}

template<typename T>
ABS<T>::ABS(const ABS &d) {
    this->_capacity = d._capacity;
    this->_size = d._size;

    absArray = new T[_capacity];
    for (unsigned int i = 0; i < _capacity; i++) { //maybe change capacity to size
        absArray[i] = d.absArray[i];
    }
}

template<typename T>
ABS<T> &ABS<T>::operator=(const ABS<T> &d) {
    _capacity = d._capacity;
    _size = d._size;
    d.absArray = new T[_capacity];

    for (unsigned int i = 0; i < _capacity; i++) { //maybe change capacity to size
        absArray[i] = d.absArray[i];
    }
    return *this;
}

template<typename T>
ABS<T>::~ABS() {
    delete[] absArray;
    absArray = nullptr;
}

template<typename T>
void ABS<T>::push(T data) {
    if (_size == _capacity) {
        _capacity *= 2;
        T* tempArray = new T[_capacity]; // copy old array elements make a new one and put them in
        for (unsigned int i = 0; i < _capacity; i++) {
            tempArray[i] = absArray[i];
        }

        delete[] absArray;
        absArray = tempArray;
    }
    absArray[_size] = data;
    _size++;

}
template<typename T>
T ABS<T>::pop() {
        if (_size == 0)  {
            throw runtime_error("Runtime Error: ");
        }
    T temp = absArray[_size-1];
        if (_size == _capacity/2 || (_capacity == 5 && _size == 3)) {
            _capacity = _capacity/2;
            T *tempArray = new T[_capacity]; // copy old array elements make a new one and put them in
            _size--;
            for (unsigned int i = 0; i < _size; i++) {
                tempArray[i] = absArray[i];
            }
            delete[] absArray;
            absArray = tempArray;
            return temp;
        }
        else {
            T *tempArray = new T[_capacity]; // copy old array elements make a new one and put them in
            _size--;
            for (unsigned int i = 0; i < _size; i++) {
                tempArray[i] = absArray[i];
            }
            delete[] absArray;
            absArray = tempArray;
            return temp;
        }
}

template<typename T>
T ABS<T>::peek() {
        if (_size > 0) {
            return absArray[_size-1];
        }
        else {
            throw runtime_error("Runtime Error: ");
        }
}

template<typename T>
unsigned int ABS<T>::getSize() {
    return _size;
}

template<typename T>
unsigned int ABS<T>::getMaxCapacity() {
    return _capacity;
}

template<typename T>
T *ABS<T>::getData() {
    return absArray;
}