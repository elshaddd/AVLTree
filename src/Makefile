all: main researches test clean

main: main.o
	g++ main.o -o main

test: tests.o 
	g++ tests.o -lgtest -o test
	
researches: research.o
	g++ research.o -o researches


main.o:
	g++ -c *.cpp -Imodules
tests.o:
	g++ -c tests/*.cpp -lgtest -Imodules
research.o:
	g++ -c research/*.cpp -Imodules


clean:
	rm -f *.o