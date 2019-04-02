#include <queue>
#include <vector>
#include <iostream>
#include <memory>
#include <string>

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
    }
    shared_ptr<HuffmanNode> last(new HuffmanNode(my_queue.top()));
    root = last;
    return true;
}

void KTMNYA001::HuffmanTree::build_code_table(){
    std::string code = "";
    build_code_table(code, root);
}

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

