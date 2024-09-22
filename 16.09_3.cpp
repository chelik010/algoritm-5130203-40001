#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int randomNumb = rand() % 200 + 1;
    int num_user;
    char play;
    do
    {
        cout <<  "Введите предполагаемое число: "<< endl;
        cin >> num_user;
        while(randomNumb != num_user)
        {
            if(randomNumb < num_user){
                cout << "Попробуйте еще раз, меньше"<<endl;
            }
            else{
                cout << "Попробуйте еще раз, больше"<<endl;
                }
        }
    } while (play == 'y' || play == 'Y');
    
}
