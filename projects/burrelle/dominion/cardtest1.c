/**
 * cardtest1.c
 * Card test for the smithy card function that resides in domain.c
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>

#define CHECK "\u2713"
#define FAIL "\u274C"

int main()
{
	// Variable declarations
	struct gameState state, testState;
	int kingdom[10] = {
		adventurer, 
		gardens, 
		embargo, 
		village, 
		minion, 
		mine, 
		cutpurse,
        sea_hag, 
        tribute, 
        smithy
    };
    int deck, hand, played;
    int passedTests = 0;
    int failedTests = 0;

    printf("Testing smithy card: \n");

    /**
     * @brief Initialize game
     * 
     * @param players number of players playing the game
     * @param kingdom the kingdom cards array above
     * @param randomSeed a random number
     * @param gameState references above game state
     */
    initializeGame(2, kingdom, 2048, &state);
    state.hand[0][1] = smithy;

    deck = state.deckCount[0];
    hand = state.handCount[0];
    played = state.playedCardCount;

    /**
     * Test Case 1
     */
    memcpy(&testState, &state, sizeof(struct gameState));
    // Play the smithy card
    cardEffect(smithy, -1, -1, -1, &testState, 1, NULL);

    // +3 - 1 = +2 in hand.
    if (testState.handCount[0] == hand + 2)
    {
    	printf(CHECK " ");
    	passedTests++;
    } 
    else
    {
    	printf(FAIL " ");
    	failedTests++;
    }
    printf("Draw three cards and discard one should result in two cards added to hand\n");
    assert(testState.handCount[0] == hand + 2);

    /**
     * Test Case 2
     */
    memcpy(&testState, &state, sizeof(struct gameState));
    // Play the smithy card
    cardEffect(smithy, -1, -1, -1, &testState, 1, NULL);
    // Deck now has three less cards
    if (testState.deckCount[0] == deck - 3)
    {
    	printf(CHECK " ");
    	passedTests++;
    } 
    else
    {
    	printf(FAIL " ");
    	failedTests++;
    }
    printf("Remove three cards from the deck\n");
    assert(testState.deckCount[0] == deck - 3);

    /**
     * Test Case 3
     */
    memcpy(&testState, &state, sizeof(struct gameState));
    // Play the smithy card
    cardEffect(smithy, -1, -1, -1, &testState, 1, NULL);
    if(testState.playedCardCount == played + 1)
    {
    	printf(CHECK " ");
    	passedTests++;
    } 
    else
    {
    	printf(FAIL " ");
    	failedTests++;
    }
	printf("Card has been added to played pile\n");
    // Removed assertion because introduced bugs from assignment 2.
    // assert(testState.playedCardCount == played + 1);

    /**
     * Test Case 4
     */
     memcpy(&testState, &state, sizeof(struct gameState));
    // Play the smithy card
    cardEffect(smithy, -1, -1, -1, &testState, 1, NULL);
    if(testState.playedCards[testState.playedCardCount -1] == smithy)
    {
    	printf(CHECK " ");
    	passedTests++;
    } 
    else
    {
    	printf(FAIL " ");
    	failedTests++;
    }
	printf("Smithy was last played card\n");
    // Removed assertion because introduced bugs from assignment 2.
    // assert(testState.playedCards[testState.playedCardCount -1] == smithy);

    /**
     * Statisics reporting
     */
    printf("Smithy card test results: ");
    printf("Passed: %d. Failed: %d\n", passedTests, failedTests);
	
	return 0;
}

