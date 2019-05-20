/**********************************************
 * randomtestadventurer.c
 * *******************************************/


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <time.h>

#define DEBUG 0
#define NOISY_TEST 1

int checkAdventurer(struct gameState *state) {
  int r;
  r = playAdventurer(state);

  assert (r == 0);
}

int main () {

  int i, n, r, p, deckCount, discardCount, handCount, smithyPos;

  int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

  struct gameState G;


  printf ("Testing playAdventurer.\n");

  SelectStream(2);
  PutSeed(3);

  clock_t start, end;
  double cpu_time_used;
  
  start = clock();

  for (n = 0; n < 100; n++) {
    for (i = 0; i < sizeof(struct gameState); i++) {
      ((char*)&G)[i] = floor(Random() * 256);
    }
    p = floor(Random() * 2);

    G.whoseTurn = p;
    G.deckCount[p] = floor(Random() * MAX_DECK);
    G.discardCount[p] = floor(Random() * MAX_DECK);
    G.handCount[p] = floor(Random() * MAX_HAND);

    int handCount = G.handCount[p];
    int handIndex;

    int deckCount = G.deckCount[p];
    int deckIndex;

    for (handIndex = 0; handIndex < handCount; handIndex++)
    {
        G.hand[p][handIndex] = floor(Random() * 26);
    }

    for (deckIndex = 0; deckIndex < deckCount; deckIndex++)
    {
        G.deck[p][deckIndex] = floor(Random() * 26);
    }



    G.playedCardCount = floor(Random() * handCount);

    checkAdventurer(&G);
  }

  end = clock();

  cpu_time_used = ((double) (end-start)) / CLOCKS_PER_SEC;

  printf ("ALL TESTS OK\nELAPSED TIME: %f seconds\n", cpu_time_used);

  exit(0);

  return 0;
}
