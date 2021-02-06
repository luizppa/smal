#include<string>
#include<sstream>
#include<iostream>
#include<queue>

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

    Node* PrefixTree::add(Node* node, std::string prefix){
        Node* new_node = new Node(prefix, this->size);
        node->children.push_back(new_node);
        new_node->parent = node;
        this->size++;
        return new_node;
    }

    Node* PrefixTree::find(int code){
        std::queue<Node*> to_visit;
        std::vector<Node*>::iterator it;
        if(code == 0){
            return this->root;
        }
        for(it = this->root->children.begin(); it != this->root->children.end(); ++it){
            to_visit.push(*it);
        }
        while(!to_visit.empty()){
            Node* p = to_visit.front();
            to_visit.pop();
            if(p->code == code){
                return p;
            }
            else{
                for(it = p->children.begin(); it != p->children.end(); ++it){
                    to_visit.push(*it);
                }
            }
        }
        return nullptr;
    }

    void PrefixTree::clear(){
        throw "Not implemented";
    }
}