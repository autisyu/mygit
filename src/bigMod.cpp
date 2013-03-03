#include<iostream>
#include<cstring>
using namespace std;
int BigOrd(int a, int mod, int order)
{
    if (order == 0) return 1;
    if (order % 2 == 0) {
        return ((BigOrd(a, mod, order/2) % mod) * (BigOrd(a, mod, order/2) % mod)) % mod;
    } else {
        return ((BigOrd(a, mod, order/2) % mod) * (BigOrd(a, mod, order/2) % mod) * a) % mod;
    }
}
int BigMod(char array[], int mod)
{
    int len = strlen(array);
    int order = 1, ans = 0;
    for (int i = 0; i < len; ++i) {
        ans = (ans * 10  + (array[i] - '0')) %  mod; 
    }
    return ans;
}
int main()
{
    char array[100];
    int a, order, mod;
    cin>>a>>order>>mod;
    cout<<BigOrd(a, mod, order)<<endl;
    //cin>>array>>mod;
    //cout<<BigMod(array,mod)<<endl;
    return 0;
}
