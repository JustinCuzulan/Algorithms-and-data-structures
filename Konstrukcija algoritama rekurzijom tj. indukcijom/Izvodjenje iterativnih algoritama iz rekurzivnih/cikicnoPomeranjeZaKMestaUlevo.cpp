#include <iostream>
#include <vector>
using namespace std;
int nzd(int a, int b) {
  while (b != 0) {
    int r = a % b;
    a = b;
    b = r;
  }
  return a;
}
void RotirajUlevo(vector<int>& a, int k) {
  int n = a.size();
  k = k % n;

  int d = nzd(n, k);
  for (int i = 0; i < d; i++) {
    int pom = a[i];
    int j;
    for (j = i; (j + k) % n != i; j = (j + k) % n) a[j] = a[(j + k) % n];
    a[j] = pom;
  }
}
int main() {
  // ubrzavamo ucitavanje i ispis
  ios_base::sync_with_stdio(false);

  // ucitavamo podatke
  int n, k;
  cin >> k >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  // rotiramo niz
  RotirajUlevo(a, k);

  // ispisujemo rotirani niz
  for (int i = 0; i < n; i++) cout << a[i] << " ";
  cout << endl;
}