#include<iostream>
#include"include/myMath.h"
using namespace std;
const int capacity = 100001;
const int INF = 0X7ffffff;
const int cnt = 5;
int d[capacity];
int v[cnt] = {2, 5, 10, 20, 50};
void init()
{
    for (int i = 0; i <= capacity; ++i) {
        d[i] = INF;
    }
    d[0] = 0;
}

int changeCoin(int s)
{
//    cout<<s<<" "<<endl;
    if (s == 0) return 0;
    int& a = d[s];
    if (a != INF) return a;
    for (int i = 0; i < cnt; ++i) {
        if (s >= v[i]) {
	    d[s] = Min(d[s], 1 + changeCoin(s - v[i]));
	}
    }
  //  cout<<s<<" "<<d[s]<<endl;
    return d[s];
}
void print_ans(int ans, int coin) 
{
    if (coin == 0) return;
    for (int i = 0; i < cnt; ++i) {
        if (ans >= v[i] && coin == 1 + d[ans - v[i]]) {
	    cout<<v[i]<<" ";
	    print_ans(ans - v[i], coin - 1);
	    break;
	}
    }
}
int main()
{
    init();
    int coin,ans;
    cin>>coin;
    cout<<(ans = changeCoin(coin))<<endl;
    print_ans(coin, ans);
    return 0;
}
