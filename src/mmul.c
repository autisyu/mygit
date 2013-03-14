#include<stdio.h>
#include<math.h>
#include<stdlib.h>
static inline max(int a, int b) {return a > b? a: b;}
static inline min(int a, int b) {return a < b? a: b;}
int mmuls(const int *data, int start, int end)
{
    int max1 = data[start];
    int max2 = 0;
    int t1, t2;
    
    int i, j;
    for(i = start + 1; i <= end; ++i) {
        t1   = max (data[i] * max1, max(data[i] * max2, data[i]));
        t2   = min (data[i] * max1, min(data[i] * max2, data[i]));
	printf("\n %d %d %d\n", t1, t2, data[i]);
	max1 = t1;
	max2 = t2;
    }
    return max(max1, max2);
}
int main()
{
    int data[] = {5, -1, 2, 3, -3, -2};
    int i;
    for (i = 0; i < 6; ++i) {
        printf("%d ", data[i]);
    }
    printf("\n%d\n", mmuls(data, 0, 5));
    return 0;
}
