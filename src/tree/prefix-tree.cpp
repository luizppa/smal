#include<string>
#include<sstream>
#include<iostream>

#include"../../include/tree/prefix-tree.hpp"

namespace tree {
    PrefixTree::PrefixTree(){
        this->root = new Node("", 0);
        this->size = 1;
    }

    PrefixTree::~PrefixTree(){

    }

    Node* PrefixTree::get_root(){
        return this->root;
    }

    int PrefixTree::get_size(){
        return this->size;
    }

    void PrefixTree::add(Node* node, std::string prefix){
        Node* new_node = new Node(prefix, this->size);
        node->children.push_back(new_node);
        new_node->parent = node;
        this->size++;
    }

    Node* PrefixTree::find(int code){
        return nullptr;
    }

    void PrefixTree::clear(){
        throw "Not implemented";
    }
}