stack: stack.o
	g++ -std=c++11 -o $@ $^

%.o: %.cpp
	g++ -std=c++11 -c -o $@ $^


.PHONY: clean
clean:
	rm -rf stack stack.o
	