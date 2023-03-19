import sys

from node import node
import time as t
import pickle as p
import random as r


def open_files(file_name_one, file_name_two):#open the files and return the contents as a list
    network = []
    input = []
    try:
        network_structure_file = open(file_name_one, 'r')
        input_file = open(file_name_two,'r')
    except:
        print("invalid files")
        network_structure_file = open(file_name_one, 'w')
        input_file = open(file_name_two, 'w')
        network_structure_file.close;input_file.close
        exit()

    network_structure,inputA = network_structure_file.read().strip().split(','),input_file.read().strip().split(',')# split both files
    #network_structure = network_structure.split(',')
    for i in network_structure:
        network.append(int(i))
    for i in inputA:
        input.append(float(i))
    return network, input


def build_network(networkstructure, input):
    network = []

    prev_layer = None
    for i in network_structure:
        layer = []
        for j in range(i):
            layer.append(node(prev_layer))
        network.append(layer)
        prev_layer = layer

    for i in range(len(network[0])):
        network[0][i].collector = input[i]
    return network

def ANN_calc(network):
    for i in network:
        for j in i:
            if (j.connections != None):
                for k in j.connections:
                    j.collector = j.collector + k.collector
    return network[2][0].collector
def make_test_file():
    with open('test.txt', 'w') as test:
        sys.stdout = test
        for i in range(9999999):
            print(r.uniform(0.0, 99.99), end = ',')
        print(r.uniform(0.0, 99.99))
        sys.stdout = sys.__stdout__
        test.close()
if __name__ == "__main__":

    make_test_file()
    #network_structure, input = open_files('networkstructure.txt', 'inputfile.txt')
    network_structure, input = open_files('networkstructure.txt', 'inputfile.txt')
    if network_structure[0] != len(input):
        print(len(input))
        print("input layer, input value mismatch")
        exit()




    network = build_network(network_structure,input)


    print(ANN_calc(network))

    with open('ANN.pickle','wb') as rick:#lol
        p.dump(network,rick)

