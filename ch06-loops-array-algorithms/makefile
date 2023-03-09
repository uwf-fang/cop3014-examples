SHELL := /bin/bash
CXX := g++
LFLAGS :=
CXXFLAGS := -g -std=c++14 -Wall -Werror=return-type  -Werror=uninitialized \
			-Wno-sign-compare
RM := rm -rf
TARGETS := test-search
SOURCES := $(wildcard *.cpp)
HEADERS := $(wildcard *.hpp)
OBJECTS := $(SOURCES:.cpp=.o)

.PHONY: clean

all: $(TARGETS)

# General compilation rules
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $<

test-search: test-search.o search.o
	$(CXX) $(LFLAGS) -o $@ $^
	./$@

clean:
	$(RM) *.o $(TARGETS) *.gc* *.dSYM
