#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#define maxn 405
#define Maxn 20000008
using namespace std;
int n,m;
typedef  struct lnode  *glink;
struct  lnode{
    int v;          //边的另一个顶点
    int w;			//边权 
    glink  next;    //邻接表指针，指向邻接表的下一个结点
};
typedef  struct Vnode  *Glink;
struct Vnode	    //表顶点 
{
	int data;       //顶点数，可扩
	glink first_road;
};
glink newnode(int v,int w)
{
	glink x=(lnode *)malloc(sizeof(glink));;
	x->v=v;x->w=w;
	return x;
}
typedef  struct  graph  *Graph;
struct  graph{
    int  n;         	//顶点数
    int  e;        		//边数
    Vnode  adj[maxn];	//邻接表数组
}lgraph;
Graph Graphinit(int n,int m)
{
	int ci;
	Graph G=(Graph)malloc(sizeof(Graph)); 
  	G->n=n;
  	G->e=m;
    for(ci=0;ci<=n;ci++)
    {
    	G->adj[ci].data =0;
    	G->adj[ci].first_road = NULL;
	}
 	return G;
}
static void llink(glink list, glink node)
{
    glink p=list;
   	while(p->next!=NULL)
   	{
   		if(p->v==node->v)
   		{
   			if(p->w>node->w)p->w=node->w;
			return ;	
		}
   		p = p->next;
	}     
    p->next=node;p->next->next=NULL;
}
static void  GraphAdd(int i,int j, int w,Graph G)
{
	glink a=newnode(j,w);
	if(G->adj[i].first_road==NULL)
	{
	G->adj[i].first_road=a;
	G->adj[i].first_road->next=NULL;
	}
	else 
	{
		llink(G->adj[i].first_road,a);
	}
	G->adj[i].data++;
}
typedef pair<int, int> pir;			//first是最短距离，second是顶点的编号
priority_queue<pir, vector<pir>, greater<pir> > q;
int d[maxn][maxn];
void dijkstra(int s,Graph G)
{
		int i,bianhao;
       for(i=0;i<=n;i++)d[s][i]=Maxn;
       d[s][s]=0;
       q.push(make_pair(d[s][s], s));    
       while(!q.empty())
    	{
         pir x=q.top();q.pop();
		 bianhao=x.second;
         glink a=G->adj[bianhao].first_road;
         for(i=0;i<G->adj[bianhao].data;i++)
         {
             if (d[s][a->v] > d[s][bianhao] + a->w)
             {
                 d[s][a->v] = d[s][bianhao] + a->w;
                 q.push(make_pair(d[s][a->v], a->v));
             }
             a=a->next;
         }
     	}
}
int main() 
{
	int i,p,v,u,w;
	Graph H;
	scanf("%d %d", &n, &m);
	H=Graphinit(n,m);
    for(i=0;i<m;i++)
    {
           scanf("%d%d%d", &u, &v, &w);
           GraphAdd(u,v,w,H);
           GraphAdd(v,u,w,H);
    }

    for(i=1;i<=n;i++)dijkstra(i,H);
    cin>>p;
    while(p--)
    {
    scanf("%d %d", &n, &m);
    if(d[n][m]>=Maxn)printf("-1");
	else printf("%d",d[n][m]);
	if(p)printf("\n");	
	}
	return 0;
}
