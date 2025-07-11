#include <iostream>

using namespace std;
unsigned long long zbirNajvecihNeparnihDjelilaca(unsigned long long n)
{
    unsigned long long z=0;
    while(n>0){
unsigned long long k=(n+1)/2;
z+=k*k;
n/=2;
    }
    return z;
}
int main()
{
    unsigned long long n;
    cin >> n;
    cout << zbirNajvecihNeparnihDjelilaca(n) << endl;
    return 0;
}