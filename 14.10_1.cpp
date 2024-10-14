#include <iostream>
using namespace std;

int increment_by_value(int n);
int increment_by_refernce(int *n);

int main()
{
    int n, x1,x2;
    do
    {
       cout<<"N = ";
       cin>>n;
    } while (n<=0);
    // вызываем значение
    cout<<"\n Вызываем value: "<<endl;
    x1= increment_by_value(n);
    cout<<"N = "<<n<<"  --> "<<x1<<endl;

     // вызываем по ссылке
    cout<<"\n Вызываем reference: "<<endl;
    x2= increment_by_refernce(&n);
    cout<<"N = "<<n<<"  --> "<<x2<<endl;
}

int increment_by_value(int n)
{
    n=n+2;
    return n;
}

int increment_by_refernce(int *n)
{
    *n=*n+2;
    return *n;
}