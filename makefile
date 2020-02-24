# makefile

CXX=g++
FLAGS=-std=c++11 -Wall -Wextra -Werror
DEPENDENCIES=main.o Quash.o underlying_structures/Minheap.o underlying_structures/Hashtable.o underlying_structures/node.o

# run: prog1.out
#	--leak-check=full ./prog1.out "insert 10, insert -50, insert 76, lookup 12, insert 12, lookup 12, insert 12, lookup 12, print, deleteMin, delete -50, print, delete 10, print, deleteMin, print, delete 12, deleteMin, print, deleteMin"

prog1.out: ${DEPENDENCIES}
	${CXX} $^ ${FLAGS} -o $@

clean:
	/bin/rm -f *.o underlying_structures/*.o prog1.out vgcore*
