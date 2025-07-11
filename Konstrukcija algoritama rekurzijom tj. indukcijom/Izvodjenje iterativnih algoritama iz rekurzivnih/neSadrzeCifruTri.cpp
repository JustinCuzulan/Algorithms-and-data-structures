#include <iostream>

using namespace std;
int brojeviBezCifre3(int n)
{
    int t=1,br=1;
    while(n>0){
        int c=n%10;
        if(c<3)
        br=c*t+br;
        else if(c==3)
        br=c*t;
        else
        br=(c-1)*t+br;
        t=9*t;
        n/=10;
    }
    return br;
}
int main()
{
    int n;
    cin >> n;
    cout << brojeviBezCifre3(n) << endl;
    return 0;
}