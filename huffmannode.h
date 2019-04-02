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

        //Default Constructor
        HuffmanNode();

        // Constructor
        HuffmanNode(char l, int f);
        // Frequency only constructor
        HuffmanNode(int f);

        // Copy constructor
        HuffmanNode(const HuffmanNode& oldHuffmanNode);

        // Deconstructor
        ~HuffmanNode();

        // Operator overloading
        bool operator < (const HuffmanNode& other);

    };

    class Compare{
        public:
        bool operator() (HuffmanNode& a, HuffmanNode& b);
    };

}

#endif