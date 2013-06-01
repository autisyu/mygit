#include<stdio.h>
#define N 5
static void inline swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void Permute(int* attr, int n)
{
    int j = 0, i;
    if (n == 1) {

    for (j = 3; j >= 0;--j) {
        printf("%d ",*(attr - j));
    }
    printf("\n");

    return ;
    }
    
    Permute(attr + 1, n - 1);
    for (i = 1; i < n; ++i) {
      swap(*attr, *(attr + i));
      Permute(attr + 1 , n - 1);
      swap(*attr, *(attr + i));
    }
    
}
int main()
{
    int attr[] = {1, 2, 3, 4};
    int *temp  = attr, cnt = 0;
    Permute(attr, 4);
    for (;cnt < 4; ++cnt) {
        printf("%d ", attr[cnt]);
    }
    return 0;
}
