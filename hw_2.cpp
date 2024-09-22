#include <iostream>
#include <cmath>
#include <cctype> // для возможности использовать и строчные и большие
using namespace std;

int main()
{
    char clientCategory, productCategory, paymentType, creditType;
    double initialPrice, discount = 0, finalPrice;
    int percentRate, numPayments;
    cout << "Введите категорию клиента (A - Отличный, B - Хороший, C - Средний, D - Плохой): ";
    cin >> clientCategory;
    clientCategory = tolower(clientCategory);
    cout << "Введите категорию товара (A, B, C): ";
    cin >> productCategory;
    productCategory = tolower(productCategory);
    cout << "Введите начальную цену товара: ";
    cin >> initialPrice;

    switch(clientCategory)
    {
        case 'a':
            if (productCategory == 'a') discount = 40;
            else if (productCategory == 'b') discount = 30;
            else if (productCategory == 'c') discount = 20;
            break;
        case 'b':
            if (productCategory == 'a') discount = 30;
            else if (productCategory == 'b') discount = 20;
            else if (productCategory == 'c') discount = 10;
            break;
        case 'c':
            if (productCategory == 'a') discount = 20;
            else if (productCategory == 'b') discount = 10;
            else if (productCategory == 'c') discount = 0;
            break;
        case 'd':
            if (productCategory == 'a') discount = 0;
            else if (productCategory == 'b') discount = -5;
            else if (productCategory == 'c') discount = -10;
            break;
        default:
            cout << "Неверная категория клиента." << endl;
            return 1;
    }

    finalPrice = initialPrice * (1 - discount / 100.0);
    cout << "Первоначальная цена: " << initialPrice << endl;
    cout << "Цена после скидки: " << finalPrice << endl;
    cout << "Доступные способы оплаты:\n";
    if (clientCategory == 'a' || clientCategory == 'b')
    {
        cout << "1. Наличные\n";
        cout << "2. Чек\n";
        cout << "3. Кредит\n";
    } 
    else if (clientCategory == 'c')
    {
        cout << "1. Наличные\n";
        cout << "2. Чек\n";
    }
    else if (clientCategory == 'd')
    {
        cout << "1. Только наличные\n";
    }
    cout << "Выберите тип оплаты (N - Наличные, C - Чек, K - Кредит): ";
    cin >> paymentType;
    paymentType = tolower(paymentType);

    if (paymentType == 'c' && (clientCategory == 'a' || clientCategory == 'b' || clientCategory == 'c')) 
    { 
        cout << "Введите процентную ставку (от 3 до 15%): ";
        cin >> percentRate;
        cout << "Введите количество взносов: ";
        cin >> numPayments;

        finalPrice = finalPrice * (1 + percentRate * numPayments / 100.0);
        cout << "Итоговая сумма к оплате по чеку: " << finalPrice << endl;

    }
    else if (paymentType == 'k' && (clientCategory == 'a' || clientCategory == 'b'))
    {
        cout << "Введите тип кредита (P - Платиновый, B - Бизнес): ";
        cin >> creditType;
        creditType = tolower(creditType);
        cout << "Введите количество платежей (от 1 до 6): ";
        cin >> numPayments;
        double interestRate = (creditType == 'p') ? 5 : 2;
        finalPrice = finalPrice * pow(1 + interestRate / 100, numPayments);
        cout << "Итоговая сумма к оплате по кредиту: " << finalPrice << endl;

    }
    else if (paymentType == 'n')
    {
        cout << "Итоговая сумма к оплате наличными: " << finalPrice << endl;
    }
    else
    {
        cout << "Неверный тип оплаты!" << endl;
    }
    return 0;
}
