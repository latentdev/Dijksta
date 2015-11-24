#include "Driver.h"
#include "Graph.h"
#include <iostream>
#include "Reader.h"
#include <vector>
#include "airport.h"
#include <string>
#include "Vertex.h"
using namespace std;

void Driver()
{
	Reader*reader = new Reader();
	reader->ReadFile("airports.txt");
	vector<airport*>x = reader->getAirports();
	Graph<string, int>* a = new Graph<string, int>();
	a->FillGraph(x);
	Menu(x,a);
	a->DepthFirst(x[0]->name);
	a->Reset();
	cout << endl;
}

void Dijkstra(Graph<string, int>*x,int source,int destination)
{
	int * distance= new int[x->getVertices().size()];
	int * pred = new int[x->getVertices().size()];
	vector<Vertex<string, int>*>* vertices= new vector<Vertex<string,int>*>;
	list<Vertex<string, int>>::iterator vert_iter;
	list<Vertex<string, int>> temp = x->getVertices();
	InitializeArrays(distance, pred, temp.size());
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
	}
	distance[0] = 0;
	//int m = FindIndex((*vertices)[0], vertices);
	while (!AllProcessed(vertices))
	{
		int min = MinDistance(distance, vertices, (*vertices).size());
		vector<Edge<string, int>*>* edges = (*vertices)[min]->getEdges();
		for (int i = 0; i < (*vertices)[min]->getEdges()->size(); i++)
		{
				distance[FindIndex((*edges)[i]->getDestination2(), vertices)] = distance[min] + (*edges)[i]->getWeight();
				pred[FindIndex((*edges)[i]->getDestination2(), vertices)] = min;
		}
		(*vertices)[min]->setProcessed(true);
	}
}
void Menu(vector<airport*> x, Graph<string, int>*y)
{
	for (int i = 0; i < x.size(); i++)
		cout << i+1 << ". " << x[i]->name << endl;
	cout << "Please choose the number that corresponds to desired starting location: ";
	int source;
	cin >> source;
	cout << endl<<"Please choose the number that corresponds to the desired destination: ";
	int destination;
	cin >> destination;
	cout << endl;
	Dijkstra(y, source - 1, destination - 1);
}
void InitializeArrays(int *distance, int *predecessor,int size)
{
	for (int i = 0; i < size; i++)
	{
		distance[i] = -1;
		predecessor[i] = -1;
	}
}

int FindIndex(Vertex<string, int>*x, vector<Vertex<string, int>*>* vertices)
{
	int index = 0;
	while (x->getData() != (*vertices)[index]->getData())
		index++;
	return index;
}

int MinDistance(int *dist, vector<Vertex<string, int>*>* vertices,int size)
{
	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < size; v++)
		if ((*vertices)[v]->getProcessed() == false && dist[v] <= min && dist[v]!=-1)
			min = dist[v], min_index = v;

	return min_index;
}
bool AllProcessed(vector<Vertex<string, int>*>* vertices)
{
	for (int i = 0; i < (*vertices).size(); i++)
	{
		if ((*vertices)[i]->getProcessed() == false)
			return false;
	}
	return true;
}