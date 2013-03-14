#include<stdio.h>
static inline int max(int a, int b) { return a > b ? a: b ;}
static inline int checktype(char type) { return (type == 'A' || type == 'B' || type == 'C');}
int f[3100000];
int knap(int Q, int cnt, const int *data)
{
    int i, j;
    for (j = 0; j <= Q; j++) {
        f[j] = 0;
    }

    for (i = 1; i <= cnt; ++i) {
        for (j = Q; j >= data[i-1]; --j) {
	      f[j] = max(f[j], f[j - data[i - 1]] + data[i - 1]);
	}
    }
    return f[Q];
}
int item[40];
int cnt = 0;
int main()
{
    float Q, price, total;
    int N, i, j, num, temp_num;
    char type;
    while (scanf("%f%d", &Q, &N) && N != 0) {
	for (i = 0; i < N; ++i) {
	    total     = 0.0f;  
	    temp_num  = 0;
	    scanf("%d", &num);
	    getchar();
	    for (j = 0; j < num; ++j) {
	        type = getchar();
		getchar();
		scanf("%f", &price);
		getchar();

		total += price;
		if (checktype(type) && price <= 600.0f) {
		  item[cnt++] = price * 100;
		  temp_num++;
		}
	    }
	    if (total > 1000.0f) {
	      cnt -= temp_num;
	    }
	}
	float res = knap(Q * 100, cnt, item) / 100.0f;
	printf("%.2f\n", res);
	cnt = 0;
    }
    return 0;
}
