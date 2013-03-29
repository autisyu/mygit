#include<stdio.h>
int LowerBound(int *attr, int s, int e, int v)//lower_bound
{
    int mid;
    while (s < e) {
        mid = s + ((e - s)>>1);
	if ( v <= attr[mid]) e = mid;
	else {
	  s = mid + 1;
	}
    }
    return s;
}
int UpBound(int *attr, int s, int e, int v)//lower_bound
{
    int mid;
    while (s < e) {
        mid = s + ((e - s)>>1);
	if ( attr[mid] > v ) e = mid;
	else {
	  s = mid + 1;
	}
    }
    return s - 1;
}
int main()
{
    int attr[] = {1, 2, 4, 4, 7};
    printf("%d\n", LowerBound(attr, 0, 5, 3));
    return 0;
}
