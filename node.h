#pragma once
#include <vector>
#include <iostream>
#include <string>
using namespace std;
class node {
	
public:
	double collector = 0.0;
	vector <node*> connections;
	node();
	node(vector<node*> connections);
	void set_collector(double value);
	void set_connections(vector <node*> connections);
	//string to_string(){};
};


