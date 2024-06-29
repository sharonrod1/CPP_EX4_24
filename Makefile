
CXX = g++

CXXFLAGS = -std=c++17 -Wall

SOURCES = Demo.cpp 
HEADERS = node.hpp tree.hpp
OBJECTS = $(SOURCES:.cpp=.o)

EXEC = demo

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXEC)
