#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<stdio.h>
using namespace std;

int partition(int array[], int l, int r)
{
    int pivot = rand()%(r - l + 1) + l;
    int nTemp = array[pivot];
    array[pivot] = array[l];
    array[l] = nTemp;
    while (l < r) {
        while (l < r && array[r]>=nTemp) { r-- ;}
	array[l] = array[r];
        while (l < r && array[l]<nTemp) { l++ ;}
	array[r] = array[l];
    } 
    array[l] = nTemp;
    return l;
}
void quicksort(int array[], int start, int end)
{
    if (start < end) {
        int pivot = partition(array, start, end);
        //cout<<"start = "<<start<<",end = "<<end<<",pivort = "<<pivot<<endl; 
	quicksort(array, start, pivot - 1);
	quicksort(array, pivot + 1, end);
    }
}

int main()
{
    int array[] = {1,2,6,7,8,49,890};
    quicksort(array, 0, 6);
    for (int i = 0; i < 7; ++i) {
        cout<<array[i]<<" ";
    }
    return 0;
}


