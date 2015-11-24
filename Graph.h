#pragma once
#include <list>
#include <queue>
#include "Vertex.h"
#include "Edge.h"
#include "airport.h"
/************************************************************************
*Class: Graph
*
*Data Members:
*	list<Vertex<V,E>> vertices
		list of vertices in the graph

*	int count
		count of vertices in the graph

*Constructors:
*	Graph()
		default constructor. sets count to zero.

*	~Graph()
		destructor for Graph.

*Mutators:
*	Vertex<V, E> VerticesBegin()
		returns the head of vertices.

*	Vertex<V, E> VerticesEnd()
		returns the tail of vertices.

*	list<Vertex<V, E>> getVertices()
		returns vertices.

*Methods:
*	void InsertVertex(V data)
		creates a new Vertex and pushes it into vertices.

*	void DeleteVertex(V data);
		finds the vertex that contains data and removes it and all it's arcs.

*	void InsertArc(V from, V to, E edge)
		adds an arc from from to to.

*	void DeleteArc(V from, V to, E edge)
		removes the designated arc.

*	bool isEmpty()
		determines if the list is empty.

*	void DepthFirst(V vert)
		performs a Depth First traversal of the graph.

*	void BreadthFirst(V vert)
		performs a Breadth First Traversal of the graph.

*	void FillGraph(int size)
		fills the graph with integers. Used to showcase the graph for this assignment.

*	void Reset()
		walks throught the vertices and resets their processed bool to false. used to reset state for next traversal.

*************************************************************************/

template<typename V, typename E>
class Graph
{
private:
	std::list<Vertex<V,E>>  vertices;
	int count;
public:
	Graph();
	~Graph();

	void InsertVertex(V data);
	void DeleteVertex(V data);
	void InsertArc(V from, V to, int cost, int distance);
	void DeleteArc(V from, V to, E edge);
	bool isEmpty();
	Vertex<V, E> VerticesBegin();
	Vertex<V, E> VerticesEnd();
	list<Vertex<V, E>> getVertices();

	void DepthFirst(V vert);
	void BreadthFirst(V vert);

	void FillGraph(int size);
	void FillGraph(vector<airport*> x);
	void Reset();

};
#include "Graph.cpp"


