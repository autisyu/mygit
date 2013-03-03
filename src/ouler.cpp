#include<iostream>
#include<cmath>
using namespace std;
int ouler(int n)
{
    int ans = n;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
	    ans = ans * (i - 1)/ i;
	}
	while (n % i== 0) n /= i;
    }
    if (n > 1) {
        ans = ans * (n - 1) / n;
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    cout<<ouler(n)<<endl;
    return 0;
}
