#include <iostream>
#include <vector>

using namespace std;
bool Morzeov(int n)
{
    vector<bool> arr(n + 1);
    arr[1] = true;
    int k = 1;

    for (int i = 0; i <= n; i++)
    {
        arr[i] = !arr[i - k];
        if (i == 2 * k)
            k *= 2;
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