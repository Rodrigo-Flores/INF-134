#include <iostream>
using namespace std;

int main ()
{
    int age;
    string name;
    char option;

    cout << "TEST 1:" << endl;
    cout << "Enter your name: "; cin >> name;
    cout << "Enter your age: "; cin >> age;

    if (age < 18)
    {
        cout << name << ", you are not old enough to enter the club." << endl;
    }
    else
    {
        cout << "Welcome to the club, " << name << "!" << endl;
    }

    cout << "\nDo you want to go to the test 2? (y/n): "; cin >> option;

    if (option == 'y' || option == 'Y')
    {
        int age_test_2, option_test_2;
        string name_test_2;

        cout << "\nTEST 2: " << endl;
        cout << "Do you want to go to home? (chose an option below):\n";
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        cout << "3. Maybe" << endl;
        cout << "4. I don't know" << endl;
        cin >> option_test_2;

        switch (option_test_2)
        {
        case 1:
            cout << "You chose option 1. You are going to home." << endl;
            break;
        case 2:
            cout << "You chose option 2. You are not going to home." << endl;
            break;
        case 3:
            cout << "You chose option 3. You aren't sur eto go home yet." << endl;
            break;
        case 4:
            cout << "You chose option 4. You don't know what to do." << endl;
            break;
        default:
            cout << "You chose an invalid option." << endl;
            break;
        }
    } 
    else
    {
        cout << "SAYOONARA" << endl;
    }

    return 0;
}