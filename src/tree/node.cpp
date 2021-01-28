#include<cstring>
#include<cstdlib>
#include<string>

#include "../../include/tree/node.hpp"

namespace tree {
    Node::Node(std::string prefix){
        this->prefix = prefix;
        this->parent = nullptr;
    }

    Node::~Node(){

    }

    std::string Node::get_prefix(){
        return this->prefix;
    }

    std::string Node::get_full_prefix(){
        throw "Not implemented";
        return "";
    }

    Node* Node::get_parent(){
        return this->parent;
    }

    void Node::set_parent(Node* parent){
        this->parent = parent;
    }

    std::vector<Node*> Node::get_children(){
        return this->children;
    }

    Node* Node::get_child(int i){
        return this->children.at(i);
    }

    void Node::add_child(std::string child){
        throw "Not implemented";
    }

    int Node::get_height(){
        throw "Not implemented";
        return -1;
    }

    int Node::get_size(){
        throw "Not implemented";
        return -1;
    }

    void Node::each(void (*callback)(std::string)){
        throw "Not implemented";
    }

    void Node::each(char* path, void (*callback)(std::string, char*)){
        throw "Not implemented";
    }

    void Node::clear(){
        throw "Not implemented";
    }
}