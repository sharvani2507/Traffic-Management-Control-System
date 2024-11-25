# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall

# Source files and object files
SRC = main.cpp database.cpp data.cpp
OBJ = $(SRC:.cpp=.o)

# Output executable
EXEC = traffic_control_system

# Default target
all: $(EXEC)

# Linking object files to create the executable
$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $(EXEC)

# Compile each source file into an object file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Clean up object files and executable
clean:
	rm -f $(OBJ) $(EXEC)

.PHONY: all clean
