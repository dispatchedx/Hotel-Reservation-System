# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Iinclude

# Directories
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Main file
MAIN_FILE = Hotel_reservations.cpp

# Target executable
TARGET = $(BIN_DIR)/hotel_program

# Source files
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp) $(MAIN_FILE)

# Object files
OBJ_FILES = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(notdir $(SRC_FILES)))

# Create the necessary directories
$(shell mkdir -p $(OBJ_DIR) $(BIN_DIR))

# Default target
all: $(TARGET)

# Link the target executable
$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "Linked $(TARGET)"

# Compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "Compiled $< into $@"

$(OBJ_DIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "Compiled $< into $@"

# Clean up build files
clean:
	rm -rf $(OBJ_DIR)/*.o $(TARGET)
	@echo "Cleaned up build files"

# Phony targets
.PHONY: all clean
