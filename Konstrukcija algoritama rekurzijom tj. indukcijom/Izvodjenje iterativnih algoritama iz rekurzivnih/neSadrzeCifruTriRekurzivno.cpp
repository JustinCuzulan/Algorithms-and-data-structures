#include <iostream>

using namespace std;
int brojeviBezCifre3(int n, int d)
{
    if (n == 0)
        return 1;
    int c = n % 10;
    if (c < 3)
        return c * brojeviBezCifre3(d / 10, d / 10) + brojeviBezCifre3(n / 10, d / 10);
    else if (c == 3)
        return c * brojeviBezCifre3(d / 10, d / 10);
    else

        return (c - 1) * brojeviBezCifre3(d / 10, d / 10) + brojeviBezCifre3(n / 10, d / 10);
}
int brojeviBezCifre33(int n)
{
    int nObratno = 0;
    int devetke = 0;
    do
    {
        nObratno = nObratno * 10 + n % 10;
        devetke = devetke * 10 + 9;
        n /= 10;
    } while (n > 0);

    return brojeviBezCifre3(nObratno, devetke);
}

int main()
{
    int n;
    cin >> n;
    cout << brojeviBezCifre33(n) << endl;
    return 0;
}