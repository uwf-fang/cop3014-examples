CXX=g++
CXXFLAGS=-std=c++11 -Wall
HEADERS=../utility/testing-helper.hpp

test-vector: vector.o
	$(CXX) -o $@ $^
	./$@

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -rf test-vector *.o
