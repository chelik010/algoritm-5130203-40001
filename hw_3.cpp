#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double x;
    const int n = 20;
    double cosine = 1.0;
    double term = 1.0;

    cout << "Введите значение x (в радианах): ";
    cin >> x;

    for (int k = 1; k <= n; k++)
    {
        term *= (-1) * x * x / (2 * k * (2 * k - 1));
        cosine += term;
    }
    cout << "Приближенное значение cos(" << x << ") = " << cosine << endl;
    return 0;
}
