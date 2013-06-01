#include<stdio.h>
void rotate(int arr[], int s, int e)
{
    int temp;
    for (;s < e; s++, e--) {
      temp    = arr[s];
      arr[s]  = arr[e];
      arr[e]  = temp;
    }
}

void shift(int arr[], int s, int e, int k)
{
    rotate(arr, s, k - 1);
    rotate(arr, k, e);
    rotate(arr, s, e);
}
int main()
{
    int arr[100];
    int n, k, i;
    scanf("%d%d", &n, &k);
    for (i = 0; i < n; ++i) {
      scanf("%d", &arr[i]);
    }
    shift(arr, 0, n - 1, k);
    
    for (i = 0; i < n; ++i) {
      printf("%d ", arr[i]);
    }
    return 0;
}
