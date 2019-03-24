#include <string>
#include <iostream>
#include <fstream>
#include <unordered_map>

#include "huffmantree.h"


using namespace std;
using namespace KTMNYA001;

// Function declarations
unordered_map<string, int> getLetterFrequency(string inputfile);

/**
 * The program main.
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

    unordered_map<string, int> map = getLetterFrequency(inputfilename);

    for(const auto& n: map){
        cout << n.first << " " << n.second << endl;
    }

    return 0;
}

/**
 * Given a filename, it will take the utf-8 char and calculate 
 * a map of the characters and their frequencies in the file
 */
unordered_map<string, int> getLetterFrequency(string inputfile){
    unordered_map<string, int> map;

    // Open the filestream.
    ifstream ifs;
    ifs.open(inputfile);

    // Take in character after character.
    char buffer[1];
    bool exists;
    while(!ifs.eof()){
        exists = false;
        ifs.read(buffer, sizeof(buffer[0]));
        
        // Check if the value is not already in the map
        for(const auto& n: map){
            if(n.first == string(&buffer[0])) exists = true;
        }

        if(exists){ // Add one to the already existing entry
            map[string(&buffer[0])] += 1;
        } else { // Add the new entry and put 0
            map[string(&buffer[0])] = 1;
        }
    }

    ifs.close();

    cout << "Done reading in the input files to map" << endl;

    return map;
}