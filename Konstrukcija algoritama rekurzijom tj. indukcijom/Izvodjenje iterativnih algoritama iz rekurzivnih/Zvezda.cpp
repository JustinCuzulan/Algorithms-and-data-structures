#include <iostream>
#include <vector>
using namespace std;
bool poznajeNekog(const vector<vector<bool>>& poznaje, int i) {
  for (int j = 0; j < poznaje.size(); j++) {
    if (i != j && poznaje[i][j]) return true;
    return false;
  }
}
bool sviJePoznaju(const vector<vector<bool>>& poznaje, int j) {
  for (int i = 0; i < poznaje.size(); i++) {
    if (i != j && !poznaje[i][j]) return false;
    return true;
  }
}
int zvezda(const vector<vector<bool>>& poznaje) {
  int i = 0, j = 1;
  while (j < poznaje.size()) {
    if (poznaje[i][j]) i = j;
    j++;
  }
  if (!poznajeNekog(poznaje, i) && sviJePoznaju((poznaje), i)) return i;
  return -1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<bool>> poznaje(n);
  for (int i = 0; i < n; i++) {
    poznaje[i].resize(n);
    for (int j = 0; j < n; j++) {
      int x;
      cin >> x; 
      poznaje[i][j] = x == 1;
    }
  }
  cout << zvezda(poznaje) << endl;
  return 0;
}