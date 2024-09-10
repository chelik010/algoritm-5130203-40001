#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a, b, g;
    float f;
    cout << "Введите A: ";
    cin >> a;
    cout << "Введите B: ";
    cin >> b;

    if (a < b)
    {
        f = sqrt(a) * b;
    }
    else if (a > b && b < 0)
    {
        f = pow(a, 2) + b;
    }
    else if (a > b && b >= 0)
    {
        f = a - b;
    }
    cout << "F = " << f << endl;

    if (a <=1)
    {
        g=0;
    }
    {}
}
