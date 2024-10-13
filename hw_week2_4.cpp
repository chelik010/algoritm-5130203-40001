//Задача 9.1: Пример с отладчиком
#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int b = 20;
    int c = a + b;
    cout << "Initial values:" << endl;
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;
    a = 15;
    c = a + b;
    cout << "Updated values:" << endl;
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;
    return 0;
}
