#include <iostream>
#include <vector>
#include <string>
using namespace std;
int Zbir(int n, int sum, int b)
{
    if (n == 0)
    {
        sum = 0;
        b = 1;
    }
    else
    {
        int sumR, bR;
        Zbir(n / 10, sumR, bR);
        sum = sumR + sumR * 10 + bR * (n % 10);
        b = bR * 2;
    }
}
int Zbir(int n)
{
    int zbir, b;
    Zbir(n, zbir, b);
    return zbir;
}
int main()
{
    int n;
    cin >> n;
    cout << Zbir(n) << endl;
    return 0;
}