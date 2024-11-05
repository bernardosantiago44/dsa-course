#pragma once
#include <string>
#include "MyLinkedList.h"

using namespace std;

class MyHashTable {
    public:
        int size; // La cantidad de elementos en la tabla
        int sizeArray; // Tamaño del arreglo
        MyLinkedList* tabla;
    //private:
        void rehash(); // LLamado por put cuando el factor de carga excede 0.75
        int getPos(string key);
        void deleteLL(MyLinkedList* tabla, int size); // Elimina tofos los elementos de la lista

    //public:
        MyHashTable();
        ~MyHashTable();
        bool isEmpty();
        void put(string key, int value);
        int get(string key); // Si no lo encuentra, arroja una excepción
        void remove(string key); // Si no lo encuentra, arroja una excepción
};