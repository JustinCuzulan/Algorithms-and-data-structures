#include <iostream>
#include <vector>
using namespace std;
void ispisiNiz(vector<int> varijacija) {
  int velicinaNiza = varijacija.size();
  for (int i = 0; i < velicinaNiza; i++) cout << varijacija[i];
}
void sledeciBinarniNiz(vector<int>& varijacija) {
  int velicinaNiza = varijacija.size();
  int i;
  for (i = velicinaNiza; i > 0; i--) {
    if (varijacija[i] == 0) {
      if (varijacija[i + 1] == 0) {
        varijacija[i] = 1;
        break;
      }
    }
    if (i == 0 && varijacija[i] == 1) {
      cout << "ne postoji" << endl;
    }
  }
  for (int j = velicinaNiza; j > i; j--) {
    varijacija[j] = 0;
  }
  
}
int main() {
  int n;
  cin >> n;
  vector<int> varijacija(n);
  int velicina = varijacija.size();
  for (int i = 0; i < velicina; i++) cin >> varijacija[i];
  sledeciBinarniNiz(varijacija);
  ispisiNiz(varijacija);
  return 0;
}