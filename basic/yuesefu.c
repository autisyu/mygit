#include<stdio.h>
int yuesefu(int k, int n)
{
    int _x  = 0;
    int cnt = 1, x; 
    while (cnt + 1 <= n) {
        x  = (_x + k + cnt + 1) % (cnt + 1);
	_x = x;
	cnt++;
    }
    return _x;
}
int main()
{
    int k, n;
    scanf("%d%d", &k, &n);
    printf("%d\n", yuesefu(k, n));
    return 0;
}
