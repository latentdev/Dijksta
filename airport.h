#pragma once
#include <string>
#include <vector>
using namespace std;
struct connection
{
	string name;
	int cost;
	int distance;
};

struct airport
{
	string name;
	vector<connection*>*flights;
};