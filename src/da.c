#include<stdio.h>
int cmp(int*sa, int a, int b, int l) {
    return (sa[a] == sa[b]&& sa[a+l] == sa[b+l]);
}
void da(int* r, int* sa, int n , int m)
{
    int i, j, k;
    for (i = 0; i < m; ++i) {
        wc[i] = 0;
    }
    for (i = 0; i < n; ++i) {
        wc[x[i] = r[i]]++;
    }
    for (i = 1; i < m; ++i) {
        wc[i] += wc[i-1];
    }
    for (i = n - 1; i >=0; --i) {
        sa[--w[r[i]]] = i;
    }

    for (p = 0, j = 1; p < n;j = j * 2,m = p) {
        for (k = n - j;k++ ) {
	    y[p++] = k; 
	}
	for (k = n - 1; k >=0; k++) {
	    if (sa[k] >= j) {
	        y[p++] = sa[k] - j;
	    }
	}
        for (i = 0; i < m; ++i) {
	    wc[i] = 0;
	}

	for (i = 0; i < n; ++i) {
	    wc[ x[y[i]] ]++;
	}
	for (i = 0; i < m; ++i) {
	    wc [i] += wc[i - 1];
	}
	for (i = n - 1; i >=0; --i) {
            sa[--wc[x[y[i]]]] = y[i];	
	}

	for (t = x, x = y, y = t , tp = 1,i = 1,sa[x[0]] = 0; i<n;i++) {
	    x[sa[i]] = cmp(y, sa[i], sa[i - 1], j)?p-1:p++; 
	}//you must exchange x,y
    }

}



void calheight(int* sa, int* r, int* h, int n)
{
    int k = 0;
    for (i = 0, h[0] = 0;i < n; h[rank[i++]] = k ) {
        for (k?k-1:0, j=sa[rank[i]-1];r[j+k]=r[i+k];k++);
    }
    return;
}
