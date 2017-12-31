.PHONY:all
all:libmymath.a libmymath.so
OBJ=add.o sub.o mul.o


libmymath.a:$(OBJ)
	ar -rc $@ $^
	mv libmymath.a ../lib

libmymath.so:$(OBJ)
	gcc -shared -fPHC -o $@ $^
	mv libmymath.so ../lib

%.o:%.c
	gcc -c $^ -o $@ -I../include

	

.PHONY:clean
clean:
	rm -rf $(OBJ) 

