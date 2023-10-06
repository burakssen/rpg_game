# Define compiler and flags for C++
CXX := g++
CXXFLAGS := -Wall -Wextra -g -std=c++20
LDFLAGS := -framework IOKit -framework Cocoa -framework OpenGL
SRCDIR := src
OBJDIR := obj
BINDIR := bin
INCDIR := include
LIBDIR := lib  # Add your library directory here
LIBS := raylib
EXECUTABLENAME := rpg_game

# Find all source files in the src directory and its subdirectories
SOURCES := $(shell find $(SRCDIR) -type f -name '*.cpp')
# Generate corresponding object file names
OBJECTS := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))
# Name of the final executable
EXECUTABLE := $(BINDIR)/$(EXECUTABLENAME)

# Main target: the executable
$(EXECUTABLE): $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CXX) $(LDFLAGS) -L$(LIBDIR) $^ $(addprefix -l, $(LIBS)) -o $@

# Rule to compile a source file into an object file
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

# Phony target to clean the project
.PHONY: clean
clean:
	rm -rf $(OBJDIR) $(BINDIR)

# Default target
all: $(EXECUTABLE)

run:
	./$(BINDIR)/$(EXECUTABLENAME)

# Print a message when make is run without any target
.DEFAULT_GOAL := all
