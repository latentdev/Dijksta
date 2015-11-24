#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <list>
#include "airport.h"
using namespace std;



class Reader
{
private:
	vector<airport*>* airports;
	vector<vector<string>>data;
public:
	Reader();
	void ReadFile(string x);
	airport* BuildAirport(vector<string> source);
	connection* ParseConnection(string s);
	vector<airport*> getAirports();
};