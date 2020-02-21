# makefile

CXX=g++
FLAGS=-std=c++11
DEPENDENCIES=main.o mainFuncs.o Quash.o Minheap.o Hashtable.o

prog1: ${DEPENDENCIES}
	${CXX} $^ ${FLAGS} -o $@

clean:
	/bin/rm -f *.o prog1
