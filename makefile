CC=g++
STD=c++11
CFLAGS=-Wall -Wextra -std=$(STD)
TARGET_NAME=smal
BUILD_PATH=./build
SOURCE_PATH=./src
LIB_PATH=./include
TARGET_PATH=$(BUILD_PATH)/$(TARGET_NAME)

SOURCE_EXT := cpp
SOURCES := $(shell find $(SOURCE_PATH) -path '*.$(SOURCE_EXT)')
OBJECTS := $(patsubst $(SOURCE_PATH)/%,$(BUILD_PATH)/%,$(SOURCES:.$(SOURCE_EXT)=.o))

all: $(TARGET_NAME)

$(BUILD_PATH)/%.o: $(SOURCE_PATH)/%.cpp $(LIB_PATH)/%.hpp
	mkdir -p $(@D)
	$(CC) -c $(CFLAGS) -o $@ $<

$(TARGET_NAME): $(OBJECTS) ./main.cpp
	$(CC) $(CFLAGS) -o $(TARGET_PATH) ./main.cpp $(OBJECTS)

clean:
	rm -rf $(BUILD_PATH)/*

run:
	$(TARGET_PATH) -c ./input/06.in ./output/06.z78
	$(TARGET_PATH) -x ./output/06.z78 ./output/06-decompressed.in
	diff -q ./input/06.in ./output/06-decompressed.in

mem:
	valgrind --leak-check=full --show-leak-kinds=all --log-file="./output/compress-mem.log" $(TARGET_PATH) -c ./input/04.in ./output/04.z78
	valgrind --leak-check=full --show-leak-kinds=all --log-file="./output/decompress-mem.log" $(TARGET_PATH) -x ./output/04.z78 ./output/04-decompressed.in