#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "node.h"
using namespace std;

void read_struct_file(string fileName, vector<int>* victor) {
	string line = "", substring = "";
	ifstream test(fileName);

	vector<string> stringy;
	while (!test.eof()) {
		getline(test, line);
		stringstream strings(line);
		while (strings.good()) {
			getline(strings, substring, ',');
			stringy.push_back(substring);
		}
	}
	vector<string>::iterator k;
	for (k = stringy.begin(); k < stringy.end(); k++)
		victor->push_back(stoi(*k));
}

void read_input_file(string fileName, vector<double>* victor) {
	string line = "", substring= "";
	ifstream test(fileName);
	
	vector<string> stringy;
	while (!test.eof()) {
		getline(test, line);
		stringstream strings(line);
		while (strings.good()) {
			getline(strings, substring, ',');
			stringy.push_back(substring);
		}	
	}
	vector<string>::iterator k;
	for (k = stringy.begin(); k < stringy.end()-1; k++)
		victor->push_back(stod(*k));
}



void build_network(vector<vector<node*>> *network, vector<int> *structure) {
	vector <int>::iterator i;
	vector<node*>* previous = nullptr;
	for (i = structure->begin(); i < structure->end(); i++) {
		vector<node*>* temp = new vector<node*>;
		if (i == structure->begin()) {
			for (int j = 0; j < *i; j++) {
				temp->push_back(new node());
			}
		}
		else
			for (int j = 0; j < *i; j++)
				temp->push_back(new node(*previous));
		network->push_back(*temp);
		previous = temp;
	}
	/*for (int j = 0; j < network[0].size(); j++)
		network[0][j] = new node();
	for (int j = 1; j < network.size(); j++)
		fill_layer(network[j], network[j - 1]);*/
}

void build_network_v2(vector<vector<node*>>* network, vector<int>* structure) {
	vector <int>::iterator i;
	vector<node*>* previous = nullptr;
	for (i = structure->begin(); i < structure->end(); i++) {
		vector<node*>* temp = new vector<node*>;
			for (int j = 0; j < *i; j++) {
				temp->push_back(new node());
			}
		previous = temp;
		network->push_back(*temp);
	}
}

void fill_network(vector<vector<node*>> network) {
	for (int i = 1; i < network.size(); i++) {
		for(int j = 0; j < network[i].size();j++)
		network[i][j]->set_connections(network[i - 1]);
	}
	
}
void insert_input(vector<vector<node*>> network,vector<double>* input) {
	vector<double>::iterator i;
	int j = 0;
	for (i = input->begin(); i < input->end(); i++) {
		//layer[j]->collector = *i;
		network[0][j]->collector = *i;
		j++;
	}	
}

void run_calc(vector<vector<node*>> network) {
	for (int i = 1; i < network.size(); i++) {//vector of vectors, start at the second layer
		for (int k = 0; k < network[i].size(); k++)//for each node in the current layer
			for (int j = 0; j < network[i-1].size(); j++)//for each node in the previous layer
				network[i][k]->collector += network[i-1][j]->collector;
	}
}

int main() {
	/*ofstream structurefile("structure_file.txt");
	structurefile << "1,2,3,4,5,6,7,8\n";
	structurefile.close();
	ofstream inputfile("input_file.txt");
	inputfile << "1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8\n";
	inputfile.close();*/
	vector<int> structure;
	vector<double> input;

	read_struct_file("structure_file.txt", &structure);
    read_input_file("input_file.txt", &input);

	/*vector<vector<node*>> network;
	build_network(&network, &structure);*/

	vector<vector<node*>> network2;
	build_network_v2(&network2, &structure);
	fill_network(network2);
	
	
	
	
	
	
	//insert_input(network, &input);
	insert_input(network2, &input);

	
	
	//run_calc(network);
	run_calc(network2);
	//cout << network[2][0]->collector << " ";
	cout << network2[2][0]->collector << " ";
	cout << "done" << endl;
	

}
