OBJS=test.o my-vector.o
CXX=g++
FLAGS=-std=c++11 -Wall
RM=rm -rf

.PHONY: clean


# Target rules
test: $(OBJS)
	$(CXX) -o $@ $^

# General compilation rules
%.o: %.cpp
	$(CXX) $(FLAGS) -c $<

clean:
	$(RM) *.o $(TARGETS) *.gc* *.dSYM
