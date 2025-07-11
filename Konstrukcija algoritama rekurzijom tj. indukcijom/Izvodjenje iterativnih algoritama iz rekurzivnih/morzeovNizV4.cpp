#include <iostream>
using namespace std;
int MaxStepen2(int n){
    int max=1;
    while(max*2<n)
    max*=2;
    return max;
}
bool Morzeov(int n){
bool x=true;
while(n>1){
    n-=MaxStepen2(n);
    x=!x;
}
return x;
}
int main(){
    int n;
    cin>>n;
    cout<<(Morzeov(n)?"1":"0")<<endl;
    return 0;
}