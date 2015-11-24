#include "Vertex.h"
#include <list>
using namespace std;

/******************************************************
*   Purpose:  default constructor

*         Entry:  none

*         Exit: sets all data members to 0.
*******************************************************/
template<typename V, typename E>
inline Vertex<V, E>::Vertex()
{
	data = 0;
	indegree = 0;
	outdegree = 0;
}

/******************************************************
*   Purpose:  constructor

*         Entry:  passed in data

*         Exit: sets the data to the passed in data. sets the processed state to false and the in and out degrees to 0.
*******************************************************/
template<typename V, typename E>
Vertex<V, E>::Vertex(V in_data)
{
	data = in_data;
	processed = false;
	indegree = 0;
	outdegree = 0;
}

/******************************************************
*   Purpose:  destructor

*         Entry:  none

*         Exit: clears the list of edges
*******************************************************/
template<typename V, typename E>
Vertex<V, E>::~Vertex()
{
	edges.clear();
}

/******************************************************
*   Purpose:  getter for data

*         Entry:  none

*         Exit: returns data.
*******************************************************/
template<typename V, typename E>
V Vertex<V, E>::getData()
{
	return data;
}

/******************************************************
*   Purpose:  getter for processed

*         Entry:  none

*         Exit: returns processed
*******************************************************/
template<typename V, typename E>
bool Vertex<V, E>::getProcessed()
{
	return processed;
}

/******************************************************
*   Purpose:  setter for processed

*         Entry:  none

*         Exit: sets processed to the passed in value.
*******************************************************/
template<typename V, typename E>
void Vertex<V, E>::setProcessed(bool in_processed)
{
	processed = in_processed;
}

/******************************************************
*   Purpose:  getter for list of edges

*         Entry:  none

*         Exit: returns edges
*******************************************************/
template<typename V, typename E>
inline std::vector<Edge<V, E>*>* Vertex<V, E>::getEdges()
{
	return &edges;
}


/******************************************************
*   Purpose:  adds an edge to the vertex

*         Entry:  passed in an edge

*         Exit: adds the passed in edge to the list of edges and icrements the in and out degrees.
*******************************************************/
template<typename V, typename E>
void Vertex<V, E>::addEdge(Edge<V, E> *edge)
{
	edges.push_back(edge);
	indegree++;
	outdegree++; 
}
