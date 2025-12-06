CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic

BIN := sort_search.exe
SRC := SortingAndSearch.cpp

all: $(BIN)

$(BIN): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $(SRC)

run: $(BIN)
	./$(BIN)

clean:
	rm -f $(BIN)

.PHONY: all run clean