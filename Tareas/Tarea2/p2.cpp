#include <iostream>
#include "Components/ranked-abb.hpp"
using namespace std;

int main()
{
    ABB arbol;
    
    for (int i = 0; i < 100; i++)
    {
        arbol.insert(i);
    }

    cout << arbol.rank(10) << endl;

    arbol.eraseABB(arbol.get_raiz());
    return 0;
}