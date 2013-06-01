#include "sort.h"
#include<assert.h>
#include <stdio.h>
#include <stdlib.h>
static void swap(int* data, int a, int b);
static int SubQuickSort(int* data, int start, int end)
{
    if (data == NULL) return -1;

    int p_value = data[start];
    int t_start = start, t_end = end;
    while (t_start < t_end) {
	while(t_start < t_end && data[t_end] >= p_value) {t_end--;}
	data[t_start] = data[t_end];
        while(t_start < t_end && data[t_start] <= p_value) {t_start++;} 
	data[t_end]   = data[t_start];
    }
    data[t_start] = p_value;
    return t_start;
}
int QuickSort(int* data, int start, int end)
{
    while (start <=  end) {
      int pivort = SubQuickSort2(data, start, end);
      QuickSort(data, start, pivort - 1);
      start = pivort + 1;
      //QuickSort(data, pivort + 1, end);
    }
}

int SubQuickSort2(int* data, int start, int end)
{
    int p_pivort = start, swap_index = start + 1;
    int v_pivort = data[start];
    int i; 
    for (i = start + 1; i <= end; ++i) {
        if (data[i] < v_pivort) {
	  swap(data, i, swap_index);
	  swap_index++;
	}
    }
    swap(data, start, swap_index - 1);
    for (i = 0; i < 8; ++i) {
        printf("%d ", data[i]);
    }
    printf("\n");
    //data[swap_index] = v_pivort;
    return swap_index - 1;
}
int Midian(int arr[], int n)
{
    assert(arr != NULL && n>=1);
    int midian = n/2;
    int pivort, start = 0, end = n - 1;
    do {
    pivort = SubQuickSort2(arr, start, end);
    if (pivort > midian) {
      end = pivort - 1;
    } else if (pivort < midian) {
      start = pivort + 1; 
    }
    break;
    } while(1);
    return arr[pivort];
}
static void Merge(int* data, int start, int mid, int end)
{
    int t_data[1000], left = start, right = mid + 1, index = 0;
    int i, j;
    while (left <= mid && right <= end) {
        if (data[left] <= data[right]) {
	  t_data[index++] = data[left++];
	} else {
	  t_data[index++] = data[right++];
	}
    }
    while (left <= mid) {
        t_data[index++] = data[left++];
    }
    while (right <= end) {
        t_data[index++] = data[right++];
    }
    for (i = 0, j = start; i < index; ) {
        data[j++] = t_data[i++];
    }
}

int MergeSort(int* data, int start, int end)
{
    if (start < end) {
      int mid = ((start + end)>>1);
      MergeSort(data, start, mid);
      MergeSort(data, mid + 1, end);
      Merge(data, start, mid, end);
    }

}
static inline void swap(int* data, int pos1, int pos2)
{
   if (pos2 == pos1) return;
   data[pos1] ^= data[pos2];
   data[pos2] ^= data[pos1];
   data[pos1] ^= data[pos2];
}
static void siftup(int *data, int pos)
{
    while (1) {
        int i = (pos>>1);
	if (i == 0) break;
        if (data[pos] < data[i]) {
	  swap(data, i, pos);
	}
	pos = i;
    }
}

static void HeapRelay(int* data, int pos, int end) 
{
   int t_pos = pos;
   while (pos * 2 <= end) {
       if (2 * pos + 1 <= end && data[2 * pos + 1] < data[pos]) {t_pos = 2 * pos + 1;} 
       if (data[2 * pos] < data[pos] && data[2 * pos] < data[t_pos]) {t_pos = 2 * pos;}
       if (pos == t_pos) break;
       swap(data, pos, t_pos);
       pos = t_pos;
   } 
}
int HeapSort(int* data, int start, int end)
{
    int h = (end - start + 1) / 2 - 1;
    int i;
    for (; h >= 0; --h) {
        HeapRelay(data, h, end);
    }
    for (i = end; i > 0; --i) {
        swap(data, i, 0);
	HeapRelay(data, 0, i - 1);
    }
}
int HeapSortSimple(int *data, int start, int end)
{
    int pos = start;
    int i, j;
    for (i = 1; i <= end; ++i) {
        siftup(data, i);
    }
    for (j = end; j >= 1; --j) {
        swap(data, j, 0);
	HeapRelay(data, 0, j - 1);
    }
}
int main()
{
    int a[] = {5, 1, 2, 7, 6, 8, 4, 3};
    int i;
    QuickSort(a, 0, 7);
    //MergeSort(a, 0, 5);
    //HeapSort(a, 0, 5);
    for (i = 0; i < 8; ++i) {
        printf("%d ", a[i]);
    }
    //cout<<endl;
}
