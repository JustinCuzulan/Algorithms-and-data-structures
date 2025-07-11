#include <iostream>
#include <vector>
using namespace std;
void obradi(const vector<int>& varijacija) {
  for (int x : varijacija) cout << x << " ";
  cout << endl;
}
bool sledecaVarijacija(int n, vector<int>& varijacija) {
  int i;
  int k = varijacija.size();
  for (i = k - 1; i >= 0 && varijacija[i] == n; i--) varijacija[i] = 1;
  if (i < 0) return false;
  varijacija[i]++;
  return true;
}
void obradiSveVarijacije(int k, int n) {
  vector<int> varijacija(k, 1);
  do {
    obradi(varijacija);

  } while (sledecaVarijacija(n, varijacija));
}

int main() {int n, k;
  cin >> n >> k;
  obradiSveVarijacije(k, n);
  return 0;}