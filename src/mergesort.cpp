#include<iostream>
using namespace std;
const int cnt = 9;
int grev = 0;
void merge(int array[], unsigned int l, unsigned int mid, unsigned int r)
{
    int rev = 0;
    unsigned int ls = l, rs = mid + 1, index = 0;
    int temp[r - l + 1];
    while (ls <= mid&&rs <= r) {
        if (array[ls] <= array[rs]) {
	    temp[index++] = array[ls++];
	} else {
	    rev += (mid - ls + 1);
	    temp[index++] = array[rs++];
	}
    
    }

    int ntemp = ls > mid ? rs : ls;
    if (ls > mid) {
        while (ntemp <= r) {
	    temp[index++] = array[ntemp++];
	}
    } else {
        while (ntemp <= mid) {
	    temp[index++] = array[ntemp++];
	}
    }
    for (int i = 0; i < index; ++i) {
        array[l + i] = temp[i];
    }
    grev += rev;

}
void mergesort(int array[], unsigned int l, unsigned int r) {
    if (l < r) {
        unsigned int mid = l + ((r - l)>>1);
        //int mid = (l + r) / 2;
        mergesort(array, l, mid);
        mergesort(array, mid + 1, r);
	merge(array, l, mid, r);
    }

}
int main()
{
    int array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    mergesort(array, 0, cnt - 1);
    for (int i = 0; i < cnt; ++i) {
        cout<<array[i]<<" ";    
    }
    cout<<endl<<grev<<endl;
    return 0;
}
