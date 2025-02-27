// A C / C++ program for Prim's Minimum Spanning Tree (MST) algorithm. 
// The program is for adjacency matrix representation of the graph
 
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define MAX 1000
typedef struct graph
{
  int V;
  double* M;
}graph;
graph G; 
// Number of vertices in the graph
//#define V 5
 
// A utility function to find the vertex with minimum key value, from
// the set of vertices not yet included in MST
int minKey(int key[], int mstSet[],graph* graph)
{
   // Initialize min value
   int min = INT_MAX, min_index;
 
   for (int v = 0; v < graph->V; v++)
     if (mstSet[v] == 0 && key[v] < min)
         min = key[v], min_index = v;
 
   return min_index;
}
 
// A utility function to print the constructed MST stored in parent[]
int printMST(int parent[],graph* graph)
{
   printf("Edge   Weight\n");
   for (int i = 1; i < graph->V; i++)
      printf("%d - %d    %lf \n", parent[i], i, graph->M[i*graph->V+parent[i]]);
}
 
// Function to construct and print MST for a graph represented using adjacency
// matrix representation
void primMST(graph* graph)
{
     int parent[graph->V]; // Array to store constructed MST
     int key[graph->V];   // Key values used to pick minimum weight edge in cut
     int mstSet[graph->V];  // To represent set of vertices not yet included in MST
 
     // Initialize all keys as INFINITE
     for (int i = 0; i < graph->V; i++)
        key[i] = INT_MAX, mstSet[i] = 0;
 
     // Always include first 1st vertex in MST.
     key[0] = 0;     // Make key 0 so that this vertex is picked as first vertex
     parent[0] = -1; // First node is always root of MST 
 
     // The MST will have V vertices
     for (int count = 0; count < graph->V-1; count++)
     {
        // Pick the minimum key vertex from the set of vertices
        // not yet included in MST
        int u = minKey(key, mstSet,graph);
 
        // Add the picked vertex to the MST Set
        mstSet[u] = 1;
 
        // Update key value and parent index of the adjacent vertices of
        // the picked vertex. Consider only those vertices which are not yet
        // included in MST
        for (int v = 0; v < graph->V; v++)
 
           // graph[u][v] is non zero only for adjacent vertices of m
           // mstSet[v] is false for vertices not yet included in MST
           // Update the key only if graph[u][v] is smaller than key[v]
          if (graph->M[u*graph->V+v] && mstSet[v] == 0 && graph->M[u*graph->V+v] <  key[v])
             parent[v]  = u, key[v] = graph->M[u*graph->V+v];
     }
 
     // print the constructed MST
     printMST(parent,graph);
}
 
graph* createGraph(int V)
{
    graph* graph = malloc(sizeof(graph));
    //struct Graph* graph;
    graph->V = V;
    graph->M =(double*)malloc((V)*(V)*sizeof(double));
 
    return graph;
}
 
// driver program to test above function
int main()
{
   /* Let us create the following graph
          2    3
      (0)--(1)--(2)
       |   / \   |
      6| 8/   \5 |7
       | /     \ |
      (3)-------(4)
            9          */
   // int graph[V][V] = {{0, 2, 0, 6, 0},
   //                    {2, 0, 3, 8, 5},
   //                    {0, 3, 0, 0, 7},
   //                    {6, 8, 0, 0, 9},
   //                    {0, 5, 7, 9, 0},
   //                   };
    int V,i,j;
    printf("Enter the no of vertices: ");
    scanf("%d",&V);
    graph* graph=createGraph(V);
    for(i=0;i<graph->V;i++)
    {
      for(j=0;j<graph->V;j++)
      {
        printf("Enter the weight of edge %d--%d[if no edge enter 0]= ",i,j);
        scanf("%lf",&graph->M[i*V+j]);
        //printf("%d\n",graph->V);
      }
    }
    // Print the solution
    primMST(graph);
 
    return 0;
}