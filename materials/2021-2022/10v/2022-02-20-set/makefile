DEPS_ARRAY = main.o set_array.o
DEPS_LIST = main.o list.o set_list.o
DEPS_MAP = main.o list.o set_map.o
DEPS_TREE = main.o bst.o list.o set_tree.o
CFLAGS = -Wall -lm -std=c11 -pedantic

all: set_array set_list set_map set_tree

set_array: ${DEPS_ARRAY}
	gcc ${CFLAGS} ${DEPS_ARRAY} -o $@.out

set_list: ${DEPS_LIST}
	gcc ${CFLAGS} ${DEPS_LIST} -o $@.out

set_map: ${DEPS_MAP}
	gcc ${CFLAGS} ${DEPS_MAP} -o $@.out

set_tree: ${DEPS_TREE}
	gcc ${CFLAGS} ${DEPS_TREE} -o $@.out

%.o: %.c
	gcc ${CFLAGS} -c $< -o $@

clean:
	rm *.out *.o
