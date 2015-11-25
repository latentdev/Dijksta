#pragma once
#include "Graph.h"
#include <string>

/************************************************************************
*Methods:
*	void Driver()
		starting point of program.

*	void Dijkstra(Graph<string,int>*x, int source, int destination)
		takes the starting and ending points and a graph to perform the algorithm on. then it creates the necessary data structures for the algorithm and calls dijkstraDistance and dijkstraCost.

*	bool Menu(vector<airport*> x, Graph<string, int>*y)
		displays a menu and takes input then calls Dijkstra

*	void InitializeArrays(int *distance, int *predecessor, int size)
		fills the passed in arrays with INT_MAX

*	int FindIndex(Vertex<string, int>*x, vector<Vertex<string, int>*>* vertices)
		returns the corresponding index of a given vertex in a vector of vertices

*	int MinDistance(int *dist, vector<Vertex<string, int>*>* vertices, int size)
		returns the index of of the shortest path.

*	bool AllProcessed(vector<Vertex<string, int>*>* vertices)
		checks if all the vertices have been processed.

*	void DijkstraDistance(vector<Vertex<string, int>*>* vertices, int source, int destination)
		dijkstra's algorithm calculating distance.

*	void DijkstraCost(vector<Vertex<string, int>*>* vertices, int source, int destination)
		dijkstra's algorithm calculating cost.

*	void Reset(vector<Vertex<string, int>*>* vertices)
		resets all the vertices in the vector of vertices processed bool to false.

*************************************************************************/

void Driver();
void Dijkstra(Graph<string,int>*x, int source, int destination);
bool Menu(vector<airport*> x, Graph<string, int>*y);
void InitializeArrays(int *distance, int *predecessor, int size);
int FindIndex(Vertex<string, int>*x, vector<Vertex<string, int>*>* vertices);
int MinDistance(int *dist, vector<Vertex<string, int>*>* vertices, int size);
bool AllProcessed(vector<Vertex<string, int>*>* vertices);
void DijkstraDistance(vector<Vertex<string, int>*>* vertices, int source, int destination);
void DijkstraCost(vector<Vertex<string, int>*>* vertices, int source, int destination);
void Reset(vector<Vertex<string, int>*>* vertices);