#include "Reader.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include "airport.h"
using namespace std;

/******************************************************
*   Purpose:  default constructor

*         Entry:  none

*         Exit: allocates memory to airports
*******************************************************/

Reader::Reader()
{
	airports = new vector<airport*>();
}

/******************************************************
*   Purpose:  default constructor

*         Entry:  none

*         Exit: deletes airports
*******************************************************/

Reader::~Reader()
{
	delete airports;
}

/******************************************************
*   Purpose:  read and parse a file

*         Entry:  passed in a string corresponding to a file name

*         Exit: reads in a file parsing line by line into a vector then parses the vector of strings even further
*******************************************************/

void Reader::ReadFile(string x)
{
	ifstream infile(x);
	while (infile)
	{
		string s;
		if (!getline(infile, s)) break;
		istringstream ss(s);
		vector<string> record;
		while (ss)
		{
			string s;
			if (!getline(ss, s, ';')) break;
			record.push_back(s);
		}
		data.push_back(record);
	}
	if (!infile.eof())
	{
		cout << "Foo\n";
	}
	for (int i = 0; i < data.size(); i++)
		airports->push_back(BuildAirport(data[i]));

}

/******************************************************
*   Purpose:  factory for building an airport

*         Entry:  passed in a vector of strings

*         Exit: creates a new airport and fills out its members
*******************************************************/

airport* Reader::BuildAirport(vector<string> source)
{
	airport * temp = new airport;
	temp->flights = new vector<connection*>();
	temp->name = source[0];
	connection * temp2;
	if (source.size() > 1)
	{
		for (int i = 1; i < source.size(); i++)
		{
			temp2 = ParseConnection(source[i]);
			temp->flights->push_back(temp2);
		}
	}
	return temp;
}

/******************************************************
*   Purpose:  factory for a connection

*         Entry:  passed in a string

*         Exit: creates a new connection and builds it out by parsing the passed in string.
*******************************************************/

connection* Reader::ParseConnection(string s)
{
	istringstream ss(s);
	vector<string> record;
	while (ss)
	{
		string s;
		if (!getline(ss, s, ':')) break;
		record.push_back(s);
	}
	connection * x = new connection;
	x->name = record[0];
	x->cost = stoi(record[1]);
	x->distance = stoi(record[2]);
	return x;
}

/******************************************************
*   Purpose:  getter for airports

*         Entry:  none

*         Exit: returns airports
*******************************************************/

vector<airport*> Reader::getAirports()
{
	return *airports;
}
