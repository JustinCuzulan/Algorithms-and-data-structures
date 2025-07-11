#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

typedef long long ll;
const string digits = "0123456789";
vector<pair<string, int>> podeli(const string &s)
{
    vector<pair<string, int>> rez;
    size_t pp = 0, p = s.find_first_of(digits);
    while (p != string::npos)
    {
        rez.emplace_back(s.substr(pp, p - pp), s[p] - '0');
        pp = p + 1;
        p = s.find_first_of(digits, p + 1);
    }
    if (pp < s.length())
        rez.emplace_back(s.substr(pp), 1);
    return rez;
}
char kToSlovo(const string &s, ll k)
{
    auto delovi = podeli(s);
    vector<ll> duzine(delovi.size());
    duzine[0] = delovi[0].first.length();
    for (int i = 1; i < delovi.size(); i++)
        duzine[i] = duzine[i - 1] * delovi[i - 1].second + delovi[i].first.length();
    for (int i = delovi.size() - 1; i >= 0; i--)
    {
        if (k >= duzine[i] * delovi[i].second)
            return delovi[i + 1].first[k - duzine[i] * delovi[i].second];
        k %= duzine[i];
    }
    return delovi[0].first[k];
}
int main()
{
    string s;
  cin >> s;
  ll k;
  cin >> k;
  cout << kToSlovo(s, k) << endl;
  return 0;
}