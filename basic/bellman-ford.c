#include<stdio.h>
#include<stdlib.h>
#define N 100
#define max 0xffffff
int V, E;
int distance[N];
struct Edge {
    int u, v, w;
};

static inline void relax(struct Edge e)
{
    if (distance[e.v] > distance[e.u] + e.w) {
      distance[e.v] = distance[e.u] + e.w;
    }
}
struct Edge *ptr_edge = NULL; 
int bellman_ford()
{
    int nodeid, edgeid;
    for (nodeid = 0; nodeid < V - 1; ++nodeid) {
        for (edgeid = 0; edgeid < E; ++edgeid) {
	    relax(ptr_edge[edgeid]);
	}
    }
    for (edgeid = 0; edgeid < E; ++edgeid) {
        if (distance[ptr_edge[edgeid].v] > distance[ptr_edge[edgeid].u] + ptr_edge[edgeid].w) {
	  return 0;
	}
    }
    return 1;
}
int main()
{
    int start;
    scanf("%d%d%d", &V, &E, &start);
    int index, cnt;
    ptr_edge = (struct Edge*)malloc(E * sizeof(struct Edge));

    for (index = 0; index < E; ++index) {
        scanf("%d%d%d", &ptr_edge[index].u, &ptr_edge[index].v, &ptr_edge[index].w);
    }
    for (index = 0; index < V; ++index) {
        distance[index] = max;
    }
    distance[start] = 0;
    if (bellman_ford()) {
      for (cnt = 0; cnt < V; ++cnt) {
          printf("%d %d\n", cnt, distance[cnt]);
      }
    } else {
      printf("loop exist!\n");
    }
    return 0;
}
