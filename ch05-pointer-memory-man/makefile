TARGETS=test
OBJS=test.o my-vector.o
CXX=g++
FLAGS=-std=c++14 -Wall
RM=rm -rf

.PHONY: clean

all: $(TARGETS)

# Target rules
test: $(OBJS)
	$(CXX) -o $@ $^

# General compilation rules
%.o: %.cpp
	$(CXX) $(FLAGS) -c $<

clean:
	$(RM) *.o $(TARGETS) *.gc* *.dSYM
