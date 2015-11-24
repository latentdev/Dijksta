#include "Edge.h"

/******************************************************
*   Purpose:  constructor for Edge

*         Entry:  passed in two pointer of vertices to create the edge between

*         Exit: sets destination1 to a and destination2 to b and weight to w.
*******************************************************/
template<typename V, typename E>
inline Edge<V, E>::Edge(Vertex<V, E>* a, Vertex<V, E>* b, int w, int c)
{
	destination1 = a;
	destination2 = b;
	weight = w;
	cost = c;
}


/******************************************************
*   Purpose:  destructor

*         Entry:  none

*         Exit: none
*******************************************************/
template<typename V, typename E>
Edge<V, E>::~Edge()
{
}


/******************************************************
*   Purpose:  getter for weight

*         Entry:  none

*         Exit: returns weight
*******************************************************/
template<typename V, typename E>
int Edge<V, E>::getWeight()
{
	return weight;
}

template<typename V, typename E>
int Edge<V, E>::getCost()
{
	return cost;
}

/******************************************************
*   Purpose:  getter for destination1

*         Entry:  none

*         Exit: returns destination1
*******************************************************/
template<typename V, typename E>
Vertex<V, E>* Edge<V, E>::getDestination1()
{
	return destination1;
}

/******************************************************
*   Purpose:  getter for destination2

*         Entry:  none

*         Exit: returns destination2
*******************************************************/
template<typename V, typename E>
Vertex<V, E>* Edge<V, E>::getDestination2()
{
	return destination2;
}
