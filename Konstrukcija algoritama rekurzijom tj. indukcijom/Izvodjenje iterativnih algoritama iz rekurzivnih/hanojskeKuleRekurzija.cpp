#include <iostream>

using namespace std;
typedef int stap;

void Hanoj(int n, stap sa, stap pom, stap na)
{
    if (n > 0)
    {
        Hanoj(n - 1, sa, na, pom);
        cout << sa << " " << na << endl;
        Hanoj(n - 1, pom, sa, na);
    }
}
void HanojRek(int n)
{
    Hanoj(n, 1, 2, 3);
}
int main()
{
    int n;
    cin>>n;
    HanojRek(n);
    return 0;
}