#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int apsolutniPobednik(const vector<int>& glasovi) {
  int broj = 0;
  int kandidat;
  for (int glas : glasovi) {
    if (broj == 0) {
      kandidat = glas;
      broj = 1;
    } else if (glas == kandidat)
      broj++;
    else
      broj--;
  }
  if (broj > 0 &&
      count(begin(glasovi), end(glasovi), kandidat) > glasovi.size() / 2)
    return kandidat;
  else
    return -1;
}
int main() {
  ios_base::sync_with_stdio(false);
  // ucitavamo glasove
  int n;
  cin >> n;
  vector<int> glasovi(n);
  for (int i = 0; i < n; i++) cin >> glasovi[i];

  int pobednik = apsolutniPobednik(glasovi);
  if (pobednik >= 0)
    cout << pobednik << endl;
  else
    cout << "nema" << endl;

  return 0;
}