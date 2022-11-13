# This makefile is designed to compile each .cpp file into an executable
SHELL := /bin/bash
CXX := g++
CXXFLAGS := -g -std=c++14 -Wall -Werror=return-type  -Werror=uninitialized \
			-Wno-sign-compare
RM := rm -rf
SRCS := $(wildcard *.cpp)
TARGETS := $(basename $(SRCS))
OBJS := $(SRC:%.cpp=%.o)
HEADERS := # Shared headers

.PHONY: all clean

all : $(TARGETS)

# Generic rules should go before specialized rules
$(TARGETS): % : %.o
	$(CXX) -o $@ $<

$(OBJS): %.o : %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	$(RM) $(TARGETS) *.o *.gc* *.dSYM
