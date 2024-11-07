#include "MyHashTable.h"


// Eliminar el main
int main() {
    MyHashTable table;

    table.put("Carlos", 42);
    table.put("María", 18);
    table.put("Juan", 25);
    table.put("Lucía", 37);
    table.put("Pedro", 60);
    table.put("Ana", 22);
    table.put("Luis", 34);
    table.put("Elena", 29);
    table.put("Jorge", 50);
    table.put("Sofía", 33);
    table.put("Miguel", 45);
    table.put("Isabel", 19);
    table.put("Raúl", 28);
    table.put("Clara", 31);
    table.put("Pablo", 40);
    table.put("Laura", 26);
    table.put("Daniel", 53);
    table.put("Teresa", 47);
    table.put("Álvaro", 38);
    table.put("Carmen", 21);
    table.put("Fernando", 49);
    table.put("Paula", 27);
    table.put("Hugo", 44);
    table.put("Marta", 35);
    table.put("Diego", 30);
    table.put("Sara", 32);
    table.put("Adrián", 41);
    table.put("Nuria", 24);
    table.put("Iván", 36);
    table.put("Andrea", 23);

    // Test get
    try {
        cout << "Andrea: " << table.get("Andrea") << endl;
        cout << "Luis: " << table.get("Luis") << endl;
        cout << "Daniel: " << table.get("Daniel") << endl;
        cout << "Clara: " << table.get("Clara") << endl;
        cout << "Diego: " << table.get("Diego") << endl;
        cout << "Bernardo: " << table.get("Bernardo") << endl;
    } catch (out_of_range e) {
        cout << e.what() << endl;
    }

    try {
        cout << "Jorge: " << table.get("Jorge") << endl;
        table.remove("Jorge");
        cout << "Jorge: " << table.get("Jorge") << endl;
        table.remove("Luis");
        table.remove("Daniel");
        table.remove("Clara");
        table.remove("Diego");
        table.remove("Bernardo");
    } catch (out_of_range e) {
        cout << e.what() << endl;
    }
    table.put("Jorge", 23);
}