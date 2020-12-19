sources = *.cpp
target = stack
CXX = g++
CCFLAG = -g -Wall -fsanitize=address -std=c++17

all:
	$(CXX) $(CCFLAG) $(sources) -o $(target)

clean:
	rm -f $(target)