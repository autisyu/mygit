#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#define MAX 0x7fffffff
int main()
{
    FILE *fp = NULL;
    fp       = fopen("data.dat", "w+");
    assert(fp != NULL);
    int cnt;
    for (cnt = 0; cnt < 10000000; cnt++) {
        int random = rand();
        fprintf(fp, "%d\n", random);
    }
    return 0;
}
