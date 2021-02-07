#include<sstream>
#include<fstream>
#include<string>
#include<iostream>
#include<cstdlib>
#include<map>

#include"../include/compressor.hpp"
#include"../include/tree/prefix-tree.hpp"

namespace smal{
    
    void Compressor::compress(std::string input_path, std::string output_path){
        std::ifstream input_file(input_path);
        std::ofstream output_file(output_path, std::ios::binary);
        tree::PrefixTree* prefix_tree = new tree::PrefixTree();

        if(!input_file.is_open()){
            throw "Unexistent input file";
        }
        if(!output_file.is_open()){
            throw "Can't open output file\n";
        }

        char c, eof = (char)4;
        int code;
        tree::Node* prefix_node = prefix_tree->get_root();

        input_file.unsetf(std::ios_base::skipws);
        while(input_file >> c){
            tree::Node* prefix_child = prefix_node->get_child(std::string(1, c));
            code = prefix_node->get_code();
            if(prefix_child == nullptr){
                output_file.write((char*)(&code), 4);
                output_file.write(&c, 1);
                prefix_tree->add(prefix_node, std::string(1, c));
                prefix_node = prefix_tree->get_root();
            }
            else{
                prefix_node = prefix_child;
            }
        }
        code = prefix_node->get_code();
        if(prefix_node != prefix_tree->get_root()){
            output_file.write((char*)(&code), sizeof(int));
            output_file.write((char*)(&eof), sizeof(char));
        }

        input_file.close();
        output_file.close();
        delete prefix_tree;
    }

    void Compressor::decompress(std::string input_path, std::string output_path){
        std::ifstream input_file(input_path);
        std::ofstream output_file(output_path);
        tree::PrefixTree* prefix_tree = new tree::PrefixTree();
        std::map<int, tree::Node*> dictionary;

        if(!input_file.is_open()){
            throw "Unexistent input file";
        }
        if(!output_file.is_open()){
            throw "Can't open output file\n";
        }

        int* code = (int*) malloc(sizeof(int));
        char* c = (char*) malloc(sizeof(char));
        char eof = (char)4
        tree::Node* new_node = nullptr;

        input_file.unsetf(std::ios_base::skipws);
        while(input_file.read((char *)code, sizeof(int)) && input_file.read(c, sizeof(char))){
            if(*code == 0){
                output_file << *c;
                new_node = prefix_tree->add(prefix_tree->get_root(), std::string(1, *c));
                dictionary[new_node->get_code()] = new_node;
            }
            else{
                tree::Node* prefix_node = dictionary[*code];
                if(prefix_node != nullptr){
                    if(*c != eof){
                        output_file << prefix_node->get_full_prefix() << *c;
                    }
                    else{
                        output_file << prefix_node->get_full_prefix();
                    }
                    new_node = prefix_tree->add(prefix_node, std::string(1, *c));
                    dictionary[new_node->get_code()] = new_node;
                }
            }
        }
        free(code);
        free(c);
        delete prefix_tree;
    }


}