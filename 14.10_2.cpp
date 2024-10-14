#include <cmath>
#include <iostream>
#include <cstdlib> 
using namespace std;

void input_num_element(int *n);
int *allocate_memory(int n);
void input_vector(int n, int *x);

int main()
{
    int n, *a,*b;

    input_num_element(&n);

    a=allocate_memory(n);
    b=allocate_memory(n);

    cout <<"\n Введите элемент для вектора: "<<endl;
    cout <<"\nA "<<endl;
    input_vector(n,a);
    cout <<"\nB "<<endl;
    input_vector(n,b);

}

void input_num_element(int *n)
{
    do
    {
        cout<<"\n Номер элемента: ";
        cin>>*n;
    }
    while(*n<=0);
}

int *allocate_memory(int n)
{
    return(int *) malloc(n * sizeof(int));
}

void input_vector(int n, int *x)
{
    for(int i=0; i<n; i++)
    {
        cout<<"X["<<i<<"}:";
        cin>>x[i];
    }
}
