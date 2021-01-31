#include<iostream>
#include<cstring>
#include<string>
#include<sstream>

#include"./include/tree/prefix-tree.hpp"
#include"./include/tree/node.hpp"
#include"./include/compressor.hpp"

int main(int argc, char const* argv[]){
    if(argc < 3){
        std::cout << "Not enough arguments...\n";
        exit(1);
    }

    std::string input_file_name(argv[2]);
    std::string output_file_name;
    std::stringstream output_file_name_stream;
    if(argc >= 4){
        output_file_name = std::string(argv[3]);
    }
    else{
        int name_slice_pos = input_file_name.find_last_of('.');
        output_file_name_stream << input_file_name.substr(0, name_slice_pos);
    }

    if(strncmp(argv[1], "-c", 3) == 0){
        if(argc < 4){
            output_file_name_stream << ".z78";
            output_file_name = output_file_name_stream.str();
        }
        std::cout << "compressing...\t\n";
        smal::Compressor::compress(input_file_name, output_file_name);
        std::cout << "\bdone!\n";
    }
    else if(strncmp(argv[1], "-x", 3) == 0){
        if(argc == 4){
            output_file_name_stream << ".txt";
            output_file_name = output_file_name_stream.str();
        }
        std::cout << "decompressing...\t\n";
        smal::Compressor::decompress(input_file_name, output_file_name);
        std::cout << "\bdone!\n";
    }
    else{
        std::cout << "Unkown option " << argv[1] << "\n";
        exit(1);
    }

    return 0;
}