#include <iostream>
using namespace std;
int MaxStepen2(int n)
{
    int max = 1;
    while (max * 2 < n)
        max *= 2;
    return max;
}
bool Morzeov(int n)
{
    if (n == 1)
        return true;
    return !Morzeov(n - MaxStepen2(n));
}
int main()
{
    int n;
    cin >> n;
    cout << (Morzeov(n) ? "1" : "0") << endl;
    return 0;
}