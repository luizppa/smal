#ifndef COMPRESSOR_H
#define COMPRESSOR_H

namespace smal {

    class Compressor{

        private:


        public:
            static void compress(std::string input_path, std::string output_path);
            static void decompress(std::string input_path, std::string output_path);
    };
}

#endif