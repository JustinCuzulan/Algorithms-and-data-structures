#include <iostream>
#include <vector>
using namespace std;

struct cvor {
  int vrednost;
  cvor *levo, *desno;
};
 cvor* napravi_cvor(int x, cvor* levo = nullptr, cvor* desno = nullptr) {
  cvor* novi = new cvor;
  novi->vrednost = x;
  novi->levo = levo;
  novi->desno = desno;
  return novi;
}
void obrisi(cvor* koren) {
  if (koren != nullptr) {
    obrisi(koren->levo);
    obrisi(koren->desno);
    delete koren;
  }
}
cvor* ucitaj() {
  char c;
  cin >> c;
  if (c == '-')
    return nullptr;
  else {
    // ucitali smo [
    int vrednost;
    cin >> vrednost >> ws;
    cvor* levo = ucitaj();
    cin >> ws;
    cvor* desno = ucitaj();
    cin >> ws;
    // ucitavamo ]
    cin >> c;
    return napravi_cvor(vrednost, levo, desno);
  }
}
int visina(cvor* koren) {
  // visina praznog stabla je nula
  if (koren == nullptr) return 0;
  // visina untrašnjeg čvora
  return max(visina(koren->levo), visina(koren->desno)) + 1;
}
int maxFaktorRavnoteze(cvor* koren) {
  if (koren == nullptr)
    return 0;
  
  int maxFaktorLevo = maxFaktorRavnoteze(koren->levo);
  int maxFaktorDesno = maxFaktorRavnoteze(koren->desno);
  int faktorKoren = abs(visina(koren->levo) - visina(koren->desno));

  return max({maxFaktorLevo, maxFaktorDesno, faktorKoren});
}

int main() {
  ios_base::sync_with_stdio(false);
  cvor* koren = ucitaj();
  cout << maxFaktorRavnoteze(koren) << endl;
  obrisi(koren);
  return 0;
}
