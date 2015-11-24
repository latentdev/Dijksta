#pragma once
#include "Vertex.h"
/************************************************************************
*Class: Edge
*
*Data Members:
*	Vertex<V,E>*destination1
		ponter to the origin vertex.

*	Vertex<V,E>*destination2
		pointer to the destination vertex.

*	int weight
		weigth of the edge. not used in this program, but maybe used in the future.

*Constructors:
*	Edge(Vertex<V,E> *a,Vertex<V,E>* b, int w)
		constructor for Edge. sets the data members to the passed in values.

	~Edge();
		destructor.

*Mutators:
*	int getWeight()
		returns weight.

*	Vertex<V, E>* getDestination1()
		returns a pointer to destination1.
			
*	Vertex<V, E>* getDestination2()
		returns a pointer to destination2.

*Methods:
*	

*************************************************************************/
template<typename V,typename E>
class Edge
{
private:
	Vertex<V,E>*destination1;
	Vertex<V,E>*destination2;
	int weight;
	int cost;
	//E data;
public:
	Edge(Vertex<V,E> *a,Vertex<V,E>* b, int w,int c);
	~Edge();
	int getWeight();
	int getCost();
	Vertex<V, E>* getDestination1();
	Vertex<V, E>* getDestination2();


};
#include "Edge.cpp"


