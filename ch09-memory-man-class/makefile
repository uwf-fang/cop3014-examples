all: test3 test5 test-shallow

test3: ruleOf3.cpp
	g++ -std=c++14 -o $@ $<

test5: ruleOf5.cpp
	g++ -std=c++14 -o $@ $<

test-shallow: shallow-copy.cpp
	g++ -std=c++14 -o $@ $<

clean:
	rm -f test3 test5 test-shallow
