#include <iostream>

using namespace std;

struct info_direccion {
    string direccion;
    string ciudad;
    string provincia;
};

struct empleado {
    string nombre;
    struct info_direccion dir_empleado;
    double salario;
}empleados[2];

int main () {
    for (int i = 0; i < 2; i++) {
        cout << "Nombre: ";
        cin >> empleados[i].nombre;

        cout << "Direccion: ";
        cin >> empleados[i].dir_empleado.direccion;

        cout << "Ciudad: ";
        cin >> empleados[i].dir_empleado.ciudad;

        cout << "Provincia: ";
        cin >> empleados[i].dir_empleado.provincia;

        cout << "Salario: ";
        cin >> empleados[i].salario;

        cout << "\n\n";

    }

    cout << "\tIMPRIMIENTO DATOS" << "\n\n";

    for (int i = 0; i < 2; i++) {
        cout << "Nombre: " << empleados[i].nombre << endl;
        cout << "Direccion: " << empleados[i].dir_empleado.direccion << endl;
        cout << "Ciudad: " << empleados[i].dir_empleado.ciudad << endl;
        cout << "Provincia: " << empleados[i].dir_empleado.provincia << endl;
        cout << "Salario: " << empleados[i].salario << endl;
        cout << "\n\n";
    }

    return 0;
}