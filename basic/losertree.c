#include<stdio.h>
#include<memory.h>
#define MAXMIN -0xfffff
#define MAXMAX 0xfffff
#define N 4
int losernode[N];
int leaf[N + 1];
static void swap(int &a, int &b)
{
    int temp = a;
    a        = b; 
    b        = temp;
}
void Modify(int j) 
{
    int parent = (j + N) / 2;
    int winner = j;
    while (parent > 0) {
        if (leaf[losernode[parent]] < leaf[winner]) {
	  swap(winner, losernode[parent]);
	}
	parent /= 2;
    }
    losernode[0] = winner;
}
void CreateLoserTree()
{
    int i, j;
    for (i = 0; i < N; ++i) {
        losernode[i] = N;
    }
    for (j = 0; j < N; ++j) {
        Modify(j);
    }
}
int pa[N];
int data[N][5] = {{1, 3, 4, 6, MAXMAX}, {1, 3, 4, 6, MAXMAX}, {1, 3, 4, 6, MAXMAX}, {1, 3, 4, 6, MAXMAX}};
int main()
{
    int i;
    memset(pa, 0, N *sizeof(int));
    for (i = 0; i < N; ++i) {
        leaf[i] = data[i][pa[i]];
	pa[i]++;
    }
    leaf[N] = MAXMIN;
    CreateLoserTree();
    while (leaf[losernode[0]] != MAXMAX) {
        printf("%d ", leaf[losernode[0]]);
	int i   = losernode[0];
	leaf[i] = data[i][pa[i]++];
	Modify(i);
    }
    return 0;
}
