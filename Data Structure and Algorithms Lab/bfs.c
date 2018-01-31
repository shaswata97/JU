#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define MAX 1000
typedef struct graph
{
  int V;
  int* M;
}graph;

graph* createGraph(int V)
{
    graph* G = malloc(sizeof(graph));
    G->V = V;
    G->M =(int*)malloc((V)*(V)*sizeof(int));
    return G;
}

void BFS(graph* G,int s)
{
	int i,j,u1,u2;
	queue q;
	int visited[G->V];
	for(i=0;i<G->V;i++)
	{
		visited[i]=0;
	}
	q=init_q(q);
	enqueue(q,s);
	do
	{
		u1 = dequeue(q);
		if (!(visited[u1])) 
		{
			printf("%d\t",u1); 
			visited[u1] = 1;
		}
		for (u2=0;u2<G->V;u2++)
		{
			if (!(visited[u2])&&(G->M[u2*G->V+u1]!=0||G->M[u1*G->V+u2]!=0)) 
			{
				enqueue(q,u2);
			}
		}
	}while (!empty_q(q));
}

int main()
{
	int V,i,j;
    printf("Enter the no of vertices: ");
    scanf("%d",&V);
    graph* G=createGraph(V);
    for(i=0;i<G->V;i++)
    {
    	G->M[i*V+i]=0;
    	for(j=0;j<i;j++)
    	{
    		G->M[i*V+j]=G->M[j*V+i];
    	}

	    for(j=i+1;j<G->V;j++)
	    {
	    	printf("Enter the weight of edge %d--%d[if no edge enter 0]= ",i,j);
	        scanf("%d",&G->M[i*V+j]);
	   	}
    }
    BFS(G,2);
}