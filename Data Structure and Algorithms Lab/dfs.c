#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define MAX 1000


typedef struct graph
{
  int V;
  int* M;
}Graph;

Graph* createGraph(int V);
void dfs(Graph* g,int s);

//Main function
int main()
{
	int V,i,j;
    printf("Enter the no of vertices: ");
    scanf("%d",&V);
    Graph* G=createGraph(V);
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
	        //printf("%d\n",graph->V);
	   	}
    }
    dfs(G,2);
    return 0;
}

//Function to create graph with V vertices
Graph* createGraph(int V)
{
    Graph* graph = malloc(sizeof(Graph));
    graph->V = V;
    graph->M =(int*)malloc((V)*(V)*sizeof(int)); 
    return graph;
}

// //Function to perform depth first search
// void dfs(Graph* g){
// 	int i;
// 	int visited[g->V];
// 	for(i=0;i<g->V;i++)
// 		visited[i]=0;

// 	for(i=0;i<g->V;i++)
// 		if(visited[i]==0)
// 			dfs_visit(g,i,visited);
// }

// //function to visit via dfs
// void dfs_visit(Graph* G,int u,int* visited){
// 	visited[u]=-1; //When vertex u has just been discovered
// 	int i;
// 	for(i=0;i<G->V;i++){
// 		if (((visited[i])==0)&&(G->M[i*G->V+u]!=0||G->M[u*G->V+i]!=0)) //Check if node is adjacent or not
// 			{
// 				printf("%d ",u);
// 				dfs_visit(G,i,visited);
// 			}
// 		}
// 	visited[u]=1;

// }

void dfs(Graph* G,int s){
	int i,j,u1,u2;
	stack vertex;
	int visited[G->V];

	for(i=0;i<G->V;i++){
		visited[i]=0;
	}

	vertex=init_stack();
	push(vertex,s);

	// for(i=0;i<G->V;i++)
	// {
	// 	for(j=0;j<G->V;j++)
	// 		printf("*%d\t", G->M[i*G->V+j]);
	// 	printf(" \n");
	// }

	do{
		u1=pop(vertex);
		if(!visited[u1]){
			printf("%d ",u1);
			visited[u1]=1;
		}

		for(u2=0;u2<G->V;u2++){
			// printf("$%d\n",G->M[u2*G->V+u1] );
			if (!(visited[u2])&&(G->M[u2*G->V+u1]!=0||G->M[u1*G->V+u2]!=0)) 
			{
				// printf(">%d\n",u2);
				push(vertex,u2);
				// prints(vertex);
			}
		}
	}
	while(!s_empty(vertex));
}