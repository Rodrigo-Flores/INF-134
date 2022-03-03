#include <iostream>
#include <map>
#include <stack>
#include <queue>

using namespace std;

int main ()
{
    cout << "\tARRAYS\n" << endl;
    int array_4_dimension[4];
    int array_5_dimension[3];
    int array_3_dimension[3] = {1, 2, 3};
    int array_2_dimension[2][2] = {{1, 2}, {3, 4}};

    array_4_dimension[0] = 1;
    array_4_dimension[1] = 2;
    array_4_dimension[2] = 3;
    array_4_dimension[3] = 4;

    cout << "array_4_dimension" << endl;
    for (int i = 0; i < 4; i++) {
        cout << array_4_dimension[i] << endl;
    }

    cout << "\narray_5_dimension" << endl;
    for (int i = 0; i < 5; i++) {
        array_5_dimension[i] = i;
    }
    for (int i = 0; i < 5; i++) {
        cout << array_5_dimension[i] << endl;
    }

    cout << "\n - - - - - - - - - - - - - - - - - - - - - - " << endl;
    cout << "\t\nMAPS\n" << endl;
    map<string, string>personal_data;
    personal_data["name"] = "Rodrigo";
    personal_data["age"] = "25";
    personal_data["height"] = "1.75";
    personal_data["weight"] = "80";

    cout << "personal_data" << endl;
    for (auto it = personal_data.begin(); it != personal_data.end(); it++) {
        cout << it->first << ": " << it->second << endl;
    }

    cout << "\n - - - - - - - - - - - - - - - - - - - - - - " << endl;
    cout << "\t\nSTACKS\n" << endl;
    stack<int> numbers;
    numbers.push(1);
    numbers.push(2);
    numbers.push(3);
    numbers.push(4);
    numbers.push(5);

    cout << "numbers" << endl;
    while (!numbers.empty()) {
        cout << numbers.top() << endl;
        numbers.pop();
    }

    cout << "\n - - - - - - - - - - - - - - - - - - - - - - " << endl;
    cout << "\t\nQUEUES\n" << endl;
    queue<int> numbers_queue;
    numbers_queue.push(1);
    numbers_queue.push(2);
    numbers_queue.push(3);
    numbers_queue.push(4);
    numbers_queue.push(5);

    cout << "numbers_queue" << endl;
    while (!numbers_queue.empty()) {
        cout << numbers_queue.front() << endl;
        numbers_queue.pop();
    }
    
}