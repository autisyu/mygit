#include<iostream>
#include<stdio.h>
using namespace std;
const int cnt = 7;
void HeapAjust(int array[], int i, int nLength)
{
    int nChild;
    int nTemp;
    for (nTemp = array[i]; 2 * i + 1 < nLength; i = nChild ) {
        nChild = 2 * i + 1;
	if (nChild < nLength - 1 && array[nChild + 1] < array[nChild]) {
	    ++nChild;
	}
	if(nTemp > array[nChild]) {
	    array[i] = array[nChild];
	    array[nChild] = nTemp;//nTemp don't need change
	} else {
	    break;
	}
    }
}
void swap(int array[], int i, int j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}
void HeapSort(int array[], int length)
{
    for (int i = length>>1 - 1; i >= 0; --i) {
        HeapAjust(array, i, length);
    }
    for (int i = length - 1; i >= 1; --i)
    {
	swap(array, 0, i);
	HeapAjust(array, 0, i);
    }
}

int main(int argc, char** argv)
{
    int num[] = {1,5,6,45,88,89,110};
    HeapSort(num, cnt);
    for (int i = 0; i < cnt; ++i) {
        printf("%d ",num[i]);
    }
    return 0;
}
