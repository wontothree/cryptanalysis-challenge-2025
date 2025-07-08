CC = C:/msys64/mingw64/bin/gcc.exe
CXX = C:/msys64/mingw64/bin/g++.exe
CFLAGS = -Iinclude -Wall -Wextra -std=c11 -g
CXXFLAGS = -Iinclude -Wall -Wextra -std=c++11 -g -Wno-shadow -Wno-unused-parameter

BIN_DIR := bin
SRC_DIR := source
TEST_DIR := test
INCLUDE_DIR := include

all: $(BIN_DIR)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

clean:
	del /Q $(BIN_DIR)\*.exe 2>NUL || true
	del /Q *.o 2>NUL || true

.PHONY: all clean 