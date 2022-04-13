#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

struct Ticket
{
    char rut_funcionario[10];
    int day_of_month;
    char time[6];
};

struct Servicio
{
    char nombre[20];
    int ticketDiario;
    int ticketMensual;
    char tiempoInicio[6];
    char tiempoFin[6];
};

struct Trabajador
{
    char rut[10];
    int ticketsValidos;
    int ticketsInvalidos;
    int ticketsTotales;
};

int pasarHoraASegundos(char time[6])
{
    int hora = (time[0] - '0') * 10 + (time[1] - '0');
    int minutos = (time[3] - '0') * 10 + (time[4] - '0');
    return hora * 3600 + minutos * 60;
}


bool ticketsValidosPorHoraServicio(char time[6], Servicio servicio[], int size)
{
    bool valid = false;
    for (int i = 0; i < size; i++)
    {
        int tiempoInicio = pasarHoraASegundos(servicio[i].tiempoInicio);
        int tiempoFin = pasarHoraASegundos(servicio[i].tiempoFin);
        int tiempoTicket = pasarHoraASegundos(time);

        if (tiempoInicio > tiempoFin)
        {
            tiempoFin += tiempoInicio;
        }

        if ((tiempoTicket >= tiempoInicio) && (tiempoTicket <= tiempoFin))
        {
            valid = true;
        }
    }

    return valid;
}

bool ticketsValidosPorDia(int day_of_month, Ticket tickets[], int size)
{
    bool valid = false;
    for (int i = 0; i < size; i++){
        if (tickets[i].day_of_month == day_of_month){
            valid = true;
        }
    }

    return valid;
}

bool ticketsValidosPorMes(int day_of_month, Servicio servicio[], int size)
{
    bool valid = false;
    for (int i = 0; i < size; i++)
    {
        if (servicio[i].ticketMensual <= day_of_month)
        {
            valid = true;
        }
    }

    return valid;
}

int obtenerTicketsEmitidosPorRut(char (&rut)[10], Ticket tickets[], int cantidadTickets)
{
    int ticketsEmitidos = 0;
    for (int i = 0; i < cantidadTickets; i++)
    {
        if (strcmp(rut, tickets[i].rut_funcionario) == 0)
        {
            ticketsEmitidos++;
        }
    }

    return ticketsEmitidos;
}

int obtenerTicketsValidosPorRut(char rut_funcionario[10], Ticket ticket[], int size)
{

}

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

    fp.close();

    ifstream fp2;
    fp2.open("casoT1/servicios.txt");
    if (!fp2.is_open())
    {
        cerr << " Error el abrir el archivo " << endl;
        return -1; // error
    }

    string line;
    getline(fp2, line);

    int numeroservicios = stoi(line);
    string servicios[numeroservicios];
    for (int i = 0; i < numeroservicios; i++)
    {
        getline(fp2, line);
        servicios[i] = line;
    }

    // split servicios.txt by name int int time time
    Servicio serviciosData[numeroservicios];
    for (int i = 0; i < numeroservicios; i++)
    {
        // split string
        string servicio = servicios[i];

        string servicio_name = servicio.substr(0, servicio.find(" "));
        servicio.erase(0, servicio.find(" ") + 1);

        int ticketDiarios = stoi(servicio.substr(0, servicio.find(" ")));
        servicio.erase(0, servicio.find(" ") + 1);

        int ticketMensual = stoi(servicio.substr(0, servicio.find(" ")));
        servicio.erase(0, servicio.find(" ") + 1);

        string tiempoInicio = servicio.substr(0, servicio.find(" "));
        servicio.erase(0, servicio.find(" ") + 1);

        string tiempoFin = servicio.substr(0, servicio.find(" "));
        servicio.erase(0, servicio.find(" ") + 1);

        strcpy(serviciosData[i].nombre, servicio_name.c_str());
        serviciosData[i].ticketDiario = ticketDiarios;
        serviciosData[i].ticketMensual = ticketMensual;
        strcpy(serviciosData[i].tiempoInicio, tiempoInicio.c_str());
        strcpy(serviciosData[i].tiempoFin, tiempoFin.c_str());
    }



    for (int i = 0; i < numeroTickets; i++)
    {
        ticketsValidosPorHoraServicio(ticketsData[i].time, serviciosData, numeroservicios);
        // ticketsValidosPorDia(ticketsData[i].day_of_month, serviciosData, numeroservicios);
        // ticketsValidosPorMes(ticketsData[i].day_of_month, serviciosData, numeroservicios);
        // cout << " - - - - - - - - - - - - - - - - - - " << endl;
    }

    fp2.close();

    return 0;
}