#pragma once
#include "Graph.h"
#include <string>

void Driver();
void Dijkstra(Graph<string,int>*x, int source, int destination);
void Menu(vector<airport*> x, Graph<string, int>*y);
void InitializeArrays(int *distance, int *predecessor, int size);
int FindIndex(Vertex<string, int>*x, vector<Vertex<string, int>*>* vertices);
int MinDistance(int *dist, vector<Vertex<string, int>*>* vertices, int size);
bool AllProcessed(vector<Vertex<string, int>*>* vertices);