/**********************************************
 * randomtestcard2.c
 * *******************************************/


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define DEBUG 0
#define NOISY_TEST 1

int checkSmithy(struct gameState *state, int currentPlayer, int handPos) {
  int r;
    
  r = playSmithy(state, currentPlayer, handPos);

  

  assert (r == 0);
}

int main () {

  int i, n, r, p, deckCount, discardCount, handCount, smithyPos;

  int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

  struct gameState G;


  printf ("Testing playSmithy.\n");

  printf ("RANDOM TESTS.\n");

  SelectStream(2);
  PutSeed(3);

  for (n = 0; n < 100; n++) {
    for (i = 0; i < sizeof(struct gameState); i++) {
      ((char*)&G)[i] = floor(Random() * 256);
    }
    p = floor(Random() * 2);

    
    G.deckCount[p] = floor(Random() * MAX_DECK);
    G.discardCount[p] = floor(Random() * MAX_DECK);
    G.handCount[p] = floor(Random() * MAX_HAND);

    int handCount = G.handCount[p];
    int handIndex;
    int smithyPos = floor(Random() * handCount);

    for (handIndex = 0; handIndex < handCount; handIndex++)
    {
        if (handIndex == smithyPos)
        {
            G.hand[p][handIndex] = 13;
        } else {
            G.hand[p][handIndex] = floor(Random() * 26);
        }
    }

    G.playedCardCount = floor(Random() * handCount);

    checkSmithy(&G, p, smithyPos);
  }

  printf ("ALL TESTS OK\n");

  exit(0);

  return 0;
}
