#Makefile
#Zachary Friedland and Sara Mandic
#06-06-19

all: movies.cpp main.cpp tests.cpp
	g++ -g -std=c++11 movies.cpp main.cpp -o runMovies 
	g++ -g -std=c++11 movies.cpp tests.cpp -o tests

runMovies: movies.cpp main.cpp
	g++ -g -std=c++11 movies.cpp main.cpp -o runMovies

tests: movies.cpp tests.cpp
	g++ -g -std=c++11 movies.cpp tests.cpp -o tests

clean:
	rm runMovies tests
