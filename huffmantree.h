#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H
#include <memory>

namespace KTMNYA001{

    class HuffmanNode{

        public:
        /**
         * The left and right pointers
         */
        std::shared_ptr<KTMNYA001::HuffmanNode> left;
        std::shared_ptr<KTMNYA001::HuffmanNode> right;

        char letter;
        int freq;

        // Constructor
        HuffmanNode(char l, int f);
        // Deconstructor
        ~HuffmanNode();

        // Operator overloading
        bool operator < (const HuffmanNode& other);

    };

    class Compare{
        public:
        bool operator() (HuffmanNode& a, HuffmanNode& b);
    };

    class HuffmanTree{

        std::shared_ptr<HuffmanNode> root;

        // Constructor
        HuffmanTree();
        //Destructor
        ~HuffmanTree();

        bool build_tree(std::priority_queue<HuffmanNode, std::vector<HuffmanNode>, Compare> queue);

    };

}

#endif