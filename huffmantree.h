#ifndef HUFFMANNODE_H
#include <memory>

namespace KTMNYA001{

    class HuffmanNode{

        /**
         * The left and right pointers
         */
        std::shared_ptr<KTMNYA001::HuffmanNode> left;
        std::shared_ptr<KTMNYA001::HuffmanNode> right;

        char letter;
        int frequency;

        // Constructor
        HuffmanNode();
        // Deconstructor
        ~HuffmanNode();

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