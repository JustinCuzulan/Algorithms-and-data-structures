#include <iostream>
#include <string>
using namespace std;

typedef long long ll;
const string digits = "0123456789";

ll duzina(const string &s)
{
    size_t p = s.find_first_of(digits);
    if (p == string::npos)
        return s.length();
    else
        return duzina(s.substr(0, p)) * (s[p] - '0') + (s.length() - p - 1);
}

char kToSlovo(const string &s, ll k)
{
    size_t p = s.find_last_of(digits);
    if (p == string::npos)
        return s[k];
    ll d = duzina(s.substr(0, p));
    int m = s[p] - '0';
    if (k >= m * d)
        return s.substr(p + 1)[k - m * d];
    else
        return kToSlovo(s.substr(0, p), k % d);
}
int main()
{
    string s;
    cin >> s;
    int n;
    cin >> n;
    cout << kToSlovo(s, n) << endl;
    return 0;
}