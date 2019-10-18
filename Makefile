CXX=clang++
CXXFLAGS= -Wall -g -std=c++11
LDFLAGS=

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
TARGET = node

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

.PHONY: clean
clean:
	rm -rf $(OBJ) $(TARGET)