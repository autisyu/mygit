#include<iostream>
using namespace std;
const int num = 1000000;
bool vi[num] = {0};
int prime[num];
	    
int cnt = 0;
void fun(int n)
{
    for (int i = 2; i <=n; ++i) {
        if (!vi[i]) {
            prime[cnt++] = i;
	    for (int j = i * i; j <= n; j+=i) {
	        vi[j] = 1;
	    }
	}
    }
    for (int i = 0; i < cnt; ++i) {
        cout<<prime[i]<<" ";
    }
}
int main()
{
    int n;
    cin>>n;
    fun(n);
    return 0;
}
