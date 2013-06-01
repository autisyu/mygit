#include<stdio.h>
int N = 82;
void data(int t) 
{
    int lm, lt, a = N + t, y, r, left;
    y     = a / 365;
    r     = y / 4;
    left  = a % 365 - r;
    lm = left / 30;
    lt = left % 30;
    if (left < 0) {
      printf("%d/%d/%d\n", 2013 + y - 1, 12 - lm, 30 - lt);
    } else {
      if ((2013 + y) % 4 == 0) {
        if (lm >= 2) {
	  lm += (lt + 1) / 30;
	  lt = (lt + 1) % 30;
	} 
          printf("%d/%d/%d\n", 2013 + y, lm + 1, lt);
      } else {
        if (lm >= 2) {
	  lm += (lt + 2) / 30;
	  lt = (lt + 2) % 30;
         }
          printf("%d/%d/%d\n", 2013 + y, lm + 1, lt);
	 
       }
    }
}
int main()
{

    int n, q, i;
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
      scanf("%d", &q);
      data(q);
    }
    return 0;
}
