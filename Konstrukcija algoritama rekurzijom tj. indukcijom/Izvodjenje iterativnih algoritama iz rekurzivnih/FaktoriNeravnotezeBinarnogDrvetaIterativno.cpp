#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;
struct cvor {
  int vrednost;
  cvor *levo, *desno;
};

cvor* napravi_cvor(int x, cvor* levo = nullptr, cvor* desno = nullptr) {
  cvor* novi = new cvor();
  novi->vrednost = x;
  novi->levo = levo;
  novi->desno = desno;
  return novi;
}

cvor* ucitaj() {
  char c;
  cin >> c;
  if (c == '-')
    return nullptr;
  else {
    // ucitali smo [
    int vrednost;
    cin >> vrednost >> ws;   // ucitavamo vrednost u korenu i preskacemo beline
    cvor* levo = ucitaj();   // rekurzivno ucitvamo levo poddrvo
    cin >> ws;               // preskacemo beline
    cvor* desno = ucitaj();  // rekurzivno ucitvamo desno poddrvo
    cin >> ws;               // preskacemo beline
    // ucitavamo ]
    cin >> c;
    // kreiramo koreni cvor i vracamo celo ucitano drvo
    return napravi_cvor(vrednost, levo, desno);
  }
}

void obrisi(cvor* koren) {
  if (koren != nullptr) {
    obrisi(koren->levo);
    obrisi(koren->desno);
    delete koren;
  }
}

// izracunava faktore ravnoteze svih cvorova
void visinaIMaxFaktorRavnoteze(cvor* koren, int& visina, int& maxFaktor) {
  if (koren == nullptr) {
    visina = 0;
    maxFaktor = 0;
    return;
  }

  int visinaLevo, maxFaktorLevo;
  visinaIMaxFaktorRavnoteze(koren->levo, visinaLevo, maxFaktorLevo);
  int visinaDesno, maxFaktorDesno;
  visinaIMaxFaktorRavnoteze(koren->desno, visinaDesno, maxFaktorDesno);

  int faktorKoren = abs(visinaLevo - visinaDesno);

  maxFaktor = max({maxFaktorLevo, maxFaktorDesno, faktorKoren});
  visina = max(visinaLevo, visinaDesno) + 1;
}
int maxFaktorRavnoteze(cvor* koren) {
    int visina,maxFaktor;
    visinaIMaxFaktorRavnoteze(koren,visina,maxFaktor);
    return maxFaktor;
}

int main() {
  ios_base::sync_with_stdio(false);
  cvor* koren = ucitaj();
  cout << maxFaktorRavnoteze(koren) << endl;
  obrisi(koren);
  return 0;
}