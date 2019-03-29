#include "huffmantree.h"

/**
 * Huffman Tree Class Methods
 */

/**
 * Huffman Tree class destructor
 */
KTMNYA001::HuffmanTree::~HuffmanTree(){
    root = nullptr;
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
bool KTMNYA001::HuffmanNode::operator<(const HuffmanNode& other){
    if (freq < other.freq) return true;
    return false;
}

