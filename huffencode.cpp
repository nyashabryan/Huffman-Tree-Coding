/**
 * Include statements
 */
#include <string>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <queue>

#include "huffmantree.h"

/**
 * Using declarations
 */
using namespace std;
using namespace KTMNYA001;

/**
 * Function declarations
 */
unordered_map<char, int> get_letter_frequency(string inputfile);
// bool compare(HuffmanNode& a, HuffmanNode& b);
priority_queue<HuffmanNode, vector<HuffmanNode>, Compare> make_priority_queue(const unordered_map<char, int>& map);

/**
 * The program main driver. Takes in the count of arguments and the list of
 * arguments.
 */
int main(int argc, char ** argv){

    // Check the number of arguments 
    if (argc > 3){
        cerr << "Too many arguments given. Exiting..." << endl;
        return 1;
    }

    if(argc < 3){
        cerr << "Too few arguments were given. Exiting..." << endl;
    }

    // take in the input filename from arguments
    string inputfilename = string(argv[1]);
    // count the number of occurences of letters in file.

    unordered_map<char, int> map = get_letter_frequency(inputfilename);

    for(const auto& n: map){
        cout << n.first << " " << n.second << endl;
    }

    cout << "Map size " << map.size() << endl;

    priority_queue<HuffmanNode, vector<HuffmanNode>, Compare> my_queue = make_priority_queue(map);

    //Test my queue
    // cout << "Testing priority queue" << endl;
    // while(my_queue.size() > 1){
    //     cout << my_queue.top().freq << endl;
    //     my_queue.pop();
    // }
    cout << "Done testing priority queue" << endl << endl;
    HuffmanTree tree;

    // Build the Huffman tree.
    tree.build_tree(my_queue);

    // Build the code table
    tree.build_code_table();

    for(const auto& n: tree.code_table){
        cout << n.first << " " << n.second << endl;
    }

    // Output the results of the encoding
    tree.output(string(argv[1]), string(argv[2]));

    tree.output_bitstream(string(argv[1]), string(argv[2]));
    return 0;
}

/**
 * Given a filename, it will take the utf-8 char and calculate 
 * a map of the characters and their frequencies in the file
 */
unordered_map<char, int> get_letter_frequency(string inputfile){
    unordered_map<char, int> map;

    // Open the filestream.
    ifstream ifs;
    ifs.open(inputfile, ifstream::in);

    // Take in character after character.
    char buffer[1];
    bool exists;
    while(!ifs.eof()){
        if(!ifs.good()) break;
        exists = false;
        ifs.read(buffer, sizeof(buffer[0]));
        
        // Check if the value is not already in the map
        for(const auto& n: map){
            if(n.first == char(buffer[0])) exists = true;
        }

        if(exists){ // Add one to the already existing entry
            map[char(buffer[0])] += 1;
        } else { // Add the new entry and put 0
            map[char(buffer[0])] = 1;
        }
    }

    map[buffer[0]] -= 1;

    ifs.close();

    cout << "Done reading in the input files to map" << endl;

    return map;
}


/**
 * Builds the priority queue for the Huffman Nodes.
 */
priority_queue<HuffmanNode, vector<HuffmanNode>, Compare> make_priority_queue(const unordered_map<char, int>& map){
    priority_queue<HuffmanNode, vector<HuffmanNode>, Compare> my_queue;
    for(const auto& n: map){
        HuffmanNode node(n.first, n.second);
        my_queue.push(node);
    }
    return my_queue;
}