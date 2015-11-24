#pragma once
#include <list>
#include <vector>
/************************************************************************
*Class: Vertex
*
*Data Members:
*	V data
		data to be stored.

*	int indegree
		number of arcs coming into this vertex.

*	int outdegree
		number of arcs coming out of this vertex.

*	bool processed
		state of the vertex(whether it has been processed or not).

*	std::list<Edge<V,E>> edges
		list of edges coming from this vertex.

*Constructors:
*	Vertex()
		default constructor. sets all data members to 0. private so it is not used. vertex should only be created using data.

*	Vertex(V in_data)
		creates a new Vertex setting data to the passed in data and initializes other data members.

*	~Vertex()
		destructor for Vertex.

*Mutators:
*	V getData()
		returns data.

*	bool getProcessed()
		returns processed.

*	void setProcessed(bool in_processed)
		sets processed to the passed in bool.
		
*	std::list<Edge<V,E>>* getEdges()
		returns edges.

*Methods:
*	void addEdge(Edge<V, E> edge)
		pushes the passed in edge into edges and increments out and in degrees.

*************************************************************************/
template<typename V, typename E> class Edge;
template<typename V,typename E>
class Vertex
{
private:
	V data;
	int indegree;
	int outdegree;
	bool processed;
	std::vector<Edge<V,E>*> edges;

	Vertex();
public:
	Vertex(V in_data);
	~Vertex();
	V getData();
	bool getProcessed();
	void setProcessed(bool in_processed);
	std::vector<Edge<V,E>*>* getEdges();
	void addEdge(Edge<V, E> *edge);
};
#include "Vertex.cpp"


