#include <iostream>
using namespace std;

int main()
{
    int test_option;
    cout << "Enter a test option:\n";
    cout << "1. while loop" << endl;
    cout << "2. do while loop" << endl;
    cout << "3. for loop" << endl;
    cin >> test_option;

    // 1. while loop
    float total_price, price_per_item;
    string option;
    option = "y";

    // 2. do while loop
    float total_price_2, price_per_item_2;
    string option_2;
    option_2 = "y";

    // 3. for loop
    int quantity;
    float total_price_3, price_per_item_3;

    switch (test_option)
    {
    case 1:
        while ((option == "y") || (option == "Y"))
        {
            cout << "Add item price > ";
            cin >> price_per_item;
            total_price += price_per_item;
            cout << "Do you want to add another item? (y/n): ";
            cin >> option;
        }

        cout << "\nTotal price: " << total_price << endl;
        break;
    case 2:
        do
        {
            cout << "Add item price > ";
            cin >> price_per_item_2;
            total_price_2 += price_per_item_2;
            cout << "Do you want to add another item? (y/n): ";
            cin >> option_2;
        } while ((option_2 == "y") || (option_2 == "Y"));

        cout << "\nTotal price: " << total_price_2 << endl;
        break;
    case 3:
        cout << "Enter quantity of items > ";
        cin >> quantity;
        for (int i = 0; i < quantity; i++)
        {
            cout << "Add item price > ";
            cin >> price_per_item_3;
            total_price_3 += price_per_item_3;
        }

        cout << "\nTotal price: " << total_price_3 << endl;
        break;
    default:
        cout << "Invalid option!" << endl;
        break;
    }

    return 0;
}