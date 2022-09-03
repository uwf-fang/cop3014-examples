CXX=g++
CXXFLAGS=-std=c++14 -Wall

main: io-demo.o
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -rf main *.o
