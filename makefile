PROJ_NAME = Matrix_Calculator
SRC = Calc.c 



build:
	gcc 3_Implementation/Calc.c

run: build
	./a.out

clean:
	rm ./a.out
