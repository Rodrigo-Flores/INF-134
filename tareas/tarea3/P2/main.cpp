#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct{
    int id;
    int grado_del_personaje;
};


int calcularGradoNodo(string str);

int main() {
    fstream fp;
    fp.open("data/miserables.csv", ios::in);

    if (!fp.is_open()) {
        cerr << "No se pudo abrir el archivo" << endl;
        return 1; 
    } 
    string linea;
    getline(fp, linea);   //creo que lee la primera linea

    char letra;
    int grado;
    int id;
    while (getline(fp, linea)) {
        int p = linea.find(';');
        id = stoi(linea.substr(0, p)); // verificar si incluye al supremo 
        grado = calcularGradoNodo(linea);

    }
    fp.close();

    return 0;
}

int calcularGradoNodo(string str)
{
	char letra;
    int contador = 0;
    unsigned int posicion_previa = 0;

	int l = str.length();
	for (int i = 0; i < l; i++) {
		letra = str.at(i);
        if (letra == ';') {
            contador += stoi(str.substr(posicion_previa, i));  // verificar si incluye al supremo 
            posicion_previa = i + 1;
        }
	}
    return contador;
}