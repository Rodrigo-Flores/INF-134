#include <iostream>
#include <string>
using namespace std;

typedef string TipoClave;
typedef string TipoValor;

struct tipoInfo
{
    TipoClave clave;
    TipoValor valor;
    unsigned int frecuencia = 0;
};

class CacheDiccionario
{
private:
    tipoInfo elementos[128] = {""};
    unsigned int total;
    unsigned int capacidad;

public:
    CacheDiccionario()
    {
        total = 0;
    }
    ~CacheDiccionario();
    int hashFunction(TipoClave clave, bool collision = false)
    {
        int hash = 0;
        if (!collision) {
            for (int i = 0; i < clave.length(); i++)
            {
                hash += clave[i];
            }
            return hash % 128;
        } else {
            for (int i = 0; i < clave.length(); i++)
            {
                hash += (clave[i] * (i + 1));
            }
            return hash % 128;
        }
    }
    void insert(TipoClave clave, TipoValor valor) {
        int p1 = hashFunction(clave);
        if (elementos[p1].clave == clave) {
            int p2 = hashFunction(clave, true);
            while (elementos[p2].clave != "") {
                p2 = (p2 + 1) % 128;
            }
            elementos[p2].clave = clave;
            elementos[p2].valor = valor;
        } else {
            elementos[p1].clave = clave;
            elementos[p1].valor = valor;
        }
    }
        
    bool query(TipoClave clave, TipoValor &valor)
    {
        unsigned int pos = hashFunction(clave);
        if (elementos[pos].clave == clave) {
            valor = elementos[pos].valor;
            elementos[pos].frecuencia++;
            return true;
        } else return false;
        /*else {
            int p2 = hashFunction(clave, true);
            
            while (elementos[p2].clave != "") {
                if (elementos[p2].clave == clave) {
                    valor = elementos[p2].valor;
                    elementos[p2].frecuencia++;
                    return true;
                }
                p2 = (p2 + 1) % 128;
            }
            return false;
        }*/
    }

    void querystats(int &total, int &conocidos, int &desconocidos);
    void perfstats(int &accesses, int &hits, int &misses, int &cleanups);
};