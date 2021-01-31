#include<cstring>
#include<cstdlib>
#include<string>
#include<sstream>

#include "../../include/tree/node.hpp"

namespace tree {
    Node::Node(std::string prefix, int code){
        this->prefix = prefix;
        this->code = code;
        this->parent = nullptr;
    }

    Node::~Node(){

    }

    int Node::get_code(){
        return this->code;
    }

    std::string Node::get_prefix(){
        return this->prefix;
    }

    std::string Node::get_full_prefix(){
        std::stringstream stream;
        stream << this->prefix;
        for(Node* p = this->parent; p != nullptr; p = p->parent){
            stream << p->prefix;
        }
        std::string inverted_prefix = stream.str();
        return std::string(inverted_prefix.rbegin(), inverted_prefix.rend());
    }

    std::vector<Node*> Node::get_children(){
        return this->children;
    }

    Node* Node::get_child(int i){
        return this->children.at(i);
    }

    Node* Node::get_child(std::string prefix){
        std::vector<Node*>::iterator it;
        for(it = this->children.begin(); it != this->children.end(); ++it){
            if((*it)->prefix.compare(prefix) == 0){
                return *it;
            }
        }
        return nullptr;
    }

    void Node::clear(){
        throw "Not implemented";
    }
}