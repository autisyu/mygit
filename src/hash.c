#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<malloc.h>
#define HASH_SIZE 9973   
struct hash_node{
    int key, value;
    hash_node * next;
    hash_node() {
        next = NULL;
    }
};

struct hash_head {
    int count;
    hash_node* first;
    hash_head() {
        count = 0;
	first = NULL;
    }
};

struct hash_map {
    hash_head head[HASH_SIZE];
};
int  hash_find(hash_map map, int key, int &value)
{
    int hash_key     = key % HASH_SIZE;
    hash_node** head = &(map.head[hash_key].first);
    hash_node* tp    = map.head[hash_key].first;
    while (tp && key!= tp->key) {
        tp = tp->next;
    }
    if (tp == NULL) {
        return 0;
    } 
    value = tp->value;
    return 1;

}
void hash_insert(hash_map& map, int key, int value)
{
    int hash_key     = key % HASH_SIZE;
    hash_node** head = &(map.head[hash_key].first);
    hash_node* tp    = map.head[hash_key].first;
    while (tp && key!= tp->key) {
        tp = tp->next;
    }

    if (tp) {
        tp->value = value;
	return;
    }
    tp        = (hash_node*)malloc(sizeof(hash_node));
    tp->key   = key, tp->value = value;
    tp->next  = *head;
    *head     = tp;
    map.head[hash_key].count++;
    return;
}
int main()
{
    hash_map map;
    int n, m, key, value, i, j, max = -1;
    /*printf("please input n, m\n");
    scanf("%d%d", &n, &m);
    printf("please input insert key, value\n");
    for (i = 0; i < n; ++i) {
        scanf("%d%d", &key, &value);
	hash_insert(map, key, value);
    }
    printf("please input find key\n");
    for (i = 0; i < m; ++i) {
        scanf("%d", &key);
	if (hash_find(map, key, value)) {
	    printf("key = %d, value = %d\n", key, value);
	} else {
	    printf("not found\n");
	}
    }*/
    for (i = 0; i < 5100; ++i) {
        key = rand(), value = rand();
        hash_insert(map, key, value);
    }
     
    for (i = 0; i < HASH_SIZE; ++i) {
        if (map.head[i].count > max) {
	    max = map.head[i].count;
	}
    }
    printf("%d\n", max);
    return 0;
}
