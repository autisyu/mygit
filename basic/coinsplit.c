#include<stdio.h>
#include<memory.h>
#define N 1000
int d[N], V[N], cnt;
int dp(int S)
{
   int &ans = d[S], i;
   if (ans != -1) return ans;
   ans = -0xfffff;
   for (i = 0; i < cnt; ++i) {
       if (S >= V[i]) {
         ans = ans > dp(S - V[i]) + 1 ? ans : dp(S - V[i]) + 1;
       }
   }
   return ans;
}
void print_ans(int S)
{
    int i;
    while(S > 0) {
    for (i = 0; i < cnt; ++i) {
        if (S >= V[i]&&d[S] == 1 + d[S - V[i]]) {
	    printf("%d\n", V[i]);
            S -= V[i];
	    break;
	}
    }
    }
}
int main()
{
    int i = 0, S;
    for (i = 0; i < N; ++i) {
        d[i] = -1; 
    }
    d[0] = 0;
    cnt  = 3;
    for (i = 0; i < cnt; ++i) {
        scanf("%d", &V[i]);
    }
    scanf("%d", &S);
    printf("%d\n", dp(S));
    print_ans(S);
    return 0;
}
