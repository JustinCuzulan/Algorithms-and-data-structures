#include <iostream>
#include <vector>

using namespace std;
bool Morzeov(int n)
{
    vector<bool> arr(n + 1);
    arr[1]=true;
    int upisano = 1;
    int duzina = 1;
    while (upisano < n)
    {
        for (int i = 1; i < duzina && upisano < n; i++)
        {
            arr[duzina + 1] = !arr[i];
            upisano++;
        }
        duzina *= 2;  
    }
    return arr[n];
}
int main()
{
    int n;
    cin >> n;
    cout << (Morzeov(n) ? "1" : "0") << endl;
    return 0;
}