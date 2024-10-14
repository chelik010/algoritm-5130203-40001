#include <iostream>
using namespace std;

int increment_by_value(int n);
int increment_by_refernce(int *n);
void increment_by_process(int n, int *res);

int main()
{
    int n, x1,x2,res;
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

    // execute like process
    cout<<"\n execute process: "<<endl;
    increment_by_process(n,&res);
    cout<<"N = "<<n<<"  --> "<<res<<endl;
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

void increment_by_process(int n, int *res)
{
    *res= n+2;
}