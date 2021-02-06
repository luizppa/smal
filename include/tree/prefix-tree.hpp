#ifndef TREE_H
#define TREE_H

#include<string>

#include"./node.hpp"

namespace tree{

    class PrefixTree{

        private:
            int size = 0;
            Node* root = nullptr;
            
        public:
            PrefixTree();
            ~PrefixTree();
            int get_size(); // O(1)
            Node* get_root(); // O(1)
            Node* find(int code);
            Node* add(Node* node, std::string object);
            void clear();
    };
}

#endif