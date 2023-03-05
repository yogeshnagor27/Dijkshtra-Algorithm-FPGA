// A C++ program for Dijkstra's single source shortest path algorithm.
// The program is for adjacency matrix representation of the map

#include <limits.h>
#include <stdio.h>
#include <string.h>
#include "dijkshtra.h"

#define V 8
// Function that implements Dijkstra's single source shortest path algorithm
// for a map represented using adjacency matrix representation
void dijkshtra(int* a, int* res)
{
#pragma HLS INTERFACE m_axi port = a  offset = slave bundle = gemm1
#pragma HLS INTERFACE m_axi port = res  offset = slave bundle = gemm2
#pragma HLS INTERFACE s_axilite port = return

	int map[V][V];
	int src = 0;
	memcpy(&map[0][0], const_cast<int*>(a), sizeof(int) * V * V);

	int dist[V]; // The output array. dist[i] will hold the shortest
	// distance from src to i

	bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest
	// path tree or shortest distance from src to i is finalized

	// Initialize all distances as INFINITE and stpSet[] as false
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	// Distance of source vertex from itself is always 0
	dist[src] = 0;

	// Find shortest path for all vertices
	for (int count = 0; count < V - 1; count++) {
		// Pick the minimum distance vertex from the set of vertices not
		// yet processed. u is always equal to src in the first iteration.

		// Calculate Mi
		int min = INT_MAX, min_index;

		for (int v = 0; v < V; v++)
			if (sptSet[v] == false && dist[v] <= min)
				min = dist[v], min_index = v;

		int u = min_index;

		// Mark the picked vertex as processed
		sptSet[u] = true;

		// Update dist value of the adjacent vertices of the picked vertex.
		for (int v = 0; v < V; v++)

			// Update dist[v] only if is not in sptSet, there is an edge from
			// u to v, and total weight of path from src to v through u is
			// smaller than current value of dist[v]
			if (!sptSet[v] && map[u][v] && dist[u] != INT_MAX
					&& dist[u] + map[u][v] < dist[v])
				dist[v] = dist[u] + map[u][v];
	}

	memcpy(const_cast<int*>(res), const_cast<int*>(&dist[0]), sizeof(int) * V);

}


