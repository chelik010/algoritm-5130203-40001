#include <iostream>
using namespace std;

int main()
{
    int v, *p;
    v = 100;

    p = &v;
    cout << "\nVariable --> adress: "<<&v<<" have value = "<<v;
    cout << "\nPointer --> adress: "<<p<<" have value = "<<*p;

    return 0;

}