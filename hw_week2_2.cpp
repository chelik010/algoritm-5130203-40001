// Задача 9.2: Пример с явным и неявным приведением типов
#include <iostream>
using namespace std;

int main()
{
    int x = 5;
    double y = 2.5;
    int z = x + y; 
    cout << "Initial z = " << z << endl;
    z = (int)y + x;
    cout << "Updated z = " << z << endl;
    return 0;
}
