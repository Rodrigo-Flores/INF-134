#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

#define N 4000 // tamaño de la base de datos

// esta estructura será la que ocupemos para leer los datos del archivo .dat
struct Ticket
{
	char rut_funcionario[10];
	int day_of_month;
	char time[6];
};

int main()
{
	// leyendo archivo de tipo ASCII
	/*
	ifstream fp;
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
	*/

	// leyendo archivo de tipo binario
	ifstream fp;
	Ticket tickets; // dado que no es un array, luego al leer en el while, no se guardarán los datos anteriores
	int n;

	// se abre le archivo binario
	fp.open("casoT1/tickets.dat", ios::binary);
	if (!fp.is_open())
	{
		cerr << " Error el abrir el archivo " << endl;
		return -1; // error
	}

	// se lee el primer dato de tipo entero, el cual indica en número de tickets
	fp.read((char *)&n, sizeof(int));
	cout << n << endl;

	// buscamos el resto de datos dados por la estructura Ticket
	while (fp.read((char*)&tickets, sizeof(Ticket)))
	{
		cout << "RUT: " << tickets.rut_funcionario << "\tDía del mes: " << tickets.day_of_month << "\tHora: " << tickets.time << endl;
	}

	fp.close();

	system("pause");
	return 0;
}
