.PHONY:all
all:testo testso
testo:test.c	
	gcc -static -o $@ $^ -lmymath -L./lib
testso:test.c
	gcc -o $@ $^ -lmymath -L./lib

.PHONY:clean
clean:
	rm -rf testo testso
