#include<stdio.h>
int mls(const int *data, int start, int end)
{
    int sum = data[start];
    int i, j, sub = sum;
    for(i = start + 1; i <= end; ++i) {
        if (sub > 0) {
	  sub += data[i];
	} else {
	  sub = data[i];
	}
	sum = sub > sum ? sub: sum; 
    }
    return sum;
}
int main()
{
    int data[] = {1, -1, 2, 3, -3, 2};
    int i;
    for (i = 0; i < 6; ++i) {
        printf("%d ", data[i]);
    }
    printf("\n%d", mls(data, 0, 5));
    return 0;
}
