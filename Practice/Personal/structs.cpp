#include <iostream>

using namespace std;

struct Persona {
    string nombre;
    int edad;
}persona1;

int main () {
    cout << "Nombre: ";
    cin >> persona1.nombre;

    cout << "Edad: ";
    cin >> persona1.edad;

    cout << "\nImprimiendo datos\n";
    cout << "Nombre: " << persona1.nombre << endl;
    cout << "Edad: " << persona1.edad << endl;

    return 0;
}