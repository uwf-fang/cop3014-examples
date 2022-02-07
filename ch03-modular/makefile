# Step-wise without special variables like $^, $<, etc.

CXX=g++
CXXFLAGS = -Wall

TARGETS = main

# catch all rule
all : $(TARGETS)

main : main.o threeintsfcts.o
	$(CXX) -o main main.o threeintsfcts.o

main.o : main.cpp threeintsfcts.hpp
	$(CXX) $(CXXFLAGS) -c $<

threeintsfcts.o : threeintsfcts.hpp threeintsfcts.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean :
	$(RM) -r *.dSYM
	$(RM) *.o *.gc* $(TARGETS)
