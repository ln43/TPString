
all:	main

main:	main.o String.o
	g++  main.o String.o -o main -g
	
main.o:	main.cpp String.h
	g++	-c	main.cpp	-o	main.o	--std=c++11	-g -Wall -Wextra

String.o: String.cpp String.h
	g++	-c	String.cpp	-o	String.o	--std=c++11	-g -Wall -Wextra
	
clean:
	rm -f *.o
