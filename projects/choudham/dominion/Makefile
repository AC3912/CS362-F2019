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

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

unittestresults.out: unittest1.c unittest2.c unittest3.c unittest4.c unittest5.c dominion.c rngs.c
	gcc -o unittest1 unittest1.c dominion.c rngs.c $(CFLAGS)
		unittest1 >> unittestresults.out
		gcov unittest1.c >> unittestresults.out
		gcov -f -b dominion.c >> unittestresults.out
	gcc -o unittest2 unittest2.c dominion.c rngs.c $(CFLAGS)
		unittest2 >> unittestresults.out
		gcov unittest2.c >> unittestresults.out
		gcov -f -b dominion.c >> unittestresults.out
	gcc -o unittest3 unittest3.c dominion.c rngs.c $(CFLAGS)
		unittest3 >> unittestresults.out
		gcov unittest3.c >> unittestresults.out
		gcov -f -b dominion.c >> unittestresults.out
	gcc -o unittest4 unittest4.c dominion.c rngs.c $(CFLAGS)
		unittest4 >> unittestresults.out
		gcov unittest4.c >> unittestresults.out
		gcov -f -b dominion.c >> unittestresults.out
	gcc -o unittest5 unittest5.c dominion.c rngs.c $(CFLAGS)
		unittest5 >> unittestresults.out
		gcov unittest5.c >> unittestresults.out
		gcov -f -b dominion.c >> unittestresults.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 

clean:
	rm -f *.o playdom.exe playdom player player.exe unittest1 unittest1.exe unittest2 unittest2.exe unittest3 unittest3.exe unittest4.exe unittest4 unittest5.exe unittest5 *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
