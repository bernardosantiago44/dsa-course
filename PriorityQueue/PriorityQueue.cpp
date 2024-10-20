#include "PriorityQueue.h"

template<typename T>
PriorityQueue<T>::PriorityQueue(int length) {
    this->data = new T[length+1];
    this->length = length;
    this->arr_size = 0;
}

template<typename T>
PriorityQueue<T>::~PriorityQueue() {
    delete[] this->data;
}

// Duplica la capacidad del array actual
template<typename T>
void PriorityQueue<T>::regrowArray() {
    T* temp = this->data;
    this->data = new T[2 * length + 1];
    this->length *= 2;

    // copiar los datos al nuevo array
    for (int i = 1; i <= this->arr_size; i++) {
        (this->data)[i] = temp[i];
    }
    delete[] temp;
}

template<typename T>
void PriorityQueue<T>::push(T data) {
    if (this->arr_size == this->length) {
        this->regrowArray();
    }
    this->data[arr_size+1] = data;
    arr_size++;
}

template<typename T>
void PriorityQueue<T>::print() const {
    cout << "Capacity: " << this->length << endl;
    for (int i = 1; i <= this->arr_size; i++) {
        cout << data[i] << ", ";
    }
    cout << endl;
}