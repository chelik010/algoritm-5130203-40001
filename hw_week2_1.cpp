#include <iostream>
using namespace std;

int sumOfDivisors(int num)
{
    int sum = 0;
    for (int i = 1; i <= num; i++)
    {
        if (num % i == 0)
        {
            sum += i;
        }
    }
    return sum;
}

int main()
{
    int A, B;
    cout << "Введите два числа в диапазоне [10, 1000]: ";
    cin >> A >> B;
    
    if (A < 10 || A > 1000 || B < 10 || B > 1000)
    {
        cout << "Числа должны быть в диапазоне [10, 1000]!" << endl;
        return 1;
    }
    
    int sumA = sumOfDivisors(A);
    int sumB = sumOfDivisors(B);
    
    cout << "Сумма делителей A: " << sumA << endl;
    cout << "Сумма делителей B: " << sumB << endl;
    cout << "Общая сумма делителей: " << sumA + sumB << endl;
    return 0;
}
