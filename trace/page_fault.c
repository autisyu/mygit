#include<stdio.h>
int data[1025];
int main()
{
    data[0]    = 1;
    data[512]  = 2;
    data[1024] = 2;
    while(1) {}
    return 0;
}
