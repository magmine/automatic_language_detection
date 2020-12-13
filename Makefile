trie : main_trie.o trie.o utils.o
	cc -o trie main.o trie.o utils.o

dawg : main_dawg.o dawg.o stack.o utils.o
	cc -o dawg main.o dawg.o utils.o stack.o

main_dawg.o : src/main_dawg.c src/utils.c src/dawg.c
	cc -c src/main_dawg.c
main_trie.o : src/main_trie.c src/utils.c src/trie.c
	cc -c src/main_trie.c
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