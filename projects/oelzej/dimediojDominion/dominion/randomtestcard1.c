/**********************************************
 * randomtestcard1.c
 * *******************************************/


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define DEBUG 0
#define NOISY_TEST 1

int checkCouncilRoom(struct gameState *state, int handPos) {

  int r;
  r = playCouncilRoom(state, handPos);

  assert (r == 0);
}

int main () {

  int i, n, r, p, deckCount, discardCount, handCount, smithyPos;

  int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

  struct gameState G;


  printf ("Testing playCouncilRoom.\n");

  SelectStream(2);
  PutSeed(3);

  for (n = 0; n < 100; n++) {
    for (i = 0; i < sizeof(struct gameState); i++) {
      ((char*)&G)[i] = floor(Random() * 256);
    }
    p = floor(Random() * 2);
   
    G.numPlayers = 2;

    G.whoseTurn = p;
    G.numBuys = floor(Random() * 5);

    int council_roomPOS;
    int j;
    for (j = 0; j < 2; j++)
    {
        G.deckCount[j] = floor(Random() * MAX_DECK);
        G.discardCount[j] = floor(Random() * MAX_DECK);
        G.handCount[j] = floor(Random() * MAX_HAND);

        int handCount = G.handCount[j];
        int handIndex;

        int deckCount = G.deckCount[j];
        int deckIndex;

        for (deckIndex = 0; deckIndex < deckCount; deckIndex++)
        {
            G.deck[j][deckIndex] = floor(Random() * 26);
        }
    
        council_roomPOS = floor(Random() * handCount);
        for (handIndex = 0; handIndex < handCount; handIndex++)
        {
            if (handIndex == smithyPos)
            {
                G.hand[j][handIndex] = 8;
            } else {
                G.hand[j][handIndex] = floor(Random() * 26);
            }
        }
    }
    
    

    G.playedCardCount = floor(Random() * handCount);

    checkCouncilRoom(&G, council_roomPOS);
  }

  printf ("ALL TESTS OK\n");

  exit(0);

  return 0;
}
