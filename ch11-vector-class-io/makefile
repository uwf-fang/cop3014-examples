CXX=g++
CXXFLAGS=-std=c++14 -Wall

grades-app: grades-app.o grades.o
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp grades.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	$(RM) grades-app *.o
