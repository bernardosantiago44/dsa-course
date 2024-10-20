#pragma once
#include <iostream>

using namespace std;

template<typename T>
class PriorityQueue {
private:
    T* data;
    int length, arr_size;
    void regrowArray();

public:
    PriorityQueue(int length);
    void push(T data);  // Agregar un nuevo nodo. Si la fila 
                        // está llena, reservar más espacio
    void pop();         // Saca de la fila priorizada el dato que tiene mayor prioridad
    T top() const;      // Regresa el valor del dato que esta con mayor prioridad en la fila priorizada.
    bool isEmpty() const;
    int size() const;   // Regresa la cantidad de datos que tiene la fila priorizada
    // ELIMINAR
    void print() const;
    ~PriorityQueue();
};

// Instancias específicas a usar en la actividad
// (Solo ints, pero puede ser útil para la integradora después)
template class PriorityQueue<int>; 