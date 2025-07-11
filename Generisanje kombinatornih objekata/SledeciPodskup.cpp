#include <iostream>
#include <vector>

using namespace std;
void sledecaVarijacija(int n, vector<int>& varijacija) {
  int velicinaNiza = n;
  int i;
  for (i = velicinaNiza - 1; i >= 0 && varijacija[i] == n; i--) {
    if (i < 0) cout << "-";
  }
  varijacija[i]++;
  for (int j = 1; j < velicinaNiza; j++) cout << j << " ";
  cout << endl;
}
int main() {
  int n;
  cin >> n;
  vector<int> varijacija(n);
  for (int i = 0; i < n; i++) cin >> varijacija[i];
  sledecaVarijacija(n, varijacija);
  return 0;
}