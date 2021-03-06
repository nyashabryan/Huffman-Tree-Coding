#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H
#include <memory>
#include <string>
#include <unordered_map>

#include "huffmannode.h"

namespace KTMNYA001{

    class HuffmanTree{
        
        public:
        std::shared_ptr<HuffmanNode> root;
        std::unordered_map<char, std::string> code_table;

        // Constructor
        HuffmanTree();
        //Destructor
        ~HuffmanTree();

        bool build_tree(std::priority_queue<HuffmanNode, std::vector<HuffmanNode>, Compare> queue);

        void build_code_table();

        void build_code_table(std::string code, std::shared_ptr<HuffmanNode> current);

        void output(std::string input_file, std::string output_file);

        void write_output(std::string input_file, std::string output_file);

        void write_hdr(std::string header_file);

        void output_bitstream(std::string input_file, std::string output_file);
    };

}

#endif