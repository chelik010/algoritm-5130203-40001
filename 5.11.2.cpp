#include <iostream>
#include <cstdlib> 
using namespace std;

int main()
{
    int n,even_index = 0, odd_index = 0,even_count = 0, odd_count = 0, temp = n;

    cout << "Введите число n от 100 до 1000000: ";
    cin >> n;

    if (n < 100 || n > 1000000)
    {
        cout << "Число вне диапазона" << endl;
        return 1;
    }


    while (temp > 0)
    {
        int digit = temp % 10;
        if (digit % 2 == 0) even_count++;
        else odd_count++;
        temp /= 10;
    }


    int* A = (int*)malloc((even_count > 0 ? even_count : 1) * sizeof(int));
    int* B = (int*)malloc((odd_count > 0 ? odd_count : 1) * sizeof(int));
    if (even_count == 0) A[0] = 0;
    if (odd_count == 0) B[0] = 0;


    temp = n;

    while (temp > 0)
    {
        int digit = temp % 10;
        if (digit % 2 == 0 && even_count > 0)
        {
            A[even_index++] = digit;
        }
        else if (odd_count > 0) 
        {
            B[odd_index++] = digit;
        }
        temp /= 10;
    }


    int sum_squares_even = 0, product_odd = (odd_count > 0) ? 1 : 0;
    for (int i = 0; i < even_index; i++) sum_squares_even += A[i] * A[i];
    for (int i = 0; i < odd_index; i++) product_odd *= B[i];

    cout << "Вектор A (четные цифры): ";
    for (int i = 0; i < (even_count > 0 ? even_index : 1); i++) cout << A[i] << " ";
    cout << endl;

    cout << "Вектор B (нечетные цифры): ";
    for (int i = 0; i < (odd_count > 0 ? odd_index : 1); i++) cout << B[i] << " ";
    cout << endl;

    cout << "Конечный результат (сумма квадратов четных + произведение нечетных): " << sum_squares_even + product_odd << endl;

    free(A);
    free(B);

    return 0;
}
