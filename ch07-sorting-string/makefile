CXX = g++
TARGETS = loop-string sort string
SRCS = $(wildcard *.cpp)
OBJS = $(SRC:%.cpp=%.o)
UTILS = util.o
CXXFLAGS = -std=c++11 -Wall
RM = rm -rf

.PHONY: all clean

all : $(TARGETS)

# Generic rules should go before specialized rules
$(TARGETS): % : %.o $(UTILS)
	$(CXX) -o $@ $^

$(OBJS): %.o : %.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

clean:
	$(RM) $(TARGETS) *.o  *.gc* *.dSYM
