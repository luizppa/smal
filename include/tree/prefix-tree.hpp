#ifndef TREE_H
#define TREE_H

#include<string>

#include"./node.hpp"

namespace tree{

    class PrefixTree{

        private:
            int size = 0;
            int height = 0;
            int leaves = 0;
            Node* root = nullptr;
            
        public:
            PrefixTree();
            ~PrefixTree();
            int get_size(); // O(1)
            int get_height(); // O(1)
            void add(stdd::string object);
            Node* get_root(); // O(1)
            void each(void (*callback)(std::string));
            void each(void (*callback)(std::string, char*));
            void remove(Node*); // O(1)
            void clear();
    };
}

#endif