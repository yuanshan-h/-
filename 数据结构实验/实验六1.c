#include"stdio.h"
#include"stdlib.h"
#define MaxVertexNum 100     //定义最大顶点数
typedef struct{
    char vexs[MaxVertexNum];        //顶点表
    int edges[MaxVertexNum][MaxVertexNum]; 
//邻接矩阵，可看作边表
    int n,e;          //图中的顶点数n和边数e
}MGraph;              //用邻接矩阵表示的图的类型
//=========建立邻接矩阵=======
void CreatMGraph(MGraph *G)
{
     int i,j,k;
     char a;
     printf("Input VertexNum(n) and EdgesNum(e): ");
     scanf("%d,%d",&G->n,&G->e);         //输入顶点数和边数
     scanf("%c",&a);            
     printf("Input Vertex string:");
     for(i=0;i<G->n;i++)   
     {
 scanf("%c",&a);
 G->vexs[i]=a;             //读入顶点信息，建立顶点表
     }
    for(i=0;i<G->n;i++)
for(j=0;j<G->n;j++)
   		 G->edges[i][j]=0;    //初始化邻接矩阵
     printf("Input edges,Creat Adjacency Matrix\n");
     for(k=0;k<G->e;k++) {       //读入e条边，建立邻接矩阵  
 scanf("%d%d",&i,&j);        //输入边（Vi，Vj）的顶点序号
 G->edges[i][j]=1;    
 G->edges[j][i]=1; //若为无向图，矩阵为对称矩阵；若建立有向图，去掉该条语句 
     }
}
//=========定义标志向量，为全局变量=======
typedef enum{FALSE,TRUE} Boolean;
Boolean visited[MaxVertexNum];
//========DFS：深度优先遍历的递归算法======
void DFSM(MGraph *G,int i)
{ //以Vi为出发点对邻接矩阵表示的图G进行DFS搜索，邻接矩阵是0，1矩阵
    int j;
    printf("%c",G->vexs[i]);     //访问顶点Vi
    visited[i]=TRUE;             //置已访问标志
    for(j=0;j<G->n;j++)          //依次搜索Vi的邻接点
if(G->edges[i][j]==1 && ! visited[j])
   		DFSM(G,j);              //（Vi，Vj）∈E，且Vj未访问过，故Vj为新出发点
}
void DFS(MGraph *G)
{  //此段代码有一处错误
    int i;
    for(i=0;i<G->n;i++)
visited[i]=FALSE;            //标志向量初始化
    for(i=0;i<G->n;i++)
if(!visited[i])              //Vi未访问过
   		DFSM(G,i);               //以Vi为源点开始DFS搜索
}
//===========BFS：广度优先遍历=======
void BFS(MGraph *G,int k)
{                //以Vk为源点对用邻接矩阵表示的图G进行广度优先搜索
    int i,j,f=0,r=0;
    int cq[MaxVertexNum];        //定义队列   
    for(i=0;i<G->n;i++)
visited[i]=FALSE;         //标志向量初始化
    for(i=0;i<=G->n;i++)
cq[i]=-1;                    //队列初始化
    printf("%c",G->vexs[k]);     //访问源点Vk
    visited[k]=TRUE;
    cq[r]=k;          //Vk已访问，将其入队。注意，实际上是将其序号入队
    while(cq[f]!=-1) {          //队非空则执行
     i=cq[f]; f=f+1;             //Vf出队
     for(j=0;j<G->n;j++)         //依次Vi的邻接点Vj
         if(G->edges[i][j]==1 && !visited[j]) {  //Vj未访问 以下三行代码有一处错误
         printf("%c",G->vexs[j]);         //访问Vj
         visited[j]=TRUE;
         r=r+1; cq[r]=j;          //访问过Vj入队
         }
    }
}
//==========main=====
void main()
{
    MGraph *G;
    G=(MGraph *)malloc(sizeof(MGraph));   //为图G申请内存空间
    CreatMGraph(G);          //建立邻接矩阵
printf("Print Graph DFS: ");
DFS(G);                  //深度优先遍历
    printf("\n");
    printf("Print Graph BFS: ");
    BFS(G,3);             //以序号为3的顶点开始广度优先遍历
    printf("\n");}


//.邻接链表作为存储结构程序示例
#include"stdio.h"
#include"stdlib.h"
#define MaxVertexNum 50          //定义最大顶点数
typedef struct node{       //边表结点
     int adjvex;           //邻接点域
     struct node *next;    //链域
}EdgeNode;
typedef struct vnode{      //顶点表结点
    char vertex;           //顶点域
    EdgeNode *firstedge;   //边表头指针
}VertexNode;
typedef VertexNode AdjList[MaxVertexNum];         //AdjList是邻接表类型
typedef struct {
    AdjList adjlist;       //邻接表
    int n,e;               //图中当前顶点数和边数
} ALGraph;                 //图类型
//=========建立图的邻接表=======
void CreatALGraph(ALGraph *G)
{
     int i,j,k;
     char a;
     EdgeNode *s;           //定义边表结点
     printf("Input VertexNum(n) and EdgesNum(e): ");
     scanf("%d,%d",&G->n,&G->e);       //读入顶点数和边数
     scanf("%c",&a);
     printf("Input Vertex string:");
     for(i=0;i<G->n;i++)         //建立顶点表
     {
		scanf("%c",&a);
		G->adjlist[i].vertex=a;       //读入顶点信息
		G->adjlist[i].firstedge=NULL;  //边表置为空表
     }
     printf("Input edges,Creat Adjacency List\n");
     for(k=0;k<G->e;k++) {        //建立边表
		scanf("%d%d",&i,&j);          //读入边（Vi，Vj）的顶点对序号
		s=(EdgeNode *)malloc(sizeof(EdgeNode));    //生成边表结点
		s->adjvex=j;                  //邻接点序号为j
		s->next=G->adjlist[i].firstedge;
		G->adjlist[i].firstedge=s;     //将新结点*S插入顶点Vi的边表头部
		s=(EdgeNode *)malloc(sizeof(EdgeNode));
		s->adjvex=i;                   //邻接点序号为i
		s->next=G->adjlist[j].firstedge;
		G->adjlist[j].firstedge=s;      //将新结点*S插入顶点Vj的边表头部
     }
}
//=========定义标志向量，为全局变量=======
typedef enum{FALSE,TRUE} Boolean;
Boolean visited[MaxVertexNum];
//========DFS：深度优先遍历的递归算法======
void DFSM(ALGraph *G,int i)
{                         //以Vi为出发点对邻接链表表示的图G进行DFS搜索
    EdgeNode *p;
    printf("%c",G->adjlist[i].vertex);    //访问顶点Vi
    visited[i]=TRUE;                      //标记Vi已访问
    p=G->adjlist[i].firstedge;            //取Vi边表的头指针
while(p) {                  //依次搜索Vi的邻接点Vj，这里j=p->adjvex
//以下3行代码有一处错误
		if(! visited[p->adjvex])      //若Vj尚未被访问
		    dFSM(G,p->adjvex);        //则以Vj为出发点向纵深搜索
			p=p->next;                //找Vi的下一个邻接点
    }
}
void DFS(ALGraph *G)
{
    int i;
    for(i=0;i<G->n;i++)
	visited[i]=FALSE;             //标志向量初始化
    for(i=0;i<G->n;i++)
	if(!visited[i])               //Vi未访问过
	    DFSM(G,i);                //以Vi为源点开始DFS搜索
}
//==========BFS：广度优先遍历=========
void BFS(ALGraph *G,int k)
{                          //以Vk为源点对用邻接链表表示的图G进行广度优先搜索
    int i,f=0,r=0;
    EdgeNode *p;
    int cq[MaxVertexNum];         //定义FIFO队列
    for(i=0;i<G->n;i++)
		visited[i]=FALSE;	         //标志向量初始化
    for(i=0;i<=G->n;i++)
		cq[i]=-1;                          //初始化标志向量
    printf("%c",G->adjlist[k].vertex); //访问源点Vk
    visited[k]=TRUE;
    cq[r]=k;           //Vk已访问，将其入队。注意，实际上是将其序号入队
while(cq[f]!=-1) 
{   //队列非空则执行
		i=cq[f]; f=f+1;                //Vi出队
		p=G->adjlist[i].firstedge;     //取Vi的边表头指针
		while(p) 
{                //依次搜索Vi的邻接点Vj（令p->adjvex=j）
	   		if(!visited[p->adjvex]) {           //若Vj未访问过
			printf("%c",G->adjlist[p->adjvex].vertex);      //访问Vj
			visited[p->adjvex]=TRUE;
//以下3行代码有一处错误
			r=r+1; cq[r]=p->adjvex;            //访问过的Vj入队
		 	}
	    p=p->next;               //找Vi的下一个邻接点
	}
    }//endwhile
}
//==========主函数===========
void main()
{
    int i;
    ALGraph *G;
    G=(ALGraph *)malloc(sizeof(ALGraph));
    CreatALGraph(G);
    printf("Print Graph DFS: ");
    DFS(G);
    printf("\n");
    printf("Print Graph BFS: ");
    BFS(G,3);
    printf("\n");
}