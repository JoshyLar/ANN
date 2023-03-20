#include "node.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;



	
	node::node() {
	};//basic constructor for the node class

	node::node(vector<node*> layer) {
		  this->connections = layer;
	}
	void node::set_collector(double value) {
		this->collector = value;
	}
	void node::set_connections(vector <node*> connections) {
		this->connections = connections;
	}
	

