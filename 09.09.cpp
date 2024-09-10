#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long double m,c,v,e;
    m=9.1 * pow(10, -31);
    c=2.998 * pow(10, 8);
    v=10;
    e=(m*pow(c,2))/(sqrt(1-pow((v/c), 2)))-m*pow(c, 2);
    cout << e << endl;
}
    // float x,y,z;
    // x=25.1;
    // cout <<"Hello world"<< endl;
    // y=sqrt(x);
    // z=pow(x,2);
    // cout << "Square = "<< y << endl;
    // cout << "Power in 2"<< z << endl; 
    // return 0;