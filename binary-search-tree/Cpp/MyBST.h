#pragma once
#include <iostream>

using namespace std;

struct MyNodeBST {
    int data;
    MyNodeBST *left,
              *right;
    MyNodeBST(int data, MyNodeBST *left, MyNodeBST *right) {
        this->data = data;
        this->left = left;
        this->right = right;
    }

    MyNodeBST(int data) : MyNodeBST(data, 0, 0) {};
    ~MyNodeBST() {
        cout << "deleting node with data " << data << endl;
    }
};

class MyBST{
    private:
        int size;
        MyNodeBST* root;
        bool search(int data,MyNodeBST* current);
        void preorder(MyNodeBST* current);
        void inorder(MyNodeBST* current);
        void postorder(MyNodeBST* current);
        //En caso de hacer alguno de los métodos recursivos y necesiten
        //otro método que haga la recursión deben de colocarlo como privado
        //sólo la función de preparación sería pública
        bool insert(int data, MyNodeBST* current);
        bool remove(int data, MyNodeBST* current);
        void deleteNode(MyNodeBST* node);

        // Regresa el nodo anterior en orden logico
        // (mas a la derecha del subarbol izquierdo)
        MyNodeBST* getPreviousNode(MyNodeBST* current); 
    public:
        MyBST();
        int length();
        bool isEmpty();
        bool search(int data);
        bool insert(int data);//true si lo inserto o no
        bool remove(int data);//si el valor estaba en el árbol lo borra
                              //y regresa true, caso contrario sólo regresa false
        //Estudiar borrado en BST
        //Estudiar AVL
        void preorder();
        void inorder();
        void postorder();
        void level();
        void visit(int type);//Type: 1->preorder,2->inorder.3->postorder,4->level
                                        //Imprime el recorrido separado por comas sin espacio entre los elementos.
        int height();//regresa la altura del BST.
        void ancestors(int data);//imprime los ancestros del valor pasado separados por comas y sin dejar espacios entre ellos.
                                 //el orden de impresión debe ser de la raíz hacía abajo.
                                //Si valor no se localiza en el árbol no imprime nada
        int whatLevelAmI(int data);//regresa el nivel en que se encuentra el valor
                                   //dentro del árbol. Si el valor no está en árbol regresa -1
};