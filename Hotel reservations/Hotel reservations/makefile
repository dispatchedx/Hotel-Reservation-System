# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Iinclude

# Directories
SRC_DIR = src

# Main file
MAIN_FILE = Hotel_reservations.cpp

# Target executable
TARGET = hotel_program

# Source files
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp) $(MAIN_FILE)

# Object files
OBJ_FILES = $(patsubst %.cpp, %.o, $(notdir $(SRC_FILES)))

# Default target
all: $(TARGET) clean_obj

# Link the target executable
$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "Linked $(TARGET)"

# Compile source files into object files
%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "Compiled $< into $@"

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "Compiled $< into $@"

# Clean up object files
clean_obj:
	rm -f *.o
	@echo "Cleaned up object files"

# Clean up all build files
clean: clean_obj
	rm -f $(TARGET)
	@echo "Cleaned up all build files"

# Phony targets
.PHONY: all clean clean_obj
