#include <iostream>
#include<string>

using namespace std;

int term(string, size_t&, bool&);
int faktor(string, size_t&, bool&);
int broj(string, size_t&);

int izraz(string s, size_t &i, bool &ok) {
  int a = term(s, i, ok);
  while (ok && i < s.length() && (s[i] == '+' || s[i] == '-')) {
    if (s[i] == '+') {
      i++;
      a += term(s, i, ok);
    } else if (s[i] == '-') {
      i++;
      a -= term(s,i,ok);
    }
  }
  return a;
}

int term(string s, size_t &i, bool &ok) {
  int a = faktor(s,i,ok);
  while (ok && i < s.length() && (s[i] == '*' || s[i] == '/')) {
    i++;
    if (s[i - 1] == '*')
      a *= faktor(s,i,ok);
    else {
      int b = faktor(s,i,ok);
      if (b == 0)
        ok = false;
      else
        a /= b;
    }
  }
  return a;
}

int faktor(string s, size_t&i, bool &ok) {
  if (isdigit(s[i]))
    return broj(s, i);
  else {
    i++;
    int a = izraz(s, i, ok);
    i++;
    return a;
  }
}

int broj(string s, size_t &i) {
  int x = 0;
  while (i < s.length() && isdigit(s[i])) {
    x = x*10 + s[i]-'0';
    i++;
  }
  return x;
}

int main() {
  string s;
  size_t i;
  int rez;
  bool ok;
  while (cin >> s) {
    i = 0;
    ok = true;
    rez = izraz(s, i, ok);
    if (ok)
      cout << rez << endl;
    else
      cout << "deljenje nulom" << endl;
  }
  return 0;
}