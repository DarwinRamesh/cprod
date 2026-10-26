# Compiler and flags
CXX      := clang++
CXXFLAGS := -Wall -Wextra -O2 -Iinclude -MMD -MP

# Linker flags (Raylib and system dependencies)
LDFLAGS  := -lraylib -lGL -lm -lpthread -lXrandr -ldl -lrt -lX11

# Target executable name
TARGET   := prod

# Source files, object files, and dependency tracking files
SRCS     := main.cpp date.cpp tasks.cpp
OBJS     := $(SRCS:.cpp=.o)
DEPS     := $(SRCS:.cpp=.d)

# Default rule: builds everything and runs the executable
all: $(TARGET)
	./$(TARGET)

# Link object files into the final executable
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) $(LDFLAGS) -o $(TARGET)

# Compile source files into individual object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Include the generated dependency files (.d) safely
-include $(DEPS)

# Clean up build artifacts
clean:
	rm -f $(OBJS) $(DEPS) $(TARGET)

.PHONY: all clean

