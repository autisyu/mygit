#include<stdio.h>
#define N 1000
int stack[N], top, base;
int  Push(int value)
{
    if (top >= N) { return -1;}
    stack[top] = value;
    top++;
    return 0;
}
int Pop(int& value) 
{
    if (top == base) { return -1;}
    value = stack[top - 1];
    top--;
    return 0;
}
int main()
{
    int i = 0;
    for (i = 0; i < 99; ++i) {
        Push(i);
    }
    for (i = 0; i < 110; i++) {
        int value;
        if ( -1 == Pop(value)) {
	  printf("stack empty\n");
	}
	printf("%d ", value);
    }
    return 0;
}
