#include <iostream>
#include <fstream>

using namespace std;

struct Ticket
{
    char rut_funcionario[10];
    int day_of_month;
    char time[6];
};

int main()
{
    ifstream fp;

    // abriendo archivo
    fp.open("casoT1/tickets.dat", ios::binary);
    if (!fp.is_open())
    {
        cerr << " Error el abrir el archivo " << endl;
        return -1; // error
    }

    // se lee el primer dato de tipo entero, el cual indica en número de tickets
    int numeroTickets;
    fp.read((char *)&numeroTickets, sizeof(int));
    Ticket ticketsData[numeroTickets]; // declaramos el array para guardar la información de los tickets

    // guardaremos los datos de tickets en un array de tipo Ticket
    Ticket tickets;
    int j = 0;
    while (fp.read((char *)&tickets, sizeof(Ticket)))
    {
        ticketsData[j] = tickets; // guardamos los datos en el array de tipo Ticket
        j++;
    }

    // print de los datos
    for (int i = 0; i < numeroTickets; i++)
    {
        cout << "Rut: " << ticketsData[i].rut_funcionario << endl;
        cout << "Dia: " << ticketsData[i].day_of_month << endl;
        cout << "Hora: " << ticketsData[i].time << endl;
        cout << " - - - - - - - - - - - - - - - - " << endl;
    }

    fp.close();

    return 0;
}