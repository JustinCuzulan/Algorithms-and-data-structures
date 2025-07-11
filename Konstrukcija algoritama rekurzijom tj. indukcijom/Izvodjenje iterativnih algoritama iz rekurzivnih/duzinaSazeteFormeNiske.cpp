#include <iostream>
#include <string>

using namespace std;
long long duzina(string &s)
{
    long long suma=0;
    for (char c:s)
    {
        if (isdigit(c))
            suma =suma* (c - '0');
        else
            suma += 1;
    }
    return suma;
}
int main()
{
    string s;
    cin >> s;
    cout << duzina(s) << endl;
    return 0;
}