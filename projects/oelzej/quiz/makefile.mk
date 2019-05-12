CFLAGS = -Wall -fpic -coverage -lm -std=c99

default: testme.out

testme.out: testme.c
	
	gcc -o testme testme.c $(CFLAGS)
	./testme
	gcov testme.c

clean:
	rm testme.out

cleanall: 
	rm testme *.gcda *.gcno *.gcov
