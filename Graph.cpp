#include "Graph.h"
#include <iterator>
#include "airport.h"

/******************************************************
*   Purpose:  Default constructor. 

*         Entry:  none

*         Exit: sets count to zero.
*******************************************************/
template<typename V, typename E>
inline Graph<V, E>::Graph()
{
	count = 0;
}

/******************************************************
*   Purpose:  destructor.

*         Entry:  none

*         Exit: clears the list of vertices.
*******************************************************/
template<typename V, typename E>
Graph<V, E>::~Graph()
{
	vertices.clear();
}

/******************************************************
*   Purpose:  inserts an arc between two vertices

*         Entry:  passed in 2 vertices to connect with an arc.

*         Exit: finds the two vertices to be connected and stores them in pointers. then creates two new edges using the pointers.
				adds each edge to their respective edge list.
*******************************************************/
template<typename V, typename E>
void Graph<V, E>::InsertArc(V from, V to, int cost, int distance)
{
	Vertex<V, E> * temp=0;
	Vertex<V, E> * temp2=0;
	list<Vertex<V,E>>::iterator vert_iter;
	for (vert_iter = vertices.begin(); vert_iter!=vertices.end(); ++vert_iter)
	{
		if (vert_iter->getData() == from)
			temp = &(*vert_iter);
	}
	for (vert_iter = vertices.begin(); vert_iter != vertices.end(); ++vert_iter)
	{
		if (vert_iter->getData() == to)
			temp2 = &(*vert_iter);
	}
	Edge<V, E> *temp3 = new Edge<V, E>(temp, temp2, distance,cost);
	Edge<V, E> *temp4 = new Edge<V, E>(temp2, temp, distance,cost);
	temp->addEdge(temp3);
	temp2->addEdge(temp4);
}

/******************************************************
*   Purpose:  removes the designated arc

*         Entry:  two vertices to remove the arc between.

*         Exit: finds the first vertex then walks through it's list of edges looking for the one that connects to the other vertex.
				once found deletes that edge from both verices list of edges.
*******************************************************/
template<typename V, typename E>
void Graph<V, E>::DeleteArc(V from, V to, E edge)
{
	Vertex<V, E> * temp = 0;
	list<Vertex<V, E>>::iterator vert_iter;
	for (vert_iter = vertices.begin(); vert_iter != vertices.end(); ++vert_iter)
	{
		if (vert_iter->getData() == from)
		{
			list<Edge<V, E>>* temp2 = vert_iter->getEdges();
			list<Edge<V, E>>::iterator edge_iter;
			for (edge_iter = temp2->begin(); edge_iter != temp2->end(); ++edge_iter)
			{
				if (edge_iter->getDestination2()->getData()==to)
				{
					temp2->erase(edge_iter);
					break;
				}
			}
		}
	}

	for (vert_iter = vertices.begin(); vert_iter != vertices.end(); ++vert_iter)
	{
		if (vert_iter->getData() == to)
		{
			list<Edge<V, E>>* temp2 = vert_iter->getEdges();
			list<Edge<V, E>>::iterator edge_iter;
			for (edge_iter = temp2->begin(); edge_iter != temp2->end(); ++edge_iter)
			{
				if (edge_iter->getDestination2()->getData() == from)
				{
					temp2->erase(edge_iter);
					break;
				}
			}
		}
	}
}

/******************************************************
*   Purpose:  inserts a Vertex with the given data

*         Entry:  passed in data

*         Exit: creates a new Vertex with the passed in data and pushes it into the list of vertices. increases the count of vertices.
*******************************************************/
template<typename V, typename E>
void Graph<V, E>::InsertVertex(V data)
{
	Vertex<V, E> * temp = new Vertex<V, E>(data);
	vertices.push_back(*temp);
	count++;
}

/******************************************************
*   Purpose:  remove the given vertex.

*         Entry:  passed in a vertex

*         Exit: find the vertex with the given data remove all the edges connected to it. and remove the vertex.
*******************************************************/
template<typename V, typename E>
void Graph<V, E>::DeleteVertex(V data)
{
	Vertex<V, E> * temp = 0;
	list<Vertex<V, E>>::iterator vert_iter;
	for (vert_iter = vertices.begin(); vert_iter != vertices.end(); ++vert_iter)
	{
		if (vert_iter->getData() == data)
		{
			list<Edge<V, E>>* temp2 = vert_iter->getEdges();
			list<Edge<V, E>>::iterator edge_iter;
			edge_iter = temp2->begin();
			while(temp2->size()!=0)
				DeleteArc(edge_iter->getDestination1()->getData(), edge_iter->getDestination2()->getData(), 0);
		}
	}
}

/******************************************************
*   Purpose:  determine if the graph is empty.

*         Entry:  none

*         Exit: checks the size of the vertices list. if 0 then return true else false.
*******************************************************/
template<typename V, typename E>
bool Graph<V, E>::isEmpty()
{
	if (vertices.size() == 0)
		return true;
	else
		return false;
}

/******************************************************
*   Purpose:  get the head to the vertices list.

*         Entry:  none

*         Exit: returns the head of the vertices list.
*******************************************************/
template<typename V, typename E>
Vertex<V, E> Graph<V, E>::VerticesBegin()
{
	return vertices.begin();
}

/******************************************************
*   Purpose:  get the tail to the vertices list.

*         Entry:  none

*         Exit: returns the tail of the vertices list.
*******************************************************/
template<typename V, typename E>
Vertex<V, E> Graph<V, E>::VerticesEnd()
{
	return vertices.end();
}

/******************************************************
*   Purpose:  get the vertices list.

*         Entry:  none

*         Exit: returns the vertices list.
*******************************************************/
template<typename V, typename E>
list<Vertex<V, E>> Graph<V, E>::getVertices()
{
	return vertices;
}

/******************************************************
*   Purpose:  depth first traversal of the graph starting at the passed in vertex.

*         Entry:  passed in a vertex to start from.

*         Exit: recursive function. find the vertex. then if it hasn't been processed output it and call depth first on it's child.
*******************************************************/
template<typename V, typename E>
void Graph<V, E>::DepthFirst(V vert)
{
	Vertex<V, E> * temp = 0;
	list<Vertex<V, E>>::iterator vert_iter;
	for (vert_iter = vertices.begin(); vert_iter != vertices.end(); ++vert_iter)
	{
		if (vert_iter->getData() == vert)
			temp = &(*vert_iter);
	}
	if (temp->getProcessed() == false)
	{
		temp->setProcessed(true);
		cout << temp->getData() << ",";
		vector<Edge<V, E>*>* temp2 = temp->getEdges();
		//vector<Edge<V, E>*>::iterator edge_iter;
		for (int i=0; i<temp2->size(); i++)
		{
			if ((*temp2)[i]->getDestination2()->getProcessed() == false)
				DepthFirst((*temp2)[i]->getDestination2()->getData());
		}
		return;
	}
}

/******************************************************
*   Purpose:  Breadth first traversal of the graph starting from the given vertex.

*         Entry:  passed in a vertex to start from.

*         Exit: find the vertex. the push it into a queue. then while the queue is not empty we pop off the queue, 
				output the data, and push the vertex's children into the queue if they haven't already been processed.
*******************************************************/
template<typename V, typename E>
void Graph<V, E>::BreadthFirst(V vert)
{
	queue<Vertex<V,E>*>* que = new queue<Vertex<V, E>*>();
	Vertex<V, E> * temp = 0;
	list<Vertex<V, E>>::iterator vert_iter;
	for (vert_iter = vertices.begin(); vert_iter != vertices.end(); ++vert_iter)
	{
		if (vert_iter->getData() == vert)
			temp = &(*vert_iter);
	}
	temp->setProcessed(true);
	que->push(temp);
	while (!que->empty())
	{
		temp = (que->front());
		que->pop();
		cout << temp->getData() << ",";
		list<Edge<V, E>>* temp2 = temp->getEdges();
		list<Edge<V, E>>::iterator edge_iter;
		for (edge_iter = temp2->begin(); edge_iter != temp2->end(); ++edge_iter)
		{
			if (edge_iter->getDestination2()->getProcessed() == false)
			{
				que->push((edge_iter->getDestination2()));
				edge_iter->getDestination2()->setProcessed(true);
			}
		}

	}
	delete que;
}

/******************************************************
*   Purpose:  fill the graph with integers

*         Entry:  a size for the graph

*         Exit: keeps inserting vertices till the graph has hit the size limit.
*******************************************************/
template<typename V, typename E>
inline void Graph<V, E>::FillGraph(int size)
{
	for (int i = 0; i < size; i++)
		InsertVertex(i);
}

template<typename V,typename E>
inline void Graph<V, E>::FillGraph(vector<airport*>  x)
{
	for (int i = 0; i < x.size(); i++)
	{
		InsertVertex((*x[i]).name);
	}
	for (int i = 0; i < x.size(); i++)
	{
		if (x[i]->flights->size()>0)
			for (int m = 0; m < x[i]->flights->size(); m++)
			{
				vector<connection*> temp = *(x[i]->flights);
				InsertArc(x[i]->name, temp[m]->name, temp[m]->cost, temp[m]->distance);
			}
	}
}

/******************************************************
*   Purpose:  reset the processed state of the graph

*         Entry:  none

*         Exit: walk through the list setting all the vertices processed to false.
*******************************************************/
template<typename V, typename E>
void Graph<V, E>::Reset()
{
	Vertex<V, E> * temp = 0;
	list<Vertex<V, E>>::iterator vert_iter;
	for (vert_iter = vertices.begin(); vert_iter != vertices.end(); ++vert_iter)
	{
			temp = &(*vert_iter);
			temp->setProcessed(false);
	}
}
