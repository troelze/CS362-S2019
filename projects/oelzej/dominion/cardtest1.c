/*
 * cardtest1.c 5/5/19
*/


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "smithy"

int main() {
    int newCards = 3;
    int discarded = 1;
    int shuffledCards = 0;

    int i, j, m;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int remove1, remove2;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	// ----------- TEST 1: NEGATIVE - invalid input - handPos set to 1--------------
    printf("NEGATIVE TEST: invalid input for handpos\n");
	printf("BEFORE CARD IS PLAYED:\n");
	// copy the game state to a test case
    handpos = 1;
	memcpy(&testG, &G, sizeof(struct gameState));
	printf("\thand count = %d\n", testG.handCount[thisPlayer]);
	cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);
	printf("AFTER CARD IS PLAYED:\n\thand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
	printf("\tdeck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
	
    if (testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded)
    {
        printf("hand count PASS\n");
    }else{
        printf("hand count FAIL\n");
    }

    if (testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards)
    {
        printf("deck count PASS\n");
    }else{
        printf("deck count FAIL\n");
    }

	printf("\n >>>>> Testing complete %s <<<<<\n\n", TESTCARD);

	return 0;
}

