# This makefile is designed to compile each .cpp file into an executable

CXX = g++
SRCS = $(wildcard *.cpp)
TARGETS = $(basename $(SRCS))
OBJS = $(SRC:%.cpp=%.o)
CXXFLAGS = -std=c++11 -Wall -g
RM = rm -rf

.PHONY: all clean

all : $(TARGETS)

# Generic rules should go before specialized rules
$(TARGETS): % : %.o
	$(CXX) -o $@ $<

$(OBJS): %.o : %.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

clean:
	$(RM) $(TARGETS) *.o
