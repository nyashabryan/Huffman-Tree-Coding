#ifndef HUFFMANNODE_H
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

    class HuffmanTree{

        std::shared_ptr<HuffmanNode> root;

        // Constructor
        HuffmanTree();
        //Destructor
        ~HuffmanTree();

    };

}

#endif