#include <iostream>
#include <fstream>

using namespace std;

struct S
{
    char nombre[10];
    int contador = 0;
};

struct Trabajador
{
    char rut[10];
    int ticketsValidos = 0;
    int ticketsTotales = 0;
    S servicios[n];
};

struct Ticket
{
    char rut_funcionario[10];
    int day_of_month;
    char time[6];
};

int main()
{
    ifstream file;
    int n, i = 0;
    Ticket t;

    file.open("casoT1/tickets.dat", ios::binary);

    file.read((char *)&n, sizeof(int));
    Ticket ticket[n];
    while (file.read((char *)&t, sizeof(Ticket)))
    {
        ticket[i] = t;
        i++;
    }

    struct Trabajador
    {
        char rut[10];
        int ticketsValidos = 0;
        int ticketsTotales = 0;
        S servicios[noboolalpha];
    };

    // leer archivo binario
    // leer archivo de servivios

    // contar tikcets y ordenarlos por rut, día y servivicio
    // crear función de lectura de datos (filtro)

    return 0;
}