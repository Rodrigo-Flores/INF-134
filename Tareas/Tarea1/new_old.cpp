#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

// Estructura de Ticket que utilizaremos para leer el archivo binario y la creación de arrays
struct Ticket
{
    char rut_funcionario[10];
    int day_of_month;
    char time[6];
};

// Estrucutura de Servicio que utilizaremos para guardar los datos de servicios.txt en un array
struct Servicio
{
    char nombre[20];
    int ticketDiario;
    int ticketMensual;
    char tiempoInicio[6];
    char tiempoFin[6];
};

struct DatosServicio
{
    char rut[10];
    string nombre;
    int cantidad_mes = 0;
};

// Estructura de Trabajador que utilizaremos para guardar la información final de sus tickets (como una especie de hash)
struct Trabajador
{
    char rut[10];
    int ticketsValidos = 0;
    int ticketsTotales = 0;
};

/*****
 * int pasarHoraASegundos
 ******
 * Transforma hora de formato hh:mm a segundos representados
 ******
 * Input:
 * int time[6] : Recibe un array de hora con formato hh:mm
 ******
 * Returns:
 * int, retorna la hora representada en segundos
 *****/
int pasarHoraASegundos(char time[6])
{
    int hora = (time[0] - '0') * 10 + (time[1] - '0');
    int minutos = (time[3] - '0') * 10 + (time[4] - '0');
    return hora * 3600 + minutos * 60;
}

/*****
 * bool ticketsValidosPorHoraServicio
 ******
 * Se encarga de ver si un ticket es válido o no. Esto dependerá si el ticket fue emitido en un horario válido para un servicio
 ******
 * Input:
 * char time[6] : Recibe la hora del ticket actual
 * Servicio servicio[] : Recibe un array de tipo Servicio que contiene los servicios de servicios.txt
 * int size : Recibe el tamaño del array servicio[]
 ******
 * Returns:
 * bool, retorna true si el ticket es válido, en el caso contrario retorna false
 *****/
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

/*****
 * Trabajador ordernarLexicograficamente
 ******
 * Es básicamente el bubblesort de nuestro programa. Ordena los trabajadores por rut lexicográficamente.
 * Los cambios se hacen con la dirección de memoria, por lo que no se retorna nada; no es necesario, pues
 * el ordenamiento cambia direcatamente en la memoria.
 ******
 * Input:
 * Trabajador (&trabajador)[] : Recibimos la dirección de memoria de un array de tipo Trabajador
 * int size : Recibe el tamaño del array trabajador[]
 ******
 * Returns:
 * void, no retorna nada
 *****/

void ordernarLexicograficamente(Trabajador trabajadoresData[], int size)
{
    Trabajador aux;
    for (int i = 0; i <= size; i++)
    {
        for (int j = i; j < size; j++)
        {
            if (strcmp(trabajadoresData[i].rut, trabajadoresData[j].rut) > 0)
            {
                aux = trabajadoresData[i];
                trabajadoresData[i] = trabajadoresData[j];
                trabajadoresData[j] = aux;
            }
        }
    }
}

/*****
 *
 ******
 *
 ******
 * Input:
 *
 ******
 * Returns:
 *
 *****/
bool buscarRut(string ruts[], string value, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (value == ruts[i])
        {
            return true;
        }
    }
    return false;
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

    string pre_ruts[numeroTickets]{"\0"};
    for (int i = 0; i < numeroTickets; i++)
    {
        if (!buscarRut(pre_ruts, ticketsData[i].rut_funcionario, numeroTickets))
        {
            pre_ruts[i] = ticketsData[i].rut_funcionario;
        }
    }

    int total_ruts = 0;
    for (int i = 0; i < numeroTickets; i++)
    {
        if (pre_ruts[i] != "\0")
        {
            total_ruts++;
        }
    }

    string ruts[total_ruts];
    for (int i = 0; i < total_ruts; i++)
    {
        for (int j = 0; j < numeroTickets; j++)
        {
            if (pre_ruts[j] != "\0")
            {
                ruts[i] = pre_ruts[j];
                pre_ruts[j] = "\0";
                break;
            }
        }
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

    Trabajador trabajadoresData[total_ruts];
    for (int i = 0; i < total_ruts; i++)
    {
        Trabajador trabajador;
        strcpy(trabajador.rut, ruts[i].c_str());
        trabajadoresData[i] = trabajador;
    }

    bool filtro_1 = false; // por hora de servicio
    bool filtro_2 = false; // más de 100 tickets
    // bool filtro_3 = false; // por mes
    // bool filtro_4 = false; // por día

    for (int i = 0; i < total_ruts; i++)
    {
        for (int j = 0; j < numeroTickets; j++)
        {
            if (strcmp(trabajadoresData[i].rut, ticketsData[j].rut_funcionario) == 0)
            {
                filtro_1 = ticketsValidosPorHoraServicio(ticketsData[j].time, serviciosData, numeroservicios);
                filtro_2 = trabajadoresData[i].ticketsTotales <= 100;
                if (filtro_1 && filtro_2)
                {
                    trabajadoresData[i].ticketsValidos++;
                }
                trabajadoresData[i].ticketsTotales++;
            }
        }
    }

    ordernarLexicograficamente(trabajadoresData, total_ruts);

    ofstream fp3;
    fp3.open("casoT1/salida.txt");
    if (!fp3.is_open())
    {
        cerr << " Error el abrir el archivo " << endl;
        return -1; // error
    }

    for (int i = 0; i < total_ruts; i++)
    {
        fp3 << trabajadoresData[i].rut << " " << trabajadoresData[i].ticketsValidos << "/" << trabajadoresData[i].ticketsTotales << endl;
    }

    fp2.close();

    return 0;
}
