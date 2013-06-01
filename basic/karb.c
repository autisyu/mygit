#include<stdio.h>
#include<string.h>
#define PRIME 7235733  
#define BASE 10

int karb(char s[], char t[])
{
   int len_t = strlen(t);
   int len_s = strlen(s);
   int index = 0, source_hash = 0, target_hash = 0, temp_hash = 0; 
   int R     = 1;
   for (; index < len_t; ++index) {
     source_hash = (source_hash * BASE + s[index]) % PRIME;
     target_hash = (target_hash * BASE + t[index]) % PRIME;     
     R           = (R * BASE) % PRIME;
   }
   printf("%d %d %d\n",source_hash, target_hash, R);
   if (source_hash == target_hash) { return 0;}
   for (index = 1; index <= len_s - len_t; ++index) {
     source_hash = (((BASE * source_hash)%PRIME - (s[index - 1] * R)%PRIME + PRIME)%PRIME+ s[index + len_t - 1]) % PRIME;
     printf("%d %d\n",source_hash, target_hash);
     if (target_hash  == source_hash)  {return index;}
   }

   return -1;

}
int main()
{
    char s[100], t[100];
    scanf("%s%s", s, t);
    printf("%d", karb(s, t));
    return 0;
}
