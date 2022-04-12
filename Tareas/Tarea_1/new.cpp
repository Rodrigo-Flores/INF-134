#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Ticket
{
    char rut_funcionario[10];
    int day_of_month;
    char time[6];
};

struct Servicio {
    char nombre[20];
    int ticketDiario;
    int ticketMensual;
    char tiempoInicio[6];
    char tiempoFin[6];
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
    int i = 0;
    while (fp.read((char *)&tickets, sizeof(Ticket)))
    {
        ticketsData[i] = tickets; // guardamos los datos en el array de tipo Ticket
        i++;
    }
    fp.close();

    // read servicios.txt)
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
    
    //split servicios.txt by name int int time time
    Servicio serviciosData[numeroservicios];
    for (int i = 0; i < numeroservicios; i++) {
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
        
        /*
        cout << "Servicio: " << servicio_name << endl;
        cout << "Ticket diarios: " << ticketDiarios << endl;
        cout << "Ticket mensual: " << ticketMensual << endl;
        cout << "Tiempo inicio: " << tiempoInicio << endl;
        cout << "Tiempo fin: " << tiempoFin << endl;
        cout << " - - - - - - - - - - - " << endl;
        */
    }

    return 0;
}