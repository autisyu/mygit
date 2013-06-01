/* @filename:example_2_4.c */
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
char *p_4kb, *p_128kb, *p_300kb;
if ((p_4kb = malloc(4*1024)) != NULL)
{
free(p_4kb);
}
if ((p_128kb = malloc(128*1024)) != NULL)
{
p_128kb[0] = 0;
free(p_128kb);
}
if ((p_300kb = malloc(300*1024)) != NULL)
{
free(p_300kb);
}
while(1) {}
return 0;
}

