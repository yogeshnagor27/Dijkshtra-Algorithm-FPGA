#include "dijkshtra.h"
#include <stdio.h>
#include <string.h>
#include <iostream>

// A utility function to print the constructed distance array
void printSolution(int dist[], int V)
{
	printf("Vertex \t\t Distance from Source\n");
	for (int i = 0; i < V; i++)
		printf("%d \t\t %d\n", i, dist[i]);
}

int main()
{
	int V = 8;

	int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8 },
						{ 4, 0, 8, 0, 0, 0, 0, 11 },
						{ 0, 8, 0, 7, 0, 4, 0, 0 },
						{ 0, 0, 7, 0, 9, 14, 0, 0 },
						{ 0, 0, 0, 9, 0, 10, 0, 0 },
						{ 0, 0, 4, 14, 10, 0, 2, 0 },
						{ 0, 0, 0, 0, 0, 2, 0, 1 },
						{ 8, 11, 0, 0, 0, 0, 1, 0 } };

	int dist [V] = {1,0,2,0,0,0,0,0};
	//printf("variable dist is at address: %p\n", (void*)&dist);
	  dijkshtra(&graph[0][0], &dist[0]);
	  //printf("variable dist is at address: %p\n", (void*)&dist);
	// print the constructed distance array
	printSolution(dist, V);

	return 0;
}



