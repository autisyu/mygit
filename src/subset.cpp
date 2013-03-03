#include<iostream>
using namespace std;

void subset(int array[], int n)
{
    for (int i = 1; i < (1<<n); ++i) {
        cout<<"i = "<<i<<endl;
        for (int j = 0; j < n; ++j) {
	    if ((1<<j)&i) cout<<array[j]<<" ";
	}
	cout<<endl;
    }
}
int main()
{
    int array[] = {1,2,3,4,5};
    subset(array, 5);
    return 0;
}
