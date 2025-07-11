#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<int> saberi(const vector<int> &a, const vector<int> &b)
{
    vector<int> rez;
    int p = 0;
    for (size_t i = 0; i < a.size() || i < b.size(); i++)
    {
        int c = (i < a.size() ? a[i] : 0) + (i < b.size() ? b[i] : 0) + p;
        rez.push_back(c % 10);
        p = c / 10;
    }
    if (p > 0)
        rez.push_back(p);
    return rez;
}
vector<int> mnoziBrojem(const vector<int> &a, int b)
{
    vector<int> rez;
    int p = 0;
    for (size_t i = 0; i < a.size(); i++)
    {
        int c = a[i] * b + p;
        rez.push_back(c % 10);
        p = c / 10;
    }
    if (p > 0)
        rez.push_back(p);
    return rez;
}
vector<int> ucitajBroj(const string &broj)
{
    vector<int> rez(broj.size());
    for (int i = broj.size() - 1; i >= 0; i--)
        rez.push_back(broj[i] - '0');
    return rez;
}
string ispisiBroj(const vector<int>& broj)
{
    string s;
    for (int i = broj.size() - 1; i >= 0; i--)
        s.push_back('0' + broj[i]);
    return s;
}
int main()
{
    string broj;
    cin >> broj;
    vector<int> zbir;
    zbir.push_back(0);
    vector<int> b;
    b.push_back(1);
    for (char c : broj)
    {
        zbir = saberi(zbir, saberi(mnoziBrojem(zbir, 10), mnoziBrojem(b, c - '0')));
        b = mnoziBrojem(b, 2);
    }
    cout << ispisiBroj(zbir) << endl;
    return 0;
}
