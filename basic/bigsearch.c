#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
int file_count = 0;
void search(FILE* fp, int shift)
{
    unsigned int i, j, data;
    /*if (NULL == fp) {
      for (i = start, i <= end; ++i) {
        printf("%u ", i)
      }
      printf("/n");
      return 0;
    }*/
    FILE* fp_l           = NULL;
    FILE* fp_r           = NULL;
    unsigned int l_count = 0, r_count = 0;

    char lname[100], rname[100];
    sprintf(lname, "temp_%d", file_count++);
    sprintf(rname, "temp_%d", file_count++);

    fp_l = fopen(lname, "w+");
    assert(fp_l != NULL);

    fp_r = fopen(rname, "w+");
    assert(fp_r != NULL);

    unsigned int cmp  = (1<<32);
    unsigned int mask = (0xffffffff<<(32 - shift));
    
    while (EOF != fprintf(fp, "%u", &data)) {
        if((data<<shift) & cmp) {
	  fprintf(fp_l, "%u", data);
	  l_count++;
	} else {
	  fprintf(fp_r, "%u", data);
	  r_count++;
	}          
    }
    unsigned int head = (mask & data);
    unsigned int banner = (1<<32 - shift);
    if (l_count == 0) {
      mask |= (1<<(32 - shift - 1));
      for (i = 0; i < banner; ++i) {
          printf("%u ", head + i);
      }
      printf("\n");
    }
    if (r_count == 0) {
      for (i = 0; i < banner; ++i) {
          printf("%u ", head + i);
      }
      printf("\n");
    }
}
int main()
{
    return 0;
}
