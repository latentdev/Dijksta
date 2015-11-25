#include "Driver.h"
#include "Graph.h"
#include <iostream>
#include "Reader.h"
#include <vector>
#include "airport.h"
#include <string>
#include "Vertex.h"
#include <stack>

using namespace std;

/******************************************************
*   Purpose:  starting point of program

*         Entry:  none

*         Exit: reads from file and creates the graph then displays the menu while it doesn't return true
*******************************************************/
void Driver()
{
	Reader*reader = new Reader();
	reader->ReadFile("airports.txt");
	vector<airport*>x = reader->getAirports();
	Graph<string, int>* a = new Graph<string, int>();
	a->FillGraph(x);
	while (!Menu(x, a)) {}
	cout << endl;
}

/******************************************************
*   Purpose:  starting point for dijkstra

*         Entry:  passed in a graph a starting point and ending point

*         Exit: creates a new vector of vertices with the starting vertex at the start of the vector then calls DijkstraDistance(), resets the processed state of all the vertices, calls DijkstraCost.
*******************************************************/

void Dijkstra(Graph<string, int>*x,int source,int destination)
{
	vector<Vertex<string, int>*>* vertices= new vector<Vertex<string,int>*>;
	list<Vertex<string, int>>::iterator vert_iter;
	list<Vertex<string, int>> temp = x->getVertices();
	vert_iter = temp.begin();
	for (int i = 0; i < source; i++)
		++vert_iter;
	for (int i = 0; i < temp.size(); i++)
	{
		if (vert_iter != temp.end())
		{
			vertices->push_back(&(*vert_iter));
			++vert_iter;
		}
		else
		{
			vert_iter = temp.begin();
			i--;
		}
	};
	int temp_source = source;
	int temp_destination = destination;
	DijkstraDistance(vertices, temp_source, temp_destination);
	Reset(vertices);;
	temp_source = source;
	temp_destination = destination;
	DijkstraCost(vertices, temp_source, temp_destination);

}

/******************************************************
*   Purpose:  displays a menu for selection

*         Entry:  passed in a vector of airports and a graph

*         Exit: displays a menu and accepts input then calls Dijkstra using the input.
*******************************************************/

bool Menu(vector<airport*> x, Graph<string, int>*y)
{
	int source = INT_MAX;
	int destination = INT_MAX;
	for (int i = 0; i < x.size(); i++)
		cout << i+1 << ". " << x[i]->name << endl;
	cout << "8. Exit" << endl;
	while (source > x.size() + 1)
	{
		cout << "Please choose the number that corresponds to desired starting location: ";
		cin >> source;
	}
	if (source == 8 || destination == 8)
		return true;
	while (destination > x.size() + 1)
	{
		cout << endl << "Please choose the number that corresponds to the desired destination: ";
		cin >> destination;
	}
	cout << endl;
	if (source == 8 || destination == 8)
		return true;
	Dijkstra(y, source - 1, destination - 1);
	return false;
}

/******************************************************
*   Purpose:  initialize the passed in arrays

*         Entry:  passed in two int arrays

*         Exit: fills each of the elements of the arrays with INT_MAX
*******************************************************/

void InitializeArrays(int *distance, int *predecessor,int size)
{
	for (int i = 0; i < size; i++)
	{
		distance[i] = INT_MAX;
		predecessor[i] = INT_MAX;
	}
}

/******************************************************
*   Purpose:  find the index of a given vertex

*         Entry:  passed in a vertex and a vecter of vertices

*         Exit: walks through the vector comparing it's vertex with the source vertex. incrementing index each time it's not found. returns index.
*******************************************************/

int FindIndex(Vertex<string, int>*x, vector<Vertex<string, int>*>* vertices)
{
	int index = 0;
	while (x->getData() != (*vertices)[index]->getData())
		index++;
	return index;
}

/******************************************************
*   Purpose:  finds the element of distance with the least value

*         Entry:  passed in an int array, a vector of vertices and a size

*         Exit: walks through the int array comparing each element of the array to min. if it's less than set min to the element of the array and min_index the the index of the array.
*******************************************************/

int MinDistance(int *dist, vector<Vertex<string, int>*>* vertices,int size)
{
	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < size; v++)
		if ((*vertices)[v]->getProcessed() == false && dist[v] <= min && dist[v]!= INT_MAX)
			min = dist[v], min_index = v;

	return min_index;
}

/******************************************************
*   Purpose:  decides if all the vertices in the vector have been processed

*         Entry:  passed in a vector of vertices

*         Exit: walks through the vector checking if the vertex has been processed if it finds one that isn't processed it returns false else if it gets all the way through it returns true.
*******************************************************/

bool AllProcessed(vector<Vertex<string, int>*>* vertices)
{
	for (int i = 0; i < (*vertices).size(); i++)
	{
		if ((*vertices)[i]->getProcessed() == false)
			return false;
	}
	return true;
}

/******************************************************
*   Purpose:  dijkstra's calculating shortest distance

*         Entry:  passed in a vector of vertices a starting point and ending point

*         Exit:  walks through distance comparing shortest distances and adding its neighbors distances to update the distance array. update the predecessor array. then finds the path by building a stack following the predecessor array.
				outputs results.
*******************************************************/

void DijkstraDistance(vector<Vertex<string, int>*>* vertices, int source, int destination)
{
	int * distance = new int[vertices->size()];
	int * pred = new int[vertices->size()];
	InitializeArrays(distance, pred, vertices->size());
	distance[0] = 0;
	pred[0] = 0;
	while (!AllProcessed(vertices))
	{
		int min = MinDistance(distance, vertices, (*vertices).size());
		vector<Edge<string, int>*>* edges = (*vertices)[min]->getEdges();
		for (int i = 0; i < (*vertices)[min]->getEdges()->size(); i++)
		{
			if (distance[min] + (*edges)[i]->getWeight()<distance[FindIndex((*edges)[i]->getDestination2(), vertices)])
			{
				distance[FindIndex((*edges)[i]->getDestination2(), vertices)] = distance[min] + (*edges)[i]->getWeight();
				pred[FindIndex((*edges)[i]->getDestination2(), vertices)] = min;
			}
		}
		(*vertices)[min]->setProcessed(true);
	}
	stack<Vertex<string, int>*> path;
	if (destination > source)
		destination = destination - source;
	else
		destination = vertices->size() + (destination - source);
	int index = destination;
	while (index != 0)
	{
		path.push((*vertices)[index]);
		index = pred[index];
	}
	path.push((*vertices)[index]);
	cout << "shortest path from " << (*vertices)[0]->getData() << " to " << (*vertices)[destination]->getData() << endl << endl;
	while (!path.empty())
	{
		cout << path.top()->getData();
		path.pop();
		if (!path.empty())
			cout << " -> ";
	}
	cout << endl << "Total Distance: " << distance[destination] << " miles" << endl << endl;
}

/******************************************************
*   Purpose:  dijkstra's calculating cheapest cost

*         Entry:  passed in a vector of vertices a starting point and ending point

*         Exit:  walks through distance comparing costs and adding its neighbors cost to update the distance array. update the predecessor array. then finds the path by building a stack following the predecessor array.
				outputs results.
*******************************************************/

void DijkstraCost(vector<Vertex<string, int>*>* vertices, int source, int destination)
{
	int * distance = new int[vertices->size()];
	int * pred = new int[vertices->size()];
	InitializeArrays(distance, pred, vertices->size());
	distance[0] = 0;
	pred[0] = 0;
	while (!AllProcessed(vertices))
	{
		int min = MinDistance(distance, vertices, (*vertices).size());
		vector<Edge<string, int>*>* edges = (*vertices)[min]->getEdges();
		for (int i = 0; i < (*vertices)[min]->getEdges()->size(); i++)
		{
			if (distance[min] + (*edges)[i]->getCost()<distance[FindIndex((*edges)[i]->getDestination2(), vertices)])
			{
				distance[FindIndex((*edges)[i]->getDestination2(), vertices)] = distance[min] + (*edges)[i]->getCost();
				pred[FindIndex((*edges)[i]->getDestination2(), vertices)] = min;
			}
		}
		(*vertices)[min]->setProcessed(true);
	}
	stack<Vertex<string, int>*> path;
	if (destination > source)
		destination = destination - source;
	else
		destination = vertices->size() + (destination - source);
	int index = destination;
	while (index != 0)
	{
		path.push((*vertices)[index]);
		index = pred[index];
	}
	path.push((*vertices)[index]);
	cout << "cheapest path from " << (*vertices)[0]->getData() << " to " << (*vertices)[destination]->getData() << endl << endl;
	while (!path.empty())
	{
		cout << path.top()->getData();
		path.pop();
		if (!path.empty())
			cout << " -> ";
	}
	cout << endl << "Total Cost: " << distance[destination] << " Dollars" << endl << endl;
}

/******************************************************
*   Purpose:  resets the processed state of all the vectors in the passed in vector

*         Entry:  passed in a vector of vertices

*         Exit:  walks through vector setting each ones processed bool to false.
*******************************************************/

void Reset(vector<Vertex<string, int>*>* vertices)
{
	for (int i = 0; i < vertices->size(); i++)
		(*vertices)[i]->setProcessed(false);
}