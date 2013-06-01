#include<stdio.h>
int main()
{
    int i, T, N, K, M;
    int delta, t, temp;
    scanf("%d", &T);
    for (i = 0;i < T; ++i) {
        scanf("%d%d%d",  &N, &K, &M);
	temp = N * K; 
	t = temp / M;
	if (t < K) { printf("%d\n", K);}
	else {
	delta = temp % M;
	if (delta > 0) { printf("%d\n", t + 1);} 
	else {printf("%d\n", t);}
	}
    }
    return 0;
}
