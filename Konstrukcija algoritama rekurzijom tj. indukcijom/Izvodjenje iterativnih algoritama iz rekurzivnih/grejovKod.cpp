#include <iostream>

using namespace std;

string grej(unsigned n, unsigned k)
{
    if (n == 0)
        return "";
    if (k < (1u << (n - 1)))
        return "0" + grej(n - 1, k);
    else
    return "1" + grej(n - 1, (1ull << n) - 1 - k);
}
int main()
{
    unsigned n;
    cin >> n;
    unsigned k;
    cin >> k;
    cout << grej(n, k) << endl;
    return n;
}