/*
 * unittest2.c 5/5/19
*/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "playCouncilRoom()"

int main() {
    int newCards = 4;
    int newCards2 = 1;
    int discarded = 0;
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

	printf("----------------- Testing Function: %s ----------------\n", TESTCARD);

	// ----------- TEST 1: --------------
	printf("POSITIVE TEST: valid input \n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	printf("BEFORE CARD IS PLAYED:\n\tnumBuys = %d\n", testG.numBuys);
    int num2 = testG.numBuys;
    printf("\tcurrent player hand count = %d\n", testG.handCount[thisPlayer]);//print both players count before council room is played
    thisPlayer++;
    printf("\tcurrent player deck count = %d\n", testG.deckCount[thisPlayer]);
    thisPlayer--;
    printf("\tother player hand count = %d\n", testG.handCount[thisPlayer]);
    thisPlayer++;
    printf("\tother player deck count = %d\n", testG.deckCount[thisPlayer]);
    thisPlayer--;

	cardEffect(council_room, choice1, choice2, choice3, &testG, handpos, &bonus);

	printf("AFTER CARD IS PLAYED:\n\tcurrent player: hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
    if (testG.handCount[thisPlayer] == (G.handCount[thisPlayer] + newCards - discarded))
    {
        printf("PASS!\n");
    }else {
        printf("FAIL!\n");
    }
	printf("\tdeck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
    
    if (testG.deckCount[thisPlayer] == (G.deckCount[thisPlayer] - newCards + shuffledCards))
    {
        printf("PASS!\n");
    }else {
        printf("FAIL!\n");
    }
    thisPlayer++;
    printf("\tother player: hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards2 - discarded);
    if (testG.handCount[thisPlayer] == (G.handCount[thisPlayer] + newCards2 - discarded))
    {
        printf("PASS!\n");
    }else {
        printf("FAIL!\n");
    }
	printf("\tdeck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards2 + shuffledCards);
    if (testG.deckCount[thisPlayer] == (G.deckCount[thisPlayer] - newCards2 + shuffledCards))
    {
        printf("PASS!\n");
    }else {
        printf("FAIL!\n");
    }
    thisPlayer--;
    int num1 = testG.numBuys;
    printf("\tnumBuys = %d\n", testG.numBuys);
    int dif = num1 - num2;
    if (dif == 1){
        printf("PASS!\n");
    }else {
        printf("FAIL!\n");
    }

	printf("\n >>>>> Testing complete %s <<<<<\n\n", TESTCARD);


	return 0;
}

