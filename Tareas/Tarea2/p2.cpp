#include <iostream>
using namespace std;

typedef int tipoElementoArbol;

struct tipoNodoArbolBin
{
    tipoElementoArbol info;
    tipoNodoArbolBin *izq;
    tipoNodoArbolBin *der;
};

class tABB
{
private:
    tipoElementoArbol raiz = NULL;
    int nElems = 0;

public:
    tABB()
    {
        tipoElementoArbol raiz = NULL;
        int nElems = 0;
    }
};

int main()
{

    return 0;
}