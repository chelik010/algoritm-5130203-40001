#include <iostream>

using namespace std;

const int n=100;

int main()
{
    char word[n], *begin, *end;
    
    cout<<"Введите слово"<<endl;
    cin>>word;

    begin = word;
    end = word;

    while(*end)
    {
        end++;

    }
end--;

while(begin<end)
{
    if(*begin  != *end)
    {
        cout<<"\n This word is not palindroma"<<endl;
        return 0;
    }
    begin++;
    end--;
}
cout<<"\n This word is palindroma"<<endl;
return 0;
}