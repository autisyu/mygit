#include<iostream>
using namespace std;
int countNumOne(int n)
{
    int cnt = 0;
    while (n) {
        n = n & (n - 1);
	cnt++;
    }
    return cnt;
}
int main()
{
    int n;
    cin>>n;
    cout<<countNumOne(n)<<endl;;
    return 0;
}
