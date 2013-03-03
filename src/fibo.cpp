#include<iostream>
#include<cmath>
#include<stdlib.h>
using namespace std;
const long long mod = 1000000007;
long long fibo(int n)
{
    if (n == 1) return 1;
    if (n == 2) return 1;
    return (fibo(n - 1)%mod + fibo(n - 2)%mod)%mod;
}
long Fibo(int n) {
    if (n == 1 || n==2 ) return 1;
    n-=2;
    int f1 = 1, f2 = 1;
    long long res = 0;
    while (n -- ) {
        res = (f1%mod + f2%mod)%mod;
	f1 = f2;
	f2 = res;
    }
    return res;
}
int main()
{
    int n;
    cin>>n;
    //cout<<fibo(n)<<endl;
    cout<<Fibo(n)<<endl;
    return 0;
}
