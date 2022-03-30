#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Ticket {
	char rut_funcionario[10];
	int day_of_month;
	char time[10];
};

int main() {
	string s1, s2;
	// int a;
	ifstream fp;


	/* ESCRIBIMOS EN UN ARCHIVO ASCII */
	/*
	// se abre el archivo
	fp.open("servicios.txt");

	// verificamos si el archivo se abre correctamente
	if (!fp.is_open()) {
		cout << "Error al abrir el archivo" << endl;
		return 1;
	}
	// escribe un string en el archivo
	fp << "ESCRIBIENDO TEXTO" << endl;

	// escribe un entero en el arhcivo
	fp << 2022 << endl;

	// se cierra el archivo
	fp.close()

	fp.open("servicios.txt");
	if (!fp.is_open()) {
		cout << "Error al abrir el archivo" << endl;
		return 1;
	}
	*/

	/* LEEMOS UN ARCHIVO ASCII */
	/*
	// lee "ESCRIBIENDO" y lo guarda en s1
	fp >> s1;

	// lee TEXTO y lo guarda en s2
	fp >> s1;

	// lee 2022 y lo guarda en a
	fp >> a;

	fp.close()
	*/

	/* LEYENDO CARACTER A CARACTER */

	char c;
	fp.open("sismos.txt");
	if (!fp.is_open ()) {
		cout << "Error  el abrir  el  archivo" << endl;
		return 1; //
	}
	while((c = fp.get()) != EOF) {
		cout << c;
	}
	cout << endl;
	fp.close ();

	return 0;
}