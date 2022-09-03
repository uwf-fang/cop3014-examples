CXX=g++
CXXFLAGS=-std=c++14 -Wall -Wno-sign-compare -g
HEADERS=../utility/testing-helper.hpp

test-vector: vector.o
	$(CXX) -o $@ $^
	./$@

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -rf test-vector *.o
