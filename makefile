PROJ_NAME = Matrix_Calculator
SRC = main.c 


build:
	gcc 3_Implementation/main.c

run: build
	./a.out

clean:
	rm ./a.out
