/*
 * unittest4.c 5/5/19
*/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "playFeast()"

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
	int k[10] = {adventurer, embargo, village, minion, estate, cutpurse,
			sea_hag, feast, smithy, council_room};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	printf("----------------- Testing Function: %s ----------------\n", TESTCARD);

	// ----------- TEST 1: NEGATIVE TEST  --------------
	printf("POSITIVE TEST CASE 1: valid input: Hand count should remain same when swap\n");
    choice1 = 1;//purchase less expensive card 
	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	printf("BEFORE CARD IS PLAYED:\n");
    int num = testG.handCount[thisPlayer];
    printf("\tcurrent player hand count = %d\n", testG.handCount[thisPlayer]);
    printf("\tcurrent player deck count = %d\n", testG.deckCount[thisPlayer]);
    printf("\tcoins = %d\n", testG.coins);

	cardEffect(feast, choice1, choice2, choice3, &testG, handpos, &bonus);

    
	printf("AFTER CARD IS PLAYED:\n");
    printf("\tcurrent player hand count = %d, expected = %d\n", testG.handCount[thisPlayer], num);
    if (testG.handCount[thisPlayer] == num)
    {
        printf("PASS! did not gain or lose card\n");//successfully bought card
    } else {
        printf("FAIL! lost or gained a card\n");
    }

    printf("\tcurrent player deck count = %d\n", testG.deckCount[thisPlayer]);
    printf("\tcoins = %d\n", testG.coins);


	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);


	return 0;
}

