#include <cctype>
#include <iostream>

using namespace std;

void prevedi(const string& izraz, int& i, string& postfiks) {
  if (isdigit(izraz[i]))
    postfiks += izraz[i++];
  else {
    i++;
    prevedi(izraz, i, postfiks);
    char op = izraz[i++];
    prevedi(izraz, i, postfiks);
    i++;
    postfiks += op;
  }
}
string prevedi(const string& izraz) {
  string postfiks = "";
  int i = 0;
  prevedi(izraz, i, postfiks);
  return postfiks;
}
int main() {
  string izraz;
  cin >> izraz;
  string postfiks = prevedi(izraz);
  cout << postfiks << endl;
  return 0;
}