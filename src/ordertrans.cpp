#include<iostream>
#include<stack>
using namespace std;
stack<int> S;
void ordertran(int n, int order)
{
    while (n) {
        S.push(n%order);
        //cout<<n%order;
	n/=order;
    }
    while (!S.empty()) {
        int t = S.top();
	S.pop();
	cout<<t;
    }
}
int main()
{
    int n, order;
    cin>>n>>order;
    ordertran(n,order);
    return 0;
}
