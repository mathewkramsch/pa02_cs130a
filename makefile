# makefile

CXX=g++
FLAGS=-std=c++11
DEPENDENCIES=main.o main_helper/mainFuncs.o Quash.o underlying_structures/Minheap.o underlying_structures/Hashtable.o

prog1.out: ${DEPENDENCIES}
	${CXX} $^ ${FLAGS} -o $@

clean:
	/bin/rm -f *.o prog1
