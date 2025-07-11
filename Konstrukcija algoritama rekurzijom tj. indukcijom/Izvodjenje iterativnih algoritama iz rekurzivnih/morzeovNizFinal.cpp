#include <iostream>

using namespace std;
bool Morzeov(int n)
{
    n--;
    int x = 1;
    while (n)
    {
        n = n & (n - 1);
        x = !x;
    }
    return x;
}
int main()
{
    int n;
    cin >> n;
    cout << (Morzeov(n) ? "1" : "0") << endl;
    return 0;
}