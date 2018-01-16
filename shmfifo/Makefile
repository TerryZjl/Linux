.PHONY:all
all:put get
put:put.c shmfifo.c
	gcc -o $@ $^
get:get.c shmfifo.c
	gcc -o $@ $^

.PHONY:clean
clean:
	rm -rf put get
