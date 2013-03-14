#include<stdlib.h>
#include<stdio.h>
int main()
{
    int *tp  = (int*)malloc(3*sizeof(int));
    tp[2]    = 9;
    int *rtp = (int*)realloc(tp, 10);
    printf("%d\n", rtp[6]);
    int *ctp = (int*)calloc(10, sizeof(int));

    printf("%d\n", ctp[6]);
    free(tp);
    return 0;
}
