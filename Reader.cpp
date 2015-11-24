#include "Reader.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include "airport.h"
using namespace std;

Reader::Reader()
{
}

void Reader::ReadFile(string x)
{
	airports = new vector<airport*>();
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

vector<airport*> Reader::getAirports()
{
	return *airports;
}
