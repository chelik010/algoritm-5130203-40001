//Задача 9.3: Логические операторы
#include <iostream>
using namespace std;

int main()
{
    bool a = true;
    bool b = false;
    bool c = a && b;
    cout << "Initial c (a && b) = " << c << endl;
    c = a || b;
    cout << "Updated c (a || b) = " << c << endl;
    return 0;
}
