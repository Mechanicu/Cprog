sources = *.cpp */*.cpp
target = benchmark
CXX = g++
CCFLAG = -Wall -fsanitize=address -std=c++17

all:
	$(CXX) $(CCFLAG) $(sources) -o $(target)

clean:
	rm -f $(target)