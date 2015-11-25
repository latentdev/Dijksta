#pragma once
#include <string>
#include <vector>
using namespace std;
/************************************************************************
*Struct: connection
*Data Members:

*	string name
		name of the connected airport

*	int cost
		cost of the flight from the source airport to the destination

*	int distance
		distance from source airport to the destination

*************************************************************************/
struct connection
{
	string name;
	int cost;
	int distance;
};

/************************************************************************
*Struct: airport
*Data Members:

*	string name
		name of the airport

*	vector<connection*>*flights;
		a vector that holds struct connections. this represents all the flights connected to this airport.

*************************************************************************/
struct airport
{
	string name;
	vector<connection*>*flights;
};