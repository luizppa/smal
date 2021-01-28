#ifndef NODE_H
#define NODE_H

#include<string>
#include<vector>

namespace tree {

    class PrefixTree;

    class Node{
        private:
            std::string prefix;
            Node* parent;
            std::vector<Node*> children;
            void clear();

            friend class PrefixTree;
        public:
            Node(std::string prefix);
            ~Node();
            std::string get_prefix();
            std::string get_full_prefix();
            Node* get_parent();
            void set_parent(Node* parent);
            std::vector<Node*> get_children();
            Node* get_child(int i);
            void add_child(std::string child);
            int get_height();
            int get_size();
            void each(void (*callback)(std::string));
            void each(char* path, void (*callback)(std::string, char*));
    };
}

#endif