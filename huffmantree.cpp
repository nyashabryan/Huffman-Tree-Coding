#include <queue>
#include <vector>
#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <bitset>

#include "huffmantree.h"
#include "huffmannode.h"

// using directives
using namespace std;
/**
 * Huffman Tree Class Methods
 */
KTMNYA001::HuffmanTree::HuffmanTree(void){}
/**
 * Huffman Tree class destructor
 */
KTMNYA001::HuffmanTree::~HuffmanTree(){
    root = nullptr;
}

/**
 * Builds the HuffmanTree from the priority queue.
 */
bool KTMNYA001::HuffmanTree::build_tree(std::priority_queue<KTMNYA001::HuffmanNode, std::vector<KTMNYA001::HuffmanNode>, KTMNYA001::Compare> my_queue){
    cout << "Beginning to build tree " << "queue size: " << my_queue.size() <<endl;
    while(my_queue.size() > 1){
        
        shared_ptr<HuffmanNode> left(new HuffmanNode(my_queue.top()));
        my_queue.pop();

        shared_ptr<HuffmanNode> right(new HuffmanNode(my_queue.top()));
        my_queue.pop();

        shared_ptr<HuffmanNode> node(new HuffmanNode(left->freq + right->freq));
        node->left = left;
        node->right = right;

        
        my_queue.push(*node);

        if(my_queue.size() == 1){
            root = node;
        }
        
    }
    // shared_ptr<HuffmanNode> last(new HuffmanNode(my_queue.top()));
    // root = last;
    return true;
}

/**
 * Initiates the code table building
 */
void KTMNYA001::HuffmanTree::build_code_table(){
    std::string code = "";
    build_code_table(code, root);
}

/**
 * Recursively builds the code table by traversing down the HuffmanTree
 */
void KTMNYA001::HuffmanTree::build_code_table(std::string code, std::shared_ptr<KTMNYA001::HuffmanNode> current){
    if(!(current->letter == '\0')){
        code_table[current->letter] = code;
    }

    if(!(current->left == nullptr)){
        build_code_table(code + "0", current->left);
    }

    if(!(current->right == nullptr)){
        build_code_table(code + "1", current->right);
    }
}

/**
 * Initiates the output of the encoding process.
 */
void KTMNYA001::HuffmanTree::output(string input_file, string output_file){
    write_hdr(output_file + ".hdr");
    write_output(input_file, output_file);
}

/**
 * Write the output of the encoding of the original characters into 
 * an output file.
 */
void KTMNYA001::HuffmanTree::write_output(string input_file, string output_file){
    cout << "Writing output" << endl;
    string output = "";
    char buffer[1];
    ifstream ifs;
    cout << input_file << endl;
    ifs.open(input_file);
    while(!ifs.eof()){
        ifs.read(buffer, sizeof(buffer[0]));
        output+=code_table[buffer[0]];
    }
    ifs.close();

    cout << "Done" << endl;
    ofstream ofs;
    ofs.open(output_file);
    ofs << output.c_str();
    ofs.close();
}

/**
 * Output the encoding details to a header file. Includes the 
 * encoding table.
 */
void KTMNYA001::HuffmanTree::write_hdr(string header_file){
    ofstream ofs;
    ofs.open(header_file);
    ofs << code_table.size() << endl;
    for(const auto &n: code_table){
        ofs << n.first << ": " << n.second << endl;
    }
}

/**
 * Outputs the encoded input to a bitstream
 */
void KTMNYA001::HuffmanTree::output_bitstream(string inputfile, string outputfile){
    cout << "Writing output" << endl;
    string output = "";
    char buffer[1];
    ifstream ifs;
    cout << inputfile << endl;
    ifs.open(inputfile);
    while(!ifs.eof()){
        ifs.read(buffer, sizeof(buffer[0]));
        output+=code_table[buffer[0]];
    }
    ifs.close();


    int numberOfBytes;
    int numberOfBits = output.size();

    numberOfBytes = numberOfBits/8 + (numberOfBits%8 ? 1: 0);
    if(numberOfBytes == 0) return;

    char bitstream[numberOfBytes];

    // Intialize the bitstream to 0s
    for(int i = 0; i < numberOfBytes; i++){
        bitstream[i] = 0;
    }

    // Iterate through the bits in the output
    int count = 0;
    int byte = 0;
    int value = 0;
    for(int i = 0; i < numberOfBits; i++){
        if (i % 8 == 0 && i != 0){
            byte++;
        }
        if (output[i] == '1'){
            bitstream[byte] |= 1 << count;
        }
        count = (count + 1) % 8;

    }

    // print the bitstream
    for (int i =0; i < numberOfBytes; i++){
        bitset<8> a(bitstream[i]);
        cout << a << endl;
    }
}