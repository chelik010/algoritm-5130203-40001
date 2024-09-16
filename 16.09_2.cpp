#include <iostream>
using namespace std;

int main()
{
    int i, div, n;
    for (i = 2; i <= 100; i++)
    {
        n = i;  
        div = 2;
        while (div < n) 
        {
            if (n % div == 0) break;  
            div++;
        }
        if (div == n) {
            cout << n << " ";
        }
    }

    return 0;
}
