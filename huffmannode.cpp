#include "huffmannode.h"
/**
 * The Huffman Node Methods
 */

/**
 * The Huffman Node constructors
 */
KTMNYA001::HuffmanNode::HuffmanNode(char l, int f): letter(l), freq(f){}

KTMNYA001::HuffmanNode::HuffmanNode(int f): freq(f){
    letter = '\0';
}

KTMNYA001::HuffmanNode::HuffmanNode(const KTMNYA001::HuffmanNode& oldNode): letter(oldNode.letter), freq(oldNode.freq){
    left = oldNode.left;
    right = oldNode.right;
}

KTMNYA001::HuffmanNode::~HuffmanNode(){}
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
    if (a < b) return false;
    return true;
}
