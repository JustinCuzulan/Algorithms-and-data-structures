#include <cctype>
#include <iostream>
#include <stack>

using namespace std;

int main() {
  string izraz;
  cin >> izraz;

  stack<int> vrednosti;
  stack<char> operatori;
  for (char c : izraz)
    if (isdigit(c)) {
      vrednosti.push(c - '0');
    } else if (c == ')') {
      char op = operatori.top();
      operatori.pop();
      int op2 = vrednosti.top();
      vrednosti.pop();
      int op1 = vrednosti.top();
      vrednosti.pop();
      if (op == '+')
        vrednosti.push(op1 + op2);
      else if (op == '*')
        vrednosti.push(op1 * op2);
    } else if (c == '+' || c == '*') {
      operatori.push(c);
    }
  cout << vrednosti.top() << endl;
  return 0;
}