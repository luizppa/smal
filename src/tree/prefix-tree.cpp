#include<string>
#include<sstream>
#include<iostream>

#include"../../include/tree/prefix_tree.hpp"

namespace tree {
    PrefixTree::PrefixTree(){
        this->root = new Node("");
    }

    PrefixTree::~PrefixTree(){

    }

    int PrefixTree::get_height(){
        return this->height;
    }

    int PrefixTree::get_size(){
        return this->size;
    }

    void PrefixTree::add(std::string prefix){
        throw "Not implemented";
    }

    Node* PrefixTree::get_root(){
        return this->root;
    }

    void PrefixTree::each(void (*callback)(std::string)){
        this->root->propagate(callback);
    }

    void PrefixTree::each(void (*callback)(std::string, char*)){
        char* path = (char*) malloc(sizeof(char));
        path[0] = '\0';
        this->root->propagate(path, callback);
    }

    void PrefixTree::remove(Node* node){
        throw "Not implemented";
    }

    void PrefixTree::clear(){
        throw "Not implemented";
    }
}