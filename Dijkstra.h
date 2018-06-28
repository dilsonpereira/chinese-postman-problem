#pragma once

#include "./Matching/Graph.h"
#include "./Matching/BinaryHeap.h"
#include "./Matching/Globals.h"

//Dijkstra's algorithm using binary heap
//Returns a pair (vector, double)
//The double is the cost of the solution
//The vector gives the parent of each vertex in the tree of optimal paths
pair< vector<int>, double > Dijkstra(const Graph & G, int origin, const vector<double> & cost)
{
	BinaryHeap B;

	int n = G.GetNumVertices();

	//Father of each vertex in the optimal path tree
	vector<int> father(n, -1);

	//Used to indicate whether a vertex is permanently labeled
	vector<bool> permanent(n, false);

	double obj = 0;
	
	//Put s in the heap
	B.Insert(0, s);

	for(int i = 0; i < n; i++)
	{
		//Select the vertex that can be reached with smallest cost
		int u = B.DeleteMin();
		int w = father[u];

		permanent[u] = true;

		//Update the heap with vertices adjacent to u
		for(list<int>::const_iterator it = G.AdjList(u).begin(); it != G.AdjList(u).end(); it++)
		{
			int v = *it;
			
			if(permanent[v])
				continue;

			double c = cost[G.GetEdgeIndex(u,v)];

			//v has not been discovered yet
			if(father[v] == -1)
			{
				father[v] = u;	
				B.Insert(c, v);
			}
			//we found a cheaper connection to v
			else if( LESS(c, cost[G.GetEdgeIndex(father[v], v)]) )
			{
				father[v] = u;
				B.ChangeKey(c, v);
			}
		}
	}

	if(B.Size() > 0)
		throw "Error: graph is not connected";

	return make_pair(father, obj);
}



