# Smal

A file comrpessor using LZ78 algorithm.

## Building

The source code includes a makefile, so to build the project, simply run ```make```. The executable output will be located at ```build/smal```. To make a clean build, use ```make clean && make```. You can test the execution by running ```make run``` to execute the compressor over a sample output.

## Usage

Compressing files:

```smal -c input_file [output_file]```

```input file``` is the file to be compressed, ```output_file``` is an optional output path for the compressed file, if none iss provided, the output file name will be the same as the input file with .z78 extensio.

Decompressing files:

```smal -x input_file [output_file]```

```input file``` is the file to be decompressed, ```output_file``` is an optional output path for the decompressed file, if none iss provided, the output file name will be the same as the input file with .txt extensio.