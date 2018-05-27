CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

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

cardtest1: dominion.o smithy_test.c
	gcc -o cardtest1 smithy_test.c -g dominion.o rngs.o $(CFLAGS)

cardtest2: dominion.o adventurer_test.c
	gcc -o cardtest2 adventurer_test.c -g dominion.o rngs.o $(CFLAGS)

cardtest3: dominion.o sea_hag_test.c
	gcc -o cardtest3 sea_hag_test.c -g dominion.o rngs.o $(CFLAGS)	

cardtest4: dominion.o minion_test.c
	gcc -o cardtest4 minion_test.c -g dominion.o rngs.o $(CFLAGS)

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 

unittestresults.out: cardtest1 cardtest2 cardtest3 cardtest4
	./cardtest1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./cardtest2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./cardtest3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./cardtest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

smithy_random.out: dominion.o smithy_random.c
	gcc -o smithy_random smithy_random.c -g dominion.o rngs.o $(CFLAGS)
	./smithy_random >> smithy_random.out

adventurer_random.out: dominion.o adventurer_random.c
	gcc -o adventurer_random adventurer_random.c -g dominion.o rngs.o $(CFLAGS)
	./adventurer_random >> adventurer_random.out

embargo_random.out: dominion.o embargo_random.c
	gcc -o embargo_random embargo_random.c -g dominion.o rngs.o $(CFLAGS)
	./embargo_random >> embargo_random.out

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe cardtest1 cardtest2 cardtest3 cardtest4 smithy_random adventurer_random embargo_random
