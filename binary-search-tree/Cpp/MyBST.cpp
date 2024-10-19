#include "MyBST.h"
#include <queue>

MyBST::MyBST() {
    this->size = 0;
    this->root = 0;
}

// O(1)
int MyBST::length() {
    return this->size;
}

// O(1)
bool MyBST::isEmpty() {
    return this->size == 0;
}

// Recursive implementarion of search
// Complejidad temporal: O(log(n))
bool MyBST::search(int data, MyNodeBST* current) {
    if (current == nullptr) return false;
    if (current->data == data) {
        return true;
    } else if (data < current->data) {
        // Left of BST
        return search(data, current->left);
    } else {
        // Right of BST
        return search(data, current->right);
    }
}

// Función de preparacion recursiva
// Complejidad temporal: O(log(n))
// Complejidad espacial: O(log(n)) (Call Stack)
bool MyBST::search(int data) {
    MyNodeBST* current = this->root;
    return search(data, current);
}

// Complejidad temporal: O(log(n))
bool MyBST::insert(int data, MyNodeBST* current) {
    if (data == current->data) return false; // El valor ya esta en el arbol
    MyNodeBST *left, *right;
    left = current->left;
    right = current->right;

    // Caso base: si el actual es una hoka,
    // insertar el valor como una hoja
    // Base case: Current is a leaf
    if (data < current->data && left == nullptr) {
        current->left = new MyNodeBST(data);
        this->size++;
        return true;
    } else if (data > current->data && right == nullptr) {
        current->right = new MyNodeBST(data);
        this->size++;
        return true;
    }

    if (data < current->data) {
        return insert(data, current->left);
    } else {
        return insert(data, current->right);
    }
}

// Con ayuda visual de: https://www.cs.usfca.edu/~galles/visualization/BST.html
// Complejidad temporal: O(log(n))
// Complejidad espacial: O(log(n)) (Call Stack)
bool MyBST::insert(int data) {
    MyNodeBST* current = this->root;
    // If the tree is empty, create a root
    if (this->size == 0) {
        this->root = new MyNodeBST(data);
        this->size++;
        return true;
    } 

    return insert(data, this->root);
}

// Regresa el nodo anterior en orden logico
// (mas a la derecha del subarbol izquierdo)
// Complejidad temporal: O(log(n))
MyNodeBST* MyBST::getPreviousNode(MyNodeBST* current) {
    if (current->left == nullptr) return current;
    current = current->left;
    while (current != nullptr && current->right != nullptr) {
        current = current->right;
    }
    return current;
}

// Complejidad temporal: O(log(n))
MyNodeBST* MyBST::deleteNode(MyNodeBST* node) {
    if (node == nullptr) return nullptr; // Precondicion redundante: El nodo NO es nulo
    
    // Si es un nodo hoja:
    if (node->left == nullptr && node->right == nullptr) {
        delete node;
        return nullptr;
    }

    // Si solamente tiene un hijo:
        // Preferentemente ir por el izquierdo. Si no hay,
        // se copia el valor del derecho al actual.
    if (node->left == nullptr) {
        MyNodeBST* temp = node;
        node = node->right; // node.right!
        delete temp;
        return node;
    }

    // Si no hubo hijo derecho, ir por el izquiero
    if (node->right == nullptr) {
        MyNodeBST* temp = node;
        node = node->left;
        delete temp;
        return node;
    }

    // El nodo tiene 2 hijos:
    MyNodeBST* prev = getPreviousNode(node);
    node->data = prev->data;
    node->left = deleteNode(node->left); // LLamada recursiva: el delete se hace en el caso del nodo hoja
    return node;
}

// Complejidad temporal: O(log(n))
// Complejidad espacial: O(log(n)) (Call Stack)
// Con ayuda de visualización de https://youtu.be/LFzAoJJt92M?si=x_dUWgVGzBc7o7ky (sin codigo)
MyNodeBST* MyBST::remove(int data, MyNodeBST* current) {
    // if (current == nullptr) return false;
    if (current == nullptr) return nullptr;

    if (data < current->data) {
        // Llamada recursiva: buscar nodo a eliminar en el sub-arbol izquierdo
        // Regresa el nodo del nuevo sub-arbol (el mismo si no se eliminó)
        current->left = remove(data, current->left);
    } else if (data > current->data) {
        // LLamada recursiva en el lado izquierdo
        current->right = remove(data, current->right);
    } else {
        // Encontramos el nodo a eliminar
        this->deleteNode(current);
    }
    return current;
}

// Complejidad temporal: O(log(n))
// Complejidad espacial: O(log(n)) (Call Stack)
bool MyBST::remove(int data) {
    // Solución de fuerza bruta, pero no aumenta la complejidad
    // O(log(n))
    if (!this->search(data)) {
        return false;
    } else {
        this->size--;
    }
    MyNodeBST* current = this->root;
    this->root = remove(data, current);
    return true;
}

void MyBST::inorder(MyNodeBST* current) {
    if (current == nullptr) return;

    inorder(current->left);
    cout << current->data << ",";
    inorder(current->right);
}

// Complejidad temporal: O(n)
void MyBST::inorder() {
    MyNodeBST* root = this->root;
    inorder(root);
    cout << endl;
}

// Complejidad temporal: O(n)
void MyBST::preorder(MyNodeBST* current) {
    if (current == nullptr) return;

    cout << current->data << ",";
    preorder(current->left);
    preorder(current->right);
}

// Complejidad temporal: O(n)
void MyBST::preorder() {
    MyNodeBST* root = this->root;
    preorder(root);
    cout << endl;
}

// Complejidad temporal: O(n)
void MyBST::postorder(MyNodeBST* current) {
    if (current == nullptr) return;

    postorder(current->left);
    postorder(current->right);
    cout << current->data << ",";
}

// Complejidad temporal: O(n)
void MyBST::postorder() {
    MyNodeBST* root = this->root;
    postorder(root);
    cout << endl;
}


// https://cplusplus.com/reference/queue/queue/ 
// Complejidad temporal: O(n)
void MyBST::level() {
    // Imprimir los nodos nivel por nivel
    // Implementar con una cola
    queue<MyNodeBST*> queue;
    queue.push(this->root);
    while (!queue.empty()) {
        MyNodeBST* current = queue.front();
        queue.pop();
        cout << current->data << ",";

        // Si hay un sub-arbol izquierdo, agregarlo a la cola
        if (current->left != nullptr) {
            queue.push(current->left);
        }

        // Si hay un sub-arbol derecho, agregarlo a la cola
        if (current->right != nullptr) {
            queue.push(current->right);
        }

        // Repite el ciclo
    }
    cout << endl;
}

// Complejidad temporal: O(n)
void MyBST::visit(int type) {
    switch (type) {
    case 1:
        this->preorder();
        break;
    case 2:
        this->inorder();
        break;
    case 3:
        this->postorder();
        break;
    case 4:
        this->level();
        break;
    }
}

// Complejidad temporal: O(n)
int MyBST::height(MyNodeBST* current) {
    if (current == nullptr) return -1;
    int leftHeight = 1 + height(current->left);
    int rightHeight = 1 + height(current->right);

    // Si left height >= right height -> leftHeight
    // SI no, right height
    return (leftHeight >= rightHeight) ? leftHeight : rightHeight;
}

// Complejidad temporal: O(n)
int MyBST::height() {
    MyNodeBST* current = this->root;
    if (current == nullptr) return 0;
    return height(current);
}

// Complejidad temporal: O(log(n))
void MyBST::ancestors(int data, vector<int>& recorrido, MyNodeBST* current) {
    // Si encontramos un null, el valor no existe: borrar la lista de recorridos
    if (current == nullptr) {
        recorrido = {};
        return;
    }

    recorrido.push_back(current->data);
    if (data < current->data) {
        ancestors(data, recorrido, current->left);
    } else if (data > current->data) {
        ancestors(data, recorrido, current->right);
    }
}

// Complejidad temporal: O(log(n))
void MyBST::ancestors(int data) {
    vector<int> values;
    values.reserve(this->height());

    MyNodeBST* current = this->root;
    ancestors(data, values, current);

    if (!values.empty()) {
        for (int v : values) {
            cout << v << ",";
        }
        cout << endl;
    }
}


// Level starts at 0
// Complejidad temporal: O(log(n))
int MyBST::whatLevelAmI(int data) {
    if (!search(data)) {
        return -1;
    }

    int level = 0;
    MyNodeBST* current = this->root;
    while (current->data != data) {
        if (data < current->data) {
            current = current->left;
        } else if (data > current->data) {
            current = current->right;
        }
        level++;
    }
    return level;
}