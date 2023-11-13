all: main researches test clean

main: main.o
	g++ main.o AVLTree.o Node.o -o main

test: tests.o 
	g++ tests.o AVLTree.o Node.o -lgtest -o test
	
researches: research.o
	g++ research.o AVLTree.o Node.o -o researches


main.o: modules.o
	g++ -c *.cpp -Imodules
tests.o: modules.o
	g++ -c tests/*.cpp -lgtest -Imodules
research.o: modules.o
	g++ -c research/*.cpp -Imodules
modules.o:
	g++ -c modules/AVLTree/*.cpp  modules/Node/*.cpp -Imodules

clean:
	rm -f *.o