.PHONY: all

all: ex4 ex5
	echo "Testando ex4"
	-valgrind ./ex4
	echo "Testando ex5"
	-valgrind ./ex5

ex4: ex4.c
	gcc -Og -g ex4.c -o ex4
	valgrind ./ex4

ex5: ex5.c
	gcc -Og -g ex5.c -o ex5
	valgrind ./ex5
