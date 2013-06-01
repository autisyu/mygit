#include<iostream>     
//#include<cstring>
#include<stdio.h>
//#include<cstdio>
#include<queue>
#include<string.h>
#include<map>
#include<algorithm>
using namespace std;
#include<stdlib.h>
#include<math.h>
#define INF 999999999
int edge[102];
map<string, int> edge_weight;
map<string, int> path;
char int_string[20];
int cnt_edge = 0;
int cnt_result[1002];
string str_result[1002];
int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}
int select(int ne) 
{
    //qsort(edge, ne, sizeof(int), cmp);
    //sort(edge, edge + ne);
    int ine, i, j, k, l;
    for (j = 0; j < ne - 2; j++) {
        for (k = j + 1; k < ne - 1; ++k) {
	    for (l = k + 1; l < ne; ++l) {
                if (edge[j] + edge[k] > edge[l] && edge[j] + edge[l] > edge[k] && edge[l] + edge[k] > edge[j]) {
	            return 1;
	        }
	    }
        }
   }
    return 0;
}
struct node
{
    int y,v,next;
}a[1110];
int cnt,head[1205],n,m;
void ad(int x,int y,int v)
{
    a[cnt].next=head[x];
    a[cnt].y=y;
    a[cnt].v=v;
    head[x]=cnt++;
}
struct Dis
{
    int y,dis;
    bool operator<(const Dis &a) const
    {return dis>a.dis;}
};
int dijkstra(int s, int e, int cnt_node)
{
    Dis c,tmp;
    c.y=s;c.dis=0;
    int dis[1022],x ;
    for(int i=1;i<=cnt_node;i++)
        dis[i]=INF;
    dis[s]=0;
    priority_queue<Dis> q;
    q.push(c);
    sprintf(int_string, "%d", s);
    string s1 = int_string;
    string s2;
    //while(!q.empty())
    for (x = 0; x < cnt_node && !q.empty(); x++)
    {
        c=q.top();q.pop();
        int x=c.y;
        //if(dis[x]<c.dis) break;
        for(int i=head[x];i!=-1;i=a[i].next) {
            if(dis[a[i].y]>dis[x]+a[i].v)
            {
	        
	        sprintf(int_string, "%d", a[i].y);
		s2.assign(int_string);
		path[s1+s2] = x; 
                dis[a[i].y]=dis[x]+a[i].v;
                tmp.y=a[i].y;tmp.dis=dis[a[i].y];
                q.push(tmp);
            }
        }
    }
    int now = e;
    int ne  = 0;
    //cout<<dis[e]<<endl;
    //if (dis[e] == INF) {cout<<"no ans"<<endl; return 0;}
    /*getchar();
    getchar();*/
    while(now != s) {
	sprintf(int_string, "%d", now);
	string se = int_string;

        int pe    = path[s1+se];
        //cout<<"pre"<<now<<" ="<<pe<<endl;	
	sprintf(int_string, "%d", pe);
        s2.assign(int_string);

        edge[ne]  = edge_weight[s2+se];
	//cout<<edge[ne]<<endl;
	ne++;
	now       = pe;
	if (ne >= cnt_node) break;
    }
    return ne;
    //return dis[n];
}
int main()
{
    string s1, s2;
    int it, in, im, T, N, M;
    int i,x,y,w;
    int s, e;
    int tx = 1, ty = 2, tv =9;
    cnt=0;
    cin>>T;
    //T = 5;
    for (it = 0; it < T; ++it) {
        cnt = 0;
        cin>>N;
	//N = 101, M = 100;
        for(in=1;in<=N;in++)head[in]=-1;
        for(in=1;in<N;in++)
        {
            scanf("%d%d%d",&x,&y,&w);
	    //x = tx, y = ty, w = tv;
	    //tx = rand() % 100, ty = rand() % 100; tv = rand() % 100;
	    sprintf(int_string, "%d", x);
	    s1.assign(int_string);
	    sprintf(int_string, "%d", y);
	    s2.assign(int_string);
	    edge_weight[s1+s2] = w;
	    edge_weight[s2+s1] = w;
            ad(x,y,w);
	    ad(y,x,w);

        }
	cin>>M;
        tx  = 0, ty = 9;
	int cm = 0;
	for (im = 0; im < M; im++) {
            //tx = rand() % 100, ty = rand() % 100;
	    cin>>s>>e;
	    //s = tx, e  = ty;
            int ne = dijkstra(s, e, N);
	    if (ne < 3) {
	        str_result[cm++] = "No";
	    } else {
	        int res = select(ne);
		if (res) {
		    str_result[cm++] = "Yes";
		} else {
		    str_result[cm++] = "No";
		}
	    }
          
	}
        cout<<"Case #"<<it + 1<<":"<<endl;
        for (im = 0; im < M; ++im) {
            cout<<str_result[im]<<endl;
        }
	//cout<<it<<endl;
    }
}
