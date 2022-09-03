TARGETS=main
OBJS=main.o search.o
CXX=g++
FLAGS=-std=c++14 -Wall
RM=rm -rf

.PHONY: clean

all: $(TARGETS)

# Target rules
main: $(OBJS)
	$(CXX) -o $@ $^

# General compilation rules
%.o: %.cpp
	$(CXX) $(FLAGS) -c $<

clean:
	$(RM) *.o $(TARGETS) *.gc* *.dSYM
