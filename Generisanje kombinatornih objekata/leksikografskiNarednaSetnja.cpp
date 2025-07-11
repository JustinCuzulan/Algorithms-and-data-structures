#include <iostream>
#include <vector>
using namespace std;
int pronadjiVarijaciju(int n, vector<int> varijacija) {
  for (int i = n - 1; i >= 1; --i) {
    int original_value = varijacija[i];
    int next_value = original_value + 1;

    if (abs(next_value - varijacija[i - 1]) <= 1) {
      varijacija[i] = next_value;
      int current_value = next_value;
      for (int j = i + 1; j < n; ++j) {
        varijacija[j] = current_value - 1;
        current_value = varijacija[j];
      }

      bool is_valid = true;
      if (varijacija[0] != 0) {
        is_valid = false;
      } else {
        for (int k = 0; k < n - 1; ++k) {
          if (abs(varijacija[k + 1] - varijacija[k]) > 1) {
            is_valid = false;
            break;
          }
        }
      }

      if (is_valid) {
        for (int j = 0; j < n; ++j) {
          cout << varijacija[j] << (j == n - 1 ? "" : " ");
        }
        cout << endl;
        return 0;
      } else {
        varijacija[i] =
            original_value;  // Vrati na originalno stanje ako nije validno
      }
    }
  }
}
int main() {
  int n;
  cin >> n;
  vector<int> varijacija(n);
  for (int i = 0; i < n; i++) cin >> varijacija[i];
  pronadjiVarijaciju(n, varijacija);
  return 0;
}