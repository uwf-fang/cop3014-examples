main: main.o my-class.o
	g++ -o $@ $^

main.o: main.cpp my-class.hpp
	g++ -std=c++11 -Wall -c -o $@ $<

my-class.o: my-class.cpp my-class.hpp
	g++ -std=c++11 -Wall -c -o $@ $<

clean:
	rm -f *.o main
