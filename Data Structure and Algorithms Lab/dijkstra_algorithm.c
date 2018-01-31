// A C++ program for Dijkstra's single source shortest path algorithm.
// The program is for adjacency matrix representation of the graph
  
#include <stdio.h>
#include <float.h>
#include <stdlib.h>  
// Number of vertices in the graph
//#define V 9
#define MAX 1000
typedef struct graph
{
  int V;
  double* M;
}graph;

graph* createGraph(int V)
{
    graph* graph = malloc(sizeof(graph));
    //struct Graph* graph;
    graph->V = V;
    graph->M =(double*)malloc((V)*(V)*sizeof(double));
 
    return graph;
}
// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(double dist[], int sptSet[],graph* graph)
{
   // Initialize min value
   double min = DBL_MAX;int min_index;
  
   for (int v = 0; v < graph->V; v++)
     if (sptSet[v] == 0 && dist[v] <= min)
      {
        min = dist[v];
        min_index = v;
      }
   return min_index;
}
  
// A utility function to print the constructed distance array
int printSolution(double dist[], graph* graph)
{
   printf("Vertex   Distance from Source\n");
   for (int i = 0; i < graph->V; i++)
      printf("%d \t\t %lf\n", i, dist[i]);
}
  
// Funtion that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(graph* graph, int src)
{
     double dist[graph->V];     // The output array.  dist[i] will hold the shortest
                      // distance from src to i
  
     int sptSet[graph->V]; // sptSet[i] will 0 if vertex i is included in shortest
                     // path tree or shortest distance from src to i is finalized
  
     // Initialize all distances as INFINITE and stpSet[] as 0
     for (int i = 0; i < graph->V; i++)
     {
        dist[i] = DBL_MAX;
        sptSet[i] = 0;
     }
  
     // Distance of source vertex from itself is always 0
     dist[src] = 0;
  
     // Find shortest path for all vertices
     for (int count = 0; count < graph->V-1; count++)
     {
       // Pick the minimum distance vertex from the set of vertices not
       // yet processed. u is always equal to src in first iteration.
       int u = minDistance(dist, sptSet,graph);
  
       // Mark the picked vertex as processed
       sptSet[u] = 1;
  
       // Update dist value of the adjacent vertices of the picked vertex.
       for (int v = 0; v < graph->V; v++)
  
         // Update dist[v] only if is not in sptSet, there is an edge from 
         // u to v, and total weight of path from src to  v through u is 
         // smaller than current value of dist[v]
         if (!sptSet[v] && graph->M[u*graph->V+v] && dist[u] != DBL_MAX 
                                       && dist[u]+graph->M[u*graph->V+v] < dist[v])
            dist[v] = dist[u] + graph->M[u*graph->V+v];
     }
  
     // print the constructed distance array
     printSolution(dist, graph);
}
  
// driver program to test above function
int main()
{
   /* Let us create the example graph discussed above */
    int V,i,j;
    printf("Enter the no of vertices: ");
    scanf("%d",&V);
    graph* graph=createGraph(V);
    // graph->M[] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
    //                   {4, 0, 8, 0, 0, 0, 0, 11, 0},
    //                   {0, 8, 0, 7, 0, 4, 0, 0, 2},
    //                   {0, 0, 7, 0, 9, 14, 0, 0, 0},
    //                   {0, 0, 0, 9, 0, 10, 0, 0, 0},
    //                   {0, 0, 4, 14, 10, 0, 2, 0, 0},
    //                   {0, 0, 0, 0, 0, 2, 0, 1, 6},
    //                   {8, 11, 0, 0, 0, 0, 1, 0, 7},
    //                   {0, 0, 2, 0, 0, 0, 6, 7, 0}
    //                  };
    for(i=0;i<graph->V;i++)
    {
      for(j=0;j<graph->V;j++)
      {
        // printf("Enter the weight of edge %d--%d[if no edge enter 0]= ",i,j);
        scanf("%lf",&graph->M[i*V+j]);
        //printf("%d\n",graph->V);
      }
    }
    dijkstra(graph, 0);
  
    return 0;
}