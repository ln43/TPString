
all:	main

main:	main.o 
	g++  main.o -o main -g
	
main.o:	main.cpp 
	g++	-c	main.cpp	-o	main.o	--std=c++11	-g -Wall -Wextra
	
clean:
	rm -f *.o
