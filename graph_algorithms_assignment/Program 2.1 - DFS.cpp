#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	int vertex;
	struct node *next;
};
struct graph
{
	int v,e;
	struct node **adj;
};

int bs(int a[], int n, int item)
{
	int i;
	for(i=0;i<=n;i++)
		if(item == a[i])
			return 10;
			
	return -1;
}

int count = -1;

void DFS(struct graph *g, int dfs[], int start)
{
	struct node *p = g->adj[start];
	
	if( bs(dfs, count, p->vertex)== -1 )   // Item not exists , so need to be added
	{
		count = count+1;
		dfs[count] = start;
	}
	
	while(p!=NULL)
	{
		if( bs(dfs, count, p->vertex)== -1 )
			DFS(g, dfs, p->vertex);
			
		else if( bs(dfs, count, p->vertex)== 10 )
			p = p->next;
	}
}

//************************************************************************************************************
//                                 MAIN  FUNCTION
//************************************************************************************************************

main()
{
	struct graph *g = (struct graph *)malloc( sizeof(struct graph));
	
	printf("\n  How many vertices in graph : ");
	scanf("%d",&g->v);
	printf("\n  How many edges in graph : ");
	scanf("%d",&g->e);
	
	g->adj = (struct node **)malloc(g->v * sizeof(struct node));
	
	int i;
	for(i=0; i< g->v;i++)
	{
		struct node *temp = (struct node *)malloc(sizeof(struct node));
		temp->vertex = i;
		temp->next = NULL;
		g->adj[i] = temp;
	}
	
	for(i=0; i< g->e;i++)
	{
		int u,v;
		printf("\n\n	Edge %d :  ",i+1);
			printf("\n		Vertex 1 : ");
			scanf("%d",&u);
			printf("\n		Vertex 2 : ");
			scanf("%d",&v);
		
		struct node *temp = (struct node *)malloc(sizeof(struct node));
		temp->vertex = v;
		temp->next = NULL;
		struct node *p = g->adj[u];
		
		if(p->next == NULL)
			p->next = temp;
		else
		{
			p = p->next;
			if(p->vertex > temp->vertex)
			{
				temp->next = p;
				g->adj[u]->next = temp;
			}
			else
			{
				while(p->next!=NULL && p->next->vertex < temp->vertex)
					p = p->next;
		
				if(p->next == NULL)
					p->next = temp;
			
				if(p->next->vertex > temp->vertex)
				{
					temp->next = p->next;
					p->next = temp;
				}
			}
		
		}
		
/////////////////////////////////////////////////////////////////////////////////////
		
		struct node *temp1 = (struct node *)malloc(sizeof(struct node));
		temp1->vertex = u;
		temp1->next = NULL;
		struct node *p1 = g->adj[v];
		
		if(p1->next == NULL)
			p1->next = temp1;
		else
		{
			p1 = p1->next;
			if(p1->vertex > temp1->vertex)
			{
				temp1->next = p1;
				g->adj[v]->next = temp1;
			}
			else
			{
				while(p1->next!=NULL && p1->next->vertex < temp1->vertex)
					p1 = p1->next;
			
				if(p1->next == NULL)
					p1->next = temp1;	
				if(p1->next->vertex > temp1->vertex)
				{
					temp1->next = p1->next;
					p1->next = temp1;
				}
			}
		}
		
	}
	
	printf("\n\n  Let us see our graph...");
	getch();
	
	for(i=0;i<g->v;i++)
	{
		printf("\n\n	");
		struct node *temp = g->adj[i];
		while(temp!=NULL)
		{
			printf("%d --> ",temp->vertex);
			temp = temp->next;
		}
	}
	
	while(1)
	{
		count = -1;
		printf("\n\n");
		int start;
		printf("\n\n  Starting node for DFS : ");
		scanf("%d",&start);
		printf("\n\n  The DFS starting from %d : ",start);
		
		int v = g->v;	
		int dfs_nodes[v];
		DFS(g, dfs_nodes, start);
	
		for(i=0;i<v;i++)
			printf("	%d",dfs_nodes[i]);
			
		int x;
		printf("\n\n More : ");
	scanf("%d",&x);
	if(x==0)
		break;
	}
}
