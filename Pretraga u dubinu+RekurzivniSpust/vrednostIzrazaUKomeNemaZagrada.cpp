#include <iostream>
#include <string>
using namespace std;

// MOJA IMPLEMENTACIJA KOJA NEKAKO ISTPADA TACNA ALI PETLJA JE NE PREPOZNAJE KAO
// TAKVU

// int vrednost(const string& izraz, int& i) {
//   if (isdigit(izraz[i]))
//     return izraz[i++] - '0';
//   else {
//     i++;
//     int op1 = vrednost(izraz, i);
//     char op = izraz[i++];
//     int op2 = vrednost(izraz, i);
//     i++;
//     if (op == '+') return op1 + op2;
//     if (op == '-') return op1 - op2;
//     if (op == '*') return op1 * op2;
//     return 0;
//   }}
//   int vrednost(string izraz) {
//     int i = 0;
//     return vrednost(izraz, i);
//   }

// int main() {
//   string izraz;
//   cin >> izraz;
//   cout << vrednost(izraz) << endl;
//   return 0;
// }
int vrednost(const string& s) {
  int rezultat = 0;
  char op = '+';
  int tekuciBroj = 0;
  int poslednjiSabirak = 0;

  for (int i = 0; i <= s.length(); i++)
    if (i < s.length() && isdigit(s[i]))
      // procitali smo cifru
      // dodajemo je kao poslednju cifru tekuceg broja
      tekuciBroj = 10 * tekuciBroj + s[i] - '0';
    else {
      switch (op) {
        case '+':
          // rezultat uvecavamo za tekuci broj (nadajuci se da iza njega
          // ne ide *)
          rezultat += tekuciBroj;
          poslednjiSabirak = tekuciBroj;
          break;
        case '-':
          // rezultat umanjujemo za tekuci broj (nadajuci se da iza
          // njega ne ide *)
          rezultat -= tekuciBroj;
          poslednjiSabirak = -tekuciBroj;
          break;
        case '*':
          // rezultat je u prethodnom koraku greskom uvecan za poslednji sabirak
          rezultat -= poslednjiSabirak;
          // poslednji sabirak treba da ukljuci i tekuci broj kao faktor
          poslednjiSabirak = poslednjiSabirak * tekuciBroj;
          // uvecavamo rezultat za azuirarani poslednji sabirak,
          // nadajuci se da se iza njega nece vise javljati znak *
          rezultat += poslednjiSabirak;
          break;
      }
      // zavrsili smo sa obradom tekuceg broja i priremamo se za
      // citanje narednog
      tekuciBroj = 0;
      if (i < s.length())
        // pamtimo operator pre citanja narednog broja, jer nam on
        // govori kako naredni broj koji budemo procitali treba
        // ukljuciti u rezultat
        op = s[i];
    }
  return rezultat;
}

int main() {
  string s;
  getline(cin, s);
  cout << vrednost(s) << endl;
  return 0;
}