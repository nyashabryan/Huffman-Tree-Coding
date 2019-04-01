#include <queue>
#include <vector>
#include <iostream>
#include <memory>

#include "huffmantree.h"

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

bool KTMNYA001::HuffmanTree::build_tree(std::priority_queue<KTMNYA001::HuffmanNode, std::vector<KTMNYA001::HuffmanNode>, KTMNYA001::Compare> my_queue){

    while(my_queue.size() > 1){
        std::shared_ptr<HuffmanNode> left(new KTMNYA001::HuffmanNode(my_queue.top()));
        my_queue.pop();
        std::shared_ptr<HuffmanNode> right(new KTMNYA001::HuffmanNode(my_queue.top()));
        my_queue.pop();

        HuffmanNode node(left->freq + right->freq);

        my_queue.push(node);
    }
    root = std::make_shared<KTMNYA001::HuffmanNode>(KTMNYA001::HuffmanNode(my_queue.top()));
    std::cout << "Done loading priority queue" << std::endl;
    return true;
}


/**
 * The Huffman Node Methods
 */

/**
 * The Huffman Node constructors
 */
KTMNYA001::HuffmanNode::HuffmanNode(char l, int f): letter(l), freq(f){}

KTMNYA001::HuffmanNode::HuffmanNode(int f): freq(f){}

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
    if (a < b) return true;
    return false;
}

