CXX = g++
LIB = -lsystemc
#INCDIR = -I/usr/include
#LIBDIR = -L/usr/lib/x86_64-linux-gnu
CXXFLAGS = -std=c++14 -Wall
LDFLAGS = -lsystemc -lm

INCLUDES = -Iinclude
SRC_DIR = src
OBJ_DIR = obj

SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))

EXECUTABLE = main

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
	rm -rf $(OBJ_DIR)

.PHONY: all clean