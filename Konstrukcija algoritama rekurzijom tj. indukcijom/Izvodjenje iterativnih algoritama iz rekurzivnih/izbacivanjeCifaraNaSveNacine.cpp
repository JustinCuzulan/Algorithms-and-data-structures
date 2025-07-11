#include <iostream>
#include <string>
using namespace std;
int Zbir(const string& broj)
{
    int zbir=0,b=1;
    for(char c:broj){
        zbir+=10*zbir+b*(c-'0');
        b*=2;
    }return zbir;
}
int main()
{
    string broj;
    cin>>broj;
    cout<<Zbir(broj)<<endl;
    return 0;
}