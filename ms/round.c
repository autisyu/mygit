#include<stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", (((((int)(n))+(4)-1)) & ~((4)-1)));
    return 0;
}
