#include<iostream>
#include<cmath>
using namespace std;
const int cnt = 9;
int Rmq[cnt][cnt];
int Max(int a, int b)
{
    return a>b?a:b;
}
int rmq(int array[], int n)
{
    int d = log(n)/log(2);
    for (int i = 0; i < n; ++i) {
        Rmq[i][0] = array[i];
    } 
    for (int i = 1; i <= d; ++i) {
        for (int j = 0; j < n; ++j) {
	    if (j + pow(2,i)>n) continue;
	    Rmq[j][i] = Max(Rmq[j][i-1], Rmq[j + (int)pow(2, i - 1) ][i - 1]);
	    //Rmq[j][i] = Rmq[j][i-1] +  Rmq[j + (int)pow(2, i - 1) ][i - 1];
	}
    } 
}

int queryRmq(int array[], int l, int r)
{
    if (l == r) return array[l];
    int d = log(r - l + 1)/log(2) + 1;
    cout<<d<<endl;
    return Max(Rmq[l][d-1], Rmq[r - (int)pow(2, d-1) + 1 ][d - 1]);
    //return Rmq[l][d-1] +  Rmq[l + (int)pow(2, d-1) ][d - 1];
}
int main()
{
    int array[] = {2, 3, 4, 5, 2, 12, 11, 31, 3};
    for (int i = 0; i<cnt; ++i) {
        cout<<array[i]<<" ";
    }
    cout<<endl;
    rmq(array, 9);
    while (true) {
    int i, j;
    cin>>i>>j;
    cout<<queryRmq(array, i,j)<<endl; 
    }
    return 0;
}
