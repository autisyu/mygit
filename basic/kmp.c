#include"stdio.h"
#include"string.h"
typedef struct {
    int count;
    ac_t next[26];
    ac_t *fail;
    ac_t() {
      count = 0;
      for (int i = 0; i < 26; ++i) {
        next[i] = NULL;
      }
      fail = NULL;
    }
}ac_t;

ac_t* root = NULL;

void insert(char *str, ac_t *root)
{
    int len = strlen(str);
    ac_t *temp = root;
    for (i = 0; i < len; ++i) {
        int id = str[i] - 'a';
        if (temp->next[id] == NULL) {
	  ac_t node = (ac_t*)malloc(sizeof(ac_t));
	  temp->next[id] = node;
	}
	temp = temp->next[id];
    }
    temp->count++;
}
void Build_AC(ac_t *root)
{
    int st = 0, i;
    ac_t * queue[100], head =  tail = 0;
    queue[tail++] = root; 
    while (head != tail) {
        ac_t elem = queue[head++];   
	for (i = 0; i < 26; ++i) {
            if (elem->next[i] != NULL) {
	      queue[tail++] = elem->next[i]; 
	    }	
	    if (elem == root) {
	      elem->next[i]->fail == root;
	    }
	    ac_t* node = elem->fail;
	    while (node != NULL) {
	        if (node->next[i] != NULL) {
		    elem->next[i]->fail = node->next[i];
		    break;
		}
		node = node->fail;
	    }
	    if (node == NULL) {
	        elem->next[i]->fail = root;
	    }
	}
    }
    }
}
int query(char *str, ac_t *root)
{
    int i, len = strlen(str), result = 0;
    ac_t *temp = root;
    for (i = 0; i < len; ++i) {
        index = str[i] - 'a';
        while (temp->next[index] == NULL && temp != root) {
	    temp = temp->fail;
	}

	p = p->next[index];
	if (p == NULL)
	p = root;
	ac_t *node = p;

	while (node != root && node->count != -1) {
	    result += node->count;
	    temp->count = -1;
	    temp = temp->fail;
	}
    }
    return result;
}
void GetNext(int *next, const char *P)
{
    int len = strlen(P);
    next[0] = -1, next[1] = 0;
    int j = 0, p = 1;
    while (p < len) {
        if (j == -1 || P[p] == P[j]) {
	  p++, j++, next[p] = j;
	} else {
	  j = next[j];
	}
    }
}

int KMP(char *S, char *T, int *next)
{
    int t = 1, m = strlen(T), s = 1;
    while (s < strlen(S)) {
        if (t == -1 || S[s] == T[t]) {
	  s++; t++;
	} 
	else {
          
	  t = next[t];  
	}
        if (t == m) {
          return s - t + 1;
        }
    }
    return -1;
}
int main()
{
    ac_t *root = (ac_t*)malloc(sizeof(ac_t))
    int next[100];
    char S[100],  T[100];
    int cnt = 0; 
    scanf("%s%s", S, T);
    GetNext(next, T);
    for (; cnt < strlen(T); ++cnt ) {
        printf("%d ", next[cnt]);
    }
    printf("\n");
    printf("\n%d\n", KMP(S, T, next));
    return 0;
}
