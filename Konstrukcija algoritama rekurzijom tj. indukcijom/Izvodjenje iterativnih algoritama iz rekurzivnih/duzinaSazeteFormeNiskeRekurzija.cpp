#include <iostream>
#include <string>
using namespace std;

long long duzinaSazeteFormeNiske(const string &s, int n)
{
    if (n == 0)
        return 0;
    if (!isdigit(s[n - 1]))
        return duzinaSazeteFormeNiske(s, n - 1) + 1;
    else
        return duzinaSazeteFormeNiske(s, n - 1) * (s[n - 1] - '0');
}

long long duzina(const string &s)
{
    return duzinaSazeteFormeNiske(s, s.length());
}
int main()
{
    string n;
    cin >> n;
    cout << duzina(n) << endl;
    return 0;
}