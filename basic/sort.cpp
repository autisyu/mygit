#include "sort.h"
#include <iostream>
using namespace std;
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
    if (start <= end) {
      int pivort = SubQuickSort(data, start, end);
      QuickSort(data, start, pivort - 1);
      QuickSort(data, pivort + 1, end);
    }
}

static void Merge(int* data, int start, int mid, int end)
{
    int t_data[1000], left = start, right = mid + 1, index = 0;
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
    for (int i = 0, j = start; i < index; ) {
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
   data[pos1] ^= data[pos2];
   data[pos2] ^= data[pos1];
   data[pos1] ^= data[pos2];
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
    for (; h >= 0; --h) {
        HeapRelay(data, h, end);
    }
    for (int i = end; i > 0; --i) {
        swap(data, i, 0);
	HeapRelay(data, 0, i - 1);
    }
}
int main()
{
    int a[] = {9, 8, 7, 6, 5, 4};
    //QuickSort(a, 0, 5);
    //MergeSort(a, 0, 5);
    HeapSort(a, 0, 5);
    for (int i = 0; i < 6; ++i) {
      cout<<a[i]<<" ";
    }
    cout<<endl;
}
