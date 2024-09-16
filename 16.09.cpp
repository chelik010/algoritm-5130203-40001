#include <iostream>
using namespace std;
int main()
{
    int number1, i, count=0;

    cout << "Введите число:";
    cin >> number1;

    for (i=1; i <= number1; i++)
    {
        if(number1 % i == 0)
        {
        cout << i <<" ";
        count = count + i;
        }
    }
    cout << endl << "Сумма делителей: " << count << endl;

}