#include <iostream>
using namespace std;

int main ()
{
    // variable types
    int a;
    float b;
    char c;
    bool d;

    // variable initialization
    a = 0;
    b = 0.0;
    c = 'a';
    d = true;

    // variable output
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
    cout << "d = " << d << endl;

    // example
    string name;
    int age;
    cout << "Enter your name: "; cin >> name;
    cout << "Enter your age: "; cin >> age;

    cout << "Hello " << name << "! You are " << age << " years old." << endl;

    return 0;
}