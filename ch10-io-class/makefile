$(CXX)=g++
CXXFLAGS=-std=c++11 -Wall

main: main.o student-group.o
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: main.cpp student-group.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

student-group.o: student-group.cpp student-group.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -rf main *.o