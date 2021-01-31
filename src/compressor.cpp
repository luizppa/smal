#include<sstream>
#include<fstream>
#include<string>
#include<iostream>

#include"../include/compressor.hpp"
#include"../include/tree/prefix-tree.hpp"

namespace smal{
    
    void Compressor::compress(std::string input_path, std::string output_path){
        std::ifstream input_file(input_path);
        std::ofstream output_file(output_path);
        tree::PrefixTree* prefix_tree = new tree::PrefixTree();

        if(!input_file.is_open()){
            throw "Unexistent input file";
        }
        if(!output_file.is_open()){
            throw "Can't open output file\n";
        }

        char c;
        tree::Node* prefix_node = prefix_tree->get_root();
        while(input_file >> c){
            tree::Node* prefix_child = prefix_node->get_child(std::string(1, c));
            if(prefix_child == nullptr){
                std::cout << "cant find " << c << "\t creating new entry with code " << prefix_tree->get_size() << ", inserting pair (" << prefix_node->get_code() << ';' << c << ")\n";
                output_file << '(' << prefix_node->get_code() << ';' << c << ')';
                prefix_tree->add(prefix_node, std::string(1, c));
                prefix_node = prefix_tree->get_root();
            }
            else{
                prefix_node = prefix_child;
                std::cout << "found " << c << '\n';
            }
        }
        if(prefix_node != prefix_tree->get_root()){
            output_file << '(' << prefix_node->get_code() << ';' << (char)4 << ')';
        }

        input_file.close();
        output_file.close();
    }

    void Compressor::decompress(std::string input_path, std::string output_path){
        std::ifstream input_file(input_path);
        std::ofstream output_file(output_path);
        if(!input_file.is_open()){
            throw "Unexistent input file";
        }
        if(!output_file.is_open()){
            throw "Can't open output file\n";
        }
    }


}