trie : main.o trie.o utils.o
	cc -o trie main.o trie.o utils.o

dawg : main.o dawg.o stack.o utils.o
	cc -o dawg main.o dawg.o utils.o stack.o

main.o : src/main.c src/utils.c src/trie.c
	cc -c src/main.c
trie.o : src/trie.c
	cc -c src/trie.c
utils.o : src/utils.c
	cc -c src/utils.c
dawg.o : src/dawg.c src/stack.c src/hashmap.h
	cc -c src/dawg.c
stack.o : stack.c
	cc -c src/stack.c
clean :
	rm trie dawg main.o trie.o utils.o stack.o dawg.o