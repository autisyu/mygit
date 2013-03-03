#include<iostream>
using namespace std;
const int cnt = 8;
const int inf = 0x7fffff;
int range[cnt][cnt];
void init()
{
    for (int i = 0; i < cnt; ++i) {
        for (int j = 0; j < cnt; ++j) {
	    range[i][j] = inf;
	}
    }
}

int rangeValue(int array[], int l, int r)
{
    int& a = range[l][r];
    if (a != inf ) return range[l][r];
    int mid = l + ((r - l)>>1);
    if (l == r) return array[l];
    return range[l][r] = rangeValue(array, l, mid) + rangeValue(array, mid + 1, r);
}
int main()
{
    init();
    int array[] = {1,2,3,4,5,6,7,8};
    rangeValue(array, 0, 7);
    int l, r;
    cin>>l>>r;
    for (int i = 0; i < cnt; ++i) {
        for (int j = 0; j < cnt; ++j) {
	    cout<<range[i][j]<<" ";
	}
	cout<<endl;
    }
    cout<<range[l][r]<<endl;
    return 0;
}
