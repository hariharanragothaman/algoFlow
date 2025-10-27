# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra

# Specify the source directory and output directories
SRC_DIR := algoFlow
EXEC_DIR := bin

# Find all .cpp files and generate corresponding executable names
SOURCES := $(shell find $(SRC_DIR) -name '*.cpp')
EXECUTABLES := $(patsubst $(SRC_DIR)/%.cpp,$(EXEC_DIR)/%,$(SOURCES))

# Default target: Build all executables
all: $(EXEC_DIR) $(EXECUTABLES)

# Rule to build executables
$(EXEC_DIR)/%: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)  # Ensure the output directory exists
	$(CXX) $(CXXFLAGS) $< -o $@

# Create necessary directories
$(EXEC_DIR):
	@mkdir -p $(EXEC_DIR)

# Rule to clean build and executables
clean:
	rm -rf $(EXEC_DIR)

# Build only the specified file (no dependency on all)
file:
	echo "Executing this only file"
	@mkdir -p $(EXEC_DIR)
	$(CXX) $(CXXFLAGS) $(file) -o $(EXEC_DIR)/$(notdir $(basename $(file)))
