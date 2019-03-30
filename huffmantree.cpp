#include <queue>
#include <vector>

#include "huffmantree.h"

/**
 * Huffman Tree Class Methods
 */

/**
 * Huffman Tree class destructor
 */
// KTMNYA001::HuffmanTree::~HuffmanTree(){
//     //root = nullptr;
// }

bool KTMNYA001::HuffmanTree::build_tree(std::priority_queue<KTMNYA001::HuffmanNode, std::vector<KTMNYA001::HuffmanNode>, KTMNYA001::Compare> queue){
    return true;
}



/**
 * The Huffman Node Methods
 */

/**
 * The Huffman Node constructors
 */
KTMNYA001::HuffmanNode::HuffmanNode(char l, int f): letter(l), freq(f){}

/**
 * The < operator overloading. Compares two nodes based on their frequencies.
 */
bool KTMNYA001::HuffmanNode::operator < (const KTMNYA001::HuffmanNode& other){
    if (freq < other.freq) return true;
    return false;
}

/**
 * The predicate method to compare two HuffmanNodes. Uses the
 * < operator on the HuffmanNodes.
 */
bool KTMNYA001::Compare::operator()(KTMNYA001::HuffmanNode& a, KTMNYA001::HuffmanNode& b){
    if (a < b) return true;
    return false;
}

