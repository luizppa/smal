#ifndef NODE_H
#define NODE_H

#include<string>
#include<vector>

namespace tree {

    class PrefixTree;

    class Node{
        private:
            int code;
            std::string prefix;
            std::vector<Node*> children;
            Node* parent;
            void clear();

            friend class PrefixTree;
        public:
            Node(std::string prefix, int code);
            ~Node();
            int get_code();
            std::string get_prefix();
            std::string get_full_prefix();
            std::vector<Node*> get_children();
            Node* get_child(int i);
            Node* get_child(std::string prefix);
    };
}

#endif