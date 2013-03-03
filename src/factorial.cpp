#include<iostream>
using namespace std;
const int len = 10000;
int res[len];

void factorial(int n)
{
    int c = 2, k=0,carry = 0;
    bool flag = 0;
    res[0] = 1;
    while (c<=n) {
        k = 0;
	while (k < len) {
            res[k++] *= c;
	}
	k = 0;
	do {
	res[k] += carry;
	carry = res[k] / 10;
	res[k++] %= 10;
	} while (k<len);
	c++;
    }
    for (int i = len - 1; i >= 0; --i) {
        if (!res[i]&&!flag)  { continue; }
	if (!res[i]&&flag) { cout<<res[i]<<" "; } 
        if (res[i]) {
	    flag  = 1;
            cout<<res[i]<<" ";
	}
    }
}
int main()
{
    int num;
    cin>>num;
    factorial(num);
    return 0;
}
