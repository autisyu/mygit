#include<iostream>
#include<cmath>
using namespace std;
const int inf = 0x7ffffff;
const int N = 8;
inline int Min(int a, int b) 
{
    return a>b?b:a;
}
int mpp_s(int array[])
{
    int d[1<<N];
    d[0] =  0;
    for (int S = 1; S < (1<<N); ++S) {
        int i, j;
	d[S] = inf;
	for (i = 0; i < N; ++i) {
	    if (S & (1<<i)) {
	        break;
	    }
	}

	for (j = i + 1; j < N; ++j) {
	    if (S&(1<<j)) d[S] = Min(d[S],abs(array[i] - array[j]) + d[S^(1<<i)^(1<<j)]); 
	}
    }
    return d[(1<<N) - 1];
}
int mpp(int array[])
{
    int d[N + 1][1<<N];
    for (int k = 0; k < (1<<N); ++k) {
        d[0][k] = 0;
    }
    for (int i = 1; i < N; ++i) {
	    for (int S = 1; S < (1<<N); ++S) {
	        d[i][S] = inf;
		for (int j = 0; j < i; ++j) {
	        if (S & (1<<j)) {
	            d[i][S] = Min( d[i][S], abs(array[i]-array[j]) + d[i - 1][S ^(1<<i)^(1<<j)]);
		    cout<<array[i]<<" "<<array[j]<<" "<<d[i][S]<<endl;
		}
		}
	    }
	
	}
    
    return d[N - 1][(1<<N) - 1];
}
int main()
{
    int array[] = {0, 1, 5, 7, 2, 2, 9, 10};
    cout<<mpp_s(array)<<endl;
    return 0;
}
