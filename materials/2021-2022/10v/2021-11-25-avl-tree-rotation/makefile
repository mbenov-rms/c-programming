DEPS = main.o queue.o avl_tree.o
CFLAGS = -Wall -lm -std=c11 -pedantic

all: ${DEPS}
	gcc ${CFLAGS} ${DEPS} -o avl_tree.out

%.o: %.c
	gcc ${CFLAGS} -c $< -o $@

clean:
	rm a.out *.o
