CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)


#########

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out
	
randomtestresults: randomtestcard2.c randomtestadventurer.c dominion.c rngs.c
        echo "Result for running randomtestcard1:" > randomtestresults.out
        echo "randomtestcard1.c:" >> randomtestresults.out
        gcc -o randomtestcard1 rngs.c dominion.c randomtestcard1.c $(CFLAGS)
        ./randomtestcard1 >> randomtestresults.out
        gcov dominion.c -bf >> randomtestresults.out

        echo "Result for running randomtestcard2:" >> randomtestresults.out
        echo "randomtestcard2.c:" >> randomtestresults.out
        gcc -o randomtestcard2 rngs.c dominion.c randomtestcard2.c $(CFLAGS)
        ./randomtestcard2 >> randomtestresults.out
        gcov dominion.c -bf >> randomtestresults.out

        echo "Result for running randomtestadventurer:" >> randomtestresults.out
        echo "randomtestadventurer.c:" >> randomtestresults.out
        gcc -o randomtestadventurer rngs.c dominion.c randomtestadventurer.c $(CFLAGS)
        ./randomtestadventurer >> randomtestresults.out
        gcov dominion.c -bf >> randomtestresults.out
	
unittestresults.out: unittest1.c unittest2.c unittest3.c unittest4.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c dominion.c rngs.c
	echo "Result for running unittest1:" > unittestresults.out
	echo "unittest1.c:" >> unittestresults.out
	gcc -o unittest1 rngs.c dominion.c unittest1.c $(CFLAGS)
	./unittest1 >> unittestresults.out
	gcov dominion.c -bf >> unittestresults.out
	
	echo "Result for running unittest2:" >> unittestresults.out
	echo "unittest2.c:" >> unittestresults.out
	gcc -o unittest2 rngs.c dominion.c unittest2.c $(CFLAGS)
	./unittest2 >> unittestresults.out
	gcov dominion.c -bf >> unittestresults.out
	
	echo "Result for running unittest3:" >> unittestresults.out
	echo "unittest3.c:" >> unittestresults.out
	gcc -o unittest3 rngs.c dominion.c unittest3.c $(CFLAGS)
	./unittest3 >> unittestresults.out
	gcov dominion.c -bf >> unittestresults.out
	
	echo "Result for running unittest4:" >> unittestresults.out
	echo "unittest4.c:" >> unittestresults.out
	gcc -o unittest4 rngs.c dominion.c unittest4.c $(CFLAGS)
	./unittest4 >> unittestresults.out
	gcov dominion.c -bf >> unittestresults.out
	
	echo "Result for running cardtest1:" >> unittestresults.out
	echo "cardtest1.c:" >> unittestresults.out
	gcc -o cardtest1 rngs.c dominion.c cardtest1.c $(CFLAGS)
	./cardtest1 >> unittestresults.out
	gcov dominion.c -bf >> unittestresults.out
	
	echo "Result for running cardtest2:" >> unittestresults.out
	echo "cardtest2.c:" >> unittestresults.out
	gcc -o cardtest2 rngs.c dominion.c cardtest2.c $(CFLAGS)
	./cardtest2 >> unittestresults.out
	gcov dominion.c -bf >> unittestresults.out
	
	echo "Result for running cardtest3:" >> unittestresults.out
	echo "cardtest3.c:" >> unittestresults.out
	gcc -o cardtest3 rngs.c dominion.c cardtest3.c $(CFLAGS)
	./cardtest3 >> unittestresults.out
	gcov dominion.c -bf >> unittestresults.out
	
	echo "Result for running cardtest4:" >> unittestresults.out
	echo "cardtest4.c:" >> unittestresults.out
	gcc -o cardtest4 rngs.c dominion.c cardtest4.c $(CFLAGS)
	./cardtest4 >> unittestresults.out
	gcov dominion.c -bf >> unittestresults.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe unittestresults.out
