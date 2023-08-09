# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++11

# Application name
APP_NAME := ZenMode

# Source files and output directory
SRC := main.cpp
OBJ_DIR := obj
OBJ := $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.cpp=.o)))

# Application bundle directory
APP_BUNDLE := $(APP_NAME).app
APP_DIR := $(APP_BUNDLE)/Contents/MacOS

# Default target
all: $(APP_NAME)

# Compile C++ source files
$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link object files to create the application executable
$(APP_NAME): $(OBJ) | $(APP_BUNDLE)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(APP_DIR)/$(APP_NAME)

# Create the application bundle directory
$(APP_BUNDLE):
	mkdir -p $(APP_DIR)

# Clean build files
clean:
	rm -rf $(OBJ_DIR) $(APP_BUNDLE)

# Create the obj directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)