#include <iostream>

using namespace std;
unsigned long long zbirNajvecihNeparnihDjelilaca(unsigned long long n)
{
    if (n == 0)
        return 0;
    else
    {
        unsigned long long k = (n + 1) / 2;
        return k * k + zbirNajvecihNeparnihDjelilaca(n / 2);
    }
}
int main()
{
    unsigned long long n;
    cin >> n;
    cout << zbirNajvecihNeparnihDjelilaca(n) << endl;
    return 0;
}