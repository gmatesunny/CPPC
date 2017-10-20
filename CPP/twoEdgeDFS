// twoEdgeDFS.cpp : Defines the entry point for the console application.
// Copied from http://www.geeksforgeeks.org/bridge-in-a-graph/

// An edge is a bridge if low[v] > discovery_time[u], where u is parent of v in DFS graph
// Revision Planned


#include "stdafx.h"
#include <iostream>
#include <list>
#include <algorithm>

#define NIL -1
using namespace std;


class Graph
{
	int V; //no. of vertices
	list<int> *adj;
	void bridgeUtil(int v,
		bool visited[],
		int disc[],
		int low[],
		int parent[]);
public:
	Graph(int V);
	void addEdge(int v, int w);
	void bridge();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
	adj[w].push_back(v);
}

// A recursive function that finds and prints bridges using DFS traversal
// u: vertex to be visited next
void Graph::bridgeUtil(int u, bool visited[],
	int disc[], int low[], int parent[])
{
	static int time = 0;
	visited[u] = true;
	disc[u] = low[u] = ++time;

	list<int>::iterator it;
	for (it = adj[u].begin(); it != adj[u].end(); ++it)
	{
		int v = *it;

		if (!visited[v])
		{
			parent[v] = u;
			//recursive call for not visited v 
			bridgeUtil(v, visited, disc, low, parent);

			// Check if the subtree rooted with v has a 
			// connection to one of the ancestors of u, notice u
			low[u] = min(low[u], low[v]); 

			if (low[v] > disc[u])
				cout << u << " " << v << endl;
		}
		//update low value of u for parent functional call
		else if (v != parent[u])
			low[u] = min(low[u], disc[v]);
	}
}

void Graph::bridge()
{
	bool *visited = new bool[V];
	int *parent = new int[V];
	int *disc = new int[V];
	int *low = new int[V];

	for (int i = 0; i < V; i++)
	{
		parent[i] = NIL;
		visited[i] = false;
	}

	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			bridgeUtil(i, visited, disc, low, parent);
}
int main()
 {
	Graph g1(5);
	g1.addEdge(1, 0);
	g1.addEdge(0, 2);
	g1.addEdge(2, 1);
	g1.addEdge(0, 3);
	g1.addEdge(3, 4);
	g1.bridge();
	getchar();
	return 0;
}

