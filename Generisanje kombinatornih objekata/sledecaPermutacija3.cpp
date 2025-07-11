#include <iostream>
#include <vector>

using namespace std;
void ispis(int n, vector<char>& permutacija) {
  int i = 0;
  for (i = 0; i < n; i++) {
    cout << permutacija[i];
  }
}
void pronadjiPermutaciju(int n, vector<char>& permutacija) {
  int suma = 0;
  for (int j = 0; j < n; j += 2) suma += (permutacija[j] - '0');
  if (suma < 1000) {
    int i = n - 1;
    while (i >= 0 && ((permutacija[i] - '0') - 1) == 0) {
      i -= 2;
    }
    if (i <= 0)
      cout << "ne" << endl;
    else {
      permutacija[i] = ((permutacija[i] - '0') - 1) + '0';
      permutacija[i - 2] = ((permutacija[i - 2] - '0') + 1) + '0';
      ispis(n, permutacija);
    }
  } else {
    cout << "ne" << endl;
  }
}
int main() {
  char c;
  vector<char> permutacija;
  while (cin >> c) {
    permutacija.push_back(c);
  }
  int n = permutacija.size();
  pronadjiPermutaciju(n, permutacija);
  return 0;
}