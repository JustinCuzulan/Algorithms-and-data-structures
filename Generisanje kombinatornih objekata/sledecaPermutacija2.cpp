#include <iostream>
#include <vector>

using namespace std;
void sledecaPermutacija(int n, vector<int> permutacija) {
  int i = n - 2;
  while (i >= 0 && permutacija[i] >= permutacija[i + 1]) i--;
  if (i == -1)
    cout << "ne postoji" << endl;
  else {
    int j = n - 1;
    while (j > 1 && permutacija[j] <= permutacija[i]) j--;
    swap(permutacija[i], permutacija[j]);
    int left = i + 1;
    int right = n - 1;
    while (left < right) {
      swap(permutacija[left], permutacija[right]);
      left++;
      right--;
    }
    for (int k = 0; k < n; ++k) {
      std::cout << permutacija[k] << std::endl;
    }
  }
}
int main() {
  int n;
  cin >> n;
  vector<int> permutacija(n);
  for (int i = 0; i < n; i++) cin >> permutacija[i];
  sledecaPermutacija(n, permutacija);
  return 0;
}