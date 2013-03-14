#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define  maxlen  100
char c[maxlen], *a[maxlen];
int pstrcmp(const void *a, const void *b)
{
    return strcmp(*(char**)a, *(char**)b);
}
int main()
{
    char cc;
    int index = 0;
    while((cc = getchar()) != EOF) {
        c[index] = cc;
        a[index] = &c[index];
	index++;
    }
    c[index] = 0;

    qsort(a, index, sizeof(char*), pstrcmp);
    int cnt = 0;
    for (; cnt < index; cnt++) {
        printf("%s\n", a[cnt]);
    }
    return 0;
}
