#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <typeinfo>
using namespace std;

// esta estructura será la que ocupemos para leer los datos del archivo .dat
struct Ticket
{
	char rut_funcionario[10];
	int day_of_month;
	char time[6];
};

void identificarServicioPorHora(char time[6])
{
	if ((time[0] == '0') && (time[1] > '6'))
	{
		cout << "DESAYUNO" << endl;
	}
	else if ((time[0] = '1') && (time[1] < '5'))
	{
		cout << "ALMUERZO" << endl;
	}
	else if ((time[0] == '1') && ((time[1] < '9') && (time[1] > '8')))
	{
		cout << "ONCE" << endl;
	}
	else if ((time[0] == '2') && (time[1] < '2'))
	{
		cout << "CENA" << endl;
	}
	else if (((time[0] == '2') && (time[1] < '4')) || ((time[0] == '0') && (time[1] > '3'))) { // pendiente
		cout << "NOCTURNO" << endl;
	}
	else
	{
		cout << "INVALIDO" << endl;
	}
}
/*
void ticketValidoPorDiarios(char time[6])
{
	if (time[0] > )
{
	// verificaremos el timepo de servicio
}
*/
int main()
{
	// leyendo archivo de tipo binario
	ifstream fp;
	Ticket tickets; // dado que no es un array, luego al leer en el while, no se guardarán los datos anteriores

	// se abre le archivo binario

	fp.open("casoT1/tickets.dat", ios::binary);
	if (!fp.is_open())
	{
		cerr << " Error el abrir el archivo " << endl;
		return -1; // error
	}
	int n;
	// se lee el primer dato de tipo entero, el cual indica en número de tickets
	fp.read((char *)&n, sizeof(int));
	Ticket ticketsData[n]; // declaramos el array para guardar la información de los tickets

	int i = 0;
	while (fp.read((char *)&tickets, sizeof(Ticket)))
	{
		// cout << typeid(tickets.rut_funcionario).name() << "\t" << typeid(tickets.day_of_month).name() << "\t" << typeid(tickets.time).name() << endl;
		ticketsData[i] = tickets; // guardamos los datos en el array de tipo Ticket
		i++;
	}

	for (int j = 0; j < n; j++)
	{
		// cout << ticketsData[j].rut_funcionario << "\t" << ticketsData[j].day_of_month << "\t" << ticketsData[j].time << endl;
		identificarServicioPorHora(ticketsData[j].time);
		cout << ticketsData[j].time[0] << ticketsData[j].time[1] << endl;
		cout << ticketsData[j].time << endl;
		cout << " - - - - - - - - - - - - - - - - - " << endl;
	}

	fp.close();

	system("pause");
	return 0;
}