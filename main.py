def open_files(file_name_one, file_name_two):
    network = []
    input = []
    network_structure_file = open(file_name_one, 'r')
    input_file = open(file_name_two,'r')
    network_structure,inputA = network_structure_file.read().strip().split(','),input_file.read().strip().split(',')
    #network_structure = network_structure.split(',')
    for i in network_structure:
        network.append(int(i))
    for i in inputA:
        input.append(int(i))
    return network, input

if __name__ == "__main__":
    network_structure, input = open_files('networkstructure.txt', 'inputfile.txt')

    print(network_structure,input)
    for i in range(len(network_structure)):
        print(network_structure[i]+input[i])
