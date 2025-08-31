# Compiler and flags
CXX = g++

# --- CORRECTED LINES ---
# Using absolute paths to avoid confusion between Git's and MSYS2's environments
CXXFLAGS = -std=c++17 -Wall -I./include -I"C:/msys64/ucrt64/include" -I"C:/msys64/ucrt64/include/postgresql"
LDFLAGS = -L"C:/msys64/ucrt64/lib" -lpqxx -lpq
# --- END OF CORRECTED LINES ---

# Directories
SRCDIR = src
INCDIR = include
BINDIR = bin

# Find all .cpp files in the source directory
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
# Replace the .cpp extension with .o for object files
OBJECTS = $(SOURCES:.cpp=.o)

# The final executable name
TARGET = $(BINDIR)/VeritasSCM

# Default rule: build the executable
all: $(TARGET)

# Rule to link the object files into the final executable
$(TARGET): $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CXX) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

# Rule to compile a .cpp file into a .o object file
# $< is the source file, $@ is the target file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to clean up compiled files
clean:
	rm -f $(SR_FILES) $(TARGET)