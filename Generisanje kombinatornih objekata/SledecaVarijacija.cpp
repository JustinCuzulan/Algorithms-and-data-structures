#include <iostream>
#include <vector>
using namespace std;
void ispisi(const vector<int>& varijacija) {
  for (int i : varijacija) cout << i << " ";
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
int main() {
  int k, n;
  cin >> k >> n;
  vector<int> varijacija(k);
  for (int i = 0; i < k; i++) cin >> varijacija[i];
  if (sledecaVarijacija(n, varijacija))
    ispisi(varijacija);
  else
    cout << "-" << endl;
  return 0;
}