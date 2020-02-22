# makefile

CXX=g++
FLAGS=-std=c++11 -Wall -Wextra -Werror
DEPENDENCIES=main.o Quash.o underlying_structures/Minheap.o underlying_structures/Hashtable.o underlying_structures/node.o

prog1.out: ${DEPENDENCIES}
	${CXX} $^ ${FLAGS} -o $@

clean:
	/bin/rm -f *.o underlying_structures/*.o prog1.out
