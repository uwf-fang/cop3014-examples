$(CXX)=g++
CXXFLAGS=-std=c++11 -Wall

main: main.o student-group.o
	$(CXX) $(CXXFLAGS) -g -o $@ $^

main.o: main.cpp student-group.hpp
	$(CXX) $(CXXFLAGS) -g -c -o $@ $<

student-group.o: student-group.cpp student-group.hpp
	$(CXX) $(CXXFLAGS) -g -c -o $@ $<

clean:
	rm -rf main *.o