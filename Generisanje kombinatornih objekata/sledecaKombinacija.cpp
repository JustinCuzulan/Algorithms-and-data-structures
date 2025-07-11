#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  int k;
  vector<int> kombinacija;
  int element;
  while (cin >> element) {
    kombinacija.push_back(element);
  }
  k = kombinacija.size();

  int i = k - 1;
  while (i >= 0 && kombinacija[i] == n - k + 1 + i) {
    i--;
  }

  if (i < 0) {
    cout << "-" << endl;
  } else {
    kombinacija[i]++;
    for (int j = i + 1; j < k; ++j) {
      kombinacija[j] = kombinacija[j - 1] + 1;
    }
    for (int j = 0; j < k; ++j) {
      cout << kombinacija[j] << (j == k - 1 ? "" : " ");
    }
    cout << endl;
  }

  return 0;
}