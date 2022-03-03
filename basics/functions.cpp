#include <iostream>
using namespace std;

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

float divide(int a, int b) {
    return (float)a / b;
}

int multiply(int a, int b) {
    return a * b;
}

void print(string phrase) {
    cout << phrase << endl;
}

int main ()
{
    char operation;
    cout << "What do you want to do? (+, -, /, *) > ";
    cin >> operation;

    int a, b;
    cout << "Enter two numbers > ";
    cin >> a >> b;

    switch (operation) {
        case '+':
            cout << a << " + " << b << " = " << add(a, b) << endl;
            break;
        case '-':
            cout << a << " - " << b << " = " << subtract(a, b) << endl;
            break;
        case '/':
            cout << a << " / " << b << " = " << divide(a, b) << endl;
            break;
        case '*':
            cout << a << " * " << b << " = " << multiply(a, b) << endl;
            break;
        default:
            cout << "Invalid operation" << endl;
            break;
    }

    print("SAYOONARA");

    return 0;
}