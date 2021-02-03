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

        input_file.unsetf(std::ios_base::skipws);
        while(input_file >> c){
            tree::Node* prefix_child = prefix_node->get_child(std::string(1, c));
            if(prefix_child == nullptr){
                output_file << '(' << prefix_node->get_code() << ';' << c << ')';
                prefix_tree->add(prefix_node, std::string(1, c));
                prefix_node = prefix_tree->get_root();
            }
            else{
                prefix_node = prefix_child;
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
        tree::PrefixTree* prefix_tree = new tree::PrefixTree();

        if(!input_file.is_open()){
            throw "Unexistent input file";
        }
        if(!output_file.is_open()){
            throw "Can't open output file\n";
        }

        input_file.unsetf(std::ios_base::skipws);
        char dc;
        int code;
        char c;
        while(input_file >> dc >> code >> dc >> c >> dc){
            if(code == 0){
                output_file << c;
                prefix_tree->add(prefix_tree->get_root(), std::string(1, c));
            }
            else{
                tree::Node* prefix_node = prefix_tree->find(code);
                if(prefix_node != nullptr){
                    if(c != (char)4){
                        output_file << prefix_node->get_full_prefix() << c;
                    }
                    else{
                        output_file << prefix_node->get_full_prefix();
                    }
                    prefix_tree->add(prefix_node, std::string(1, c));
                }
            }
        }
    }


}