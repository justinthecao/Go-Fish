#should generate two executables - 1. game 2. tests
all:tests game
	./tests ./game

tests: cards.h cards.cpp tests.cpp
	g++ --std=c++11 -Wall cards.cpp tests.cpp -o tests 

game: cards.h cards.cpp main.cpp 
	g++ --std=c++11 -Wall cards.h cards.cpp main.cpp -o game 
clean: 
	rm tests game

