#include<iostream>
using namespace std;
const int MAX = 0x7ffffff;
inline int Max(int a, int b)
{
    return a>b?a:b;
}
inline int Min(int a, int b)
{
    return a>b?b:a;
}

int MMS(const int array[], int l, int r)
{
    int MA[r-l+1], MI[r-l+1];
    MA[0] = array[l], MI[0] = array[l];
    for(int i = l+1; i <= r; ++i) {
        MA[i-l] = Max(array[i], Max(MA[i-l-1]*array[i], MI[i-l-1]*array[i]));
        MI[i-l] = Min(array[i], Min(MA[i-l-1]*array[i], MI[i-l-1]*array[i]));
    }
    return MA[r-l];
}
int mms(const int array[], int l, int r)
{
    int mul = -MAX, temp[r-l+1][2];
    for (int i = 0; i <= r; ++i) {
        temp[i][0] = -MAX, temp[i][1] = 1;
    }
    for (int i = 1; i <= r+1; ++i) {
            if (array[i-1]>=0) {
                    cout<<"arry[i-1]="<<array[i-1]<<" ";
		    cout<<"temp[i][0] = "<<temp[i][0]<<endl;
	        if (temp[i-1][0]<0) {
		    temp[i][0] = array[i-1];
		} else {
		    temp[i][0] = Max(array[i-1], temp[i-1][0] * array[i-1]);
		    cout<<"temp[i][0] = "<<temp[i][0]<<endl;
		}
		if (temp[i-1][1]<0) {
		    temp[i][1] = temp[i-1][1] * array[i-1];
		}
	    } else {
	        if (temp[i-1][1]>0) {
		    temp[i][1] = array[i-1];
		} else {
		    temp[i][1] = array[i-1] * temp[i-1][0];
		}
		if (temp[i-1][0]>=0) {
		    temp[i][0] = Max(array[i-1] * temp[i-1][1], temp[i-1][0] * array[i-1]);
		}
	    }
	    int tp = mul > temp[i][0]?mul:temp[i][0];
	    mul = tp > temp[i][1]?tp:temp[i][1];
	    cout<<i<<" "<<mul<<" "<<array[i-1]<<" "<<temp[i][0]<<" "<<temp[i][1]<<endl;
	}
    return mul;
}
int mss(const int array[], int l, int r)
{
    int sum = array[l], b = 0;
    for (int i = l; i <= r; ++i) {
        if (b > 0) {
	    b = b + array[i];
	} else {
	    b = array[i];
	}

	if (b > sum ) { sum = b;}
    }
    return sum;
}
int main ()
{
    int array[] = {0, -1, 4, 5, -8, 9};
    for (int i = 0; i <= 5; ++i) cout<<array[i]<<" ";
    cout<<endl;
    //cout<<mss(array, 0, 5)<<endl;;
    cout<<mms(array, 0, 5)<<endl;;
    cout<<MMS(array, 0, 5)<<endl;;
    return 0;
}
