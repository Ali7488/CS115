CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic -g

SOURCES := $(wildcard *.cpp)
EXES := $(SOURCES:.cpp=.exe)

all: $(EXES)

%.exe: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

run: $(EXES)
	@if [ -z "$(EXE)" ]; then echo "Set EXE=<name>.exe (e.g., make run EXE=matrix.exe)"; exit 1; fi
	@./$(EXE)

clean:
	rm -f $(EXES)
