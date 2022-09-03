CXX = g++
FLAGS = -Wall -std=c++14 -g

driver: driver.o store.o store-item.o
	$(CXX) -o $@ $^

driver.o: driver.cpp
	$(CXX) $(FLAGS) -c $^

store.o: store.cpp store.hpp
	$(CXX) $(FLAGS) -c $^

store-item.o: store-item.cpp store-item.hpp
	$(CXX) $(FLAGS) -c $^

clean:
	$(RM) -r *.dSYM
	$(RM) *.o *.gc* driver
