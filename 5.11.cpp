#include <iostream>
using namespace std;

int main()
{
    int company_type, view_company,profit;
    float tax, profit_tax, income;
    cout << "Сфера деятельности компании: 1 - Многонациональный, 2 - Национальный" << endl;
    cin >> company_type;
    cout << "Вид деятельности: 1 - Импортная, 2 - экспортная" << endl;
    cin >> view_company;
    switch(company_type)
    {
        case 1:
            if (view_company == 1) tax = 0.15;
            else if (view_company == 2) tax = 0.05;
            break;
        case 2:
            if (view_company == 1) tax = 0.07;
            else if (view_company == 2) tax = 0.02;
            break;
    }
    cout << "Введите прибыль" << endl;
    cin >> profit;
    profit_tax=profit*tax;
    income=profit-profit_tax;

    cout << "\nНалоговая ставка " <<tax<<endl; 
    cout << "\nНалог составит " <<profit_tax<<endl;  
    cout << "\nДоход составит " <<income<< endl;
    return 0;
}
