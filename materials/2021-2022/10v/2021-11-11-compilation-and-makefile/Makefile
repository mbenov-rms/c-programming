DEPS = main.o queue.o bin_tree.o

all: ${DEPS}
	gcc -Wall ${DEPS}
	
%.o: %.c
	gcc -Wall -c $< -o $@
	
clean:
	rm a.out *.o
