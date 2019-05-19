/*
 * unittest3.c 5/5/19
*/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "playAdventurer()"

int main() {
    int newCards = 4;
    int newCards2 = 1;
    int discarded = 0;
    int shuffledCards = 0;
    int xtraCoins = 2;

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

	printf("----------------- Testing Function: %s ----------------\n", TESTCARD);

	// ----------- TEST 1: choice1 = 1 = +2 cards --------------
	printf("POSITIVE TEST CASE - valid input \n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));

	printf("BEFORE CARD IS PLAYED:\n");
    printf("\tcurrent player hand count = %d\n", testG.handCount[thisPlayer]);
    printf("\tcurrent player deck count = %d\n", testG.deckCount[thisPlayer]);
    int drawntreasure1 = 0;
    for (i=0; i<testG.handCount[thisPlayer]; i++) {
		if(testG.hand[thisPlayer][i] == copper || testG.hand[thisPlayer][i] == silver || testG.hand[thisPlayer][i] == gold)
            drawntreasure1++;
    }

    printf("\ttreasures = %d\n", drawntreasure1);
    
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);

	printf("AFTER CARD IS PLAYED:\n");
    int drawntreasure = 0;
    for (i=0; i<testG.handCount[thisPlayer]; i++) {
		if(testG.hand[thisPlayer][i] == copper || testG.hand[thisPlayer][i] == silver || testG.hand[thisPlayer][i] == gold)
            drawntreasure++;
    }

    printf("\ttreasures: %d, expected: %d\n", drawntreasure, drawntreasure1 + 2);

    if ((drawntreasure - drawntreasure1) == 2){
        printf("PASS! gained 2 treasures\n");
    } else {
        printf("FAIL! did not gain 2 treasures\n");
    }
    printf("\tcurrent player hand count = %d\n", testG.handCount[thisPlayer]);
    printf("\tcurrent player deck count = %d\n", testG.deckCount[thisPlayer]);

	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);
	return 0;
}

