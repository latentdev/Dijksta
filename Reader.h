#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <list>
#include "airport.h"
using namespace std;
/************************************************************************
*Class: Reader
*
*Data Members:
*	vector<airport*>* airports
		vector of airport structs

*	vector<vector<string>>data
		vector of strings used for parsing

*Constructors:
*	Reader()
		default constructor

*	~Reader()
		destructor

*Mutators:
*	vector<airport*> getAirports()
		getter for airports

*Methods:
*	void ReadFile(string x)
		reads in a file line by line.

*	airport* BuildAirport(vector<string> source)
		factory for building an airport based on a string

*	connection* ParseConnection(string s)
		parses the passed in string into a connection

*************************************************************************/


class Reader
{
private:
	vector<airport*>* airports;
	vector<vector<string>>data;
public:
	Reader();
	~Reader();
	void ReadFile(string x);
	airport* BuildAirport(vector<string> source);
	connection* ParseConnection(string s);
	vector<airport*> getAirports();
};