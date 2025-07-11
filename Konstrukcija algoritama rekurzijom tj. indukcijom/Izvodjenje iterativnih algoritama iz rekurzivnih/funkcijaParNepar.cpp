#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

uint64_t funkcijaParNeparRek(uint64_t n)
{
    if (n == 1)
        return 1;

    if (n % 2 == 0)
        return funkcijaParNeparRek(n / 2);
    else
        return funkcijaParNeparRek(((n - 1) / 2)) + funkcijaParNeparRek(n + 1);
}
uint64_t funkcijaParNeparIter(uint64_t n)
{
    vector<uint64_t> arr(n + 1);
    arr[0] = 999999910;
    arr[1] = 1;
    uint64_t limit = n % 2 == 0? n/2 : n/2+1;
    for (uint64_t i = 2; i <= limit; i++)
    {
        if (i % 2 == 0)
        {
            arr[i] = arr[i / 2];
        }
        else
        {
            arr[i] = arr[(i - 1) / 2] + arr[((i - 1) / 2) + 1];
        }
    }
    return n%2==0? arr[n/2] : arr[n/2]+arr[n/2+1];
}
int main()
{
    uint64_t n;
    cin >> n;
    // cout << funkcijaParNeparRek(n) << endl;
    cout << funkcijaParNeparIter(n) << endl;
    return 0;
}