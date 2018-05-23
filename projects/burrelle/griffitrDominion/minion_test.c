/**
 * minion_test.c
 * Card test for the sea_hag in dominion.c
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
        smithy};
    int deck, hand, discard;
    int passedTests = 0;
    int failedTests = 0;

    printf("Testing minion card: \n");

    /**
     * @brief Initialize game
     * 
     * @param players number of players playing the game
     * @param kingdom the kingdom cards array above
     * @param randomSeed a random number
     * @param gameState references above game state
     */
    initializeGame(2, kingdom, 2048, &state);
    state.hand[0][1] = minion;

    deck = state.deckCount[0];
    hand = state.handCount[0];
    discard = state.discardCount[0];

    /**
     * Test Case 1
     */
    memcpy(&testState, &state, sizeof(struct gameState));
    // Play the minion card
    cardEffect(minion, -1, -1, -1, &testState, 1, NULL);
    if (testState.handCount[0] == hand - 1)
    {
        printf(CHECK " ");
        passedTests++;
    }
    else
    {
        printf(FAIL " ");
        failedTests++;
    }
    printf("Choice one: one less card in the hand. \n");

    /**
     * Test Case 2
     */
    memcpy(&testState, &state, sizeof(struct gameState));
    // Play the minion card
    cardEffect(minion, -1, -1, -1, &testState, 1, NULL);
    // Deck now has three less cards
    if (testState.deckCount[0] == deck)
    {
        printf(CHECK " ");
        passedTests++;
    }
    else
    {
        printf(FAIL " ");
        failedTests++;
    }
    printf("Deck remains unchanged. \n");
    // assert(testState.deckCount[0] == deck - 3);

    /**
     * Test Case 3
     */
    memcpy(&testState, &state, sizeof(struct gameState));
    // Play the minion card
    cardEffect(minion, -1, -1, -1, &testState, 1, NULL);
    if (testState.discardCount[0] == discard)
    {
        printf(CHECK " ");
        passedTests++;
    }
    else
    {
        printf(FAIL " ");
        printf(" %d != %d --> ", testState.discardCount[0], discard);
        failedTests++;
    }
    printf("Card has been added to discard pile\n");
    // assert(testState.discardCount[0] == discard + 1);

    /**
     * Test Case 4
     */
    memcpy(&testState, &state, sizeof(struct gameState));
    cardEffect(minion, -1, -1, -1, &testState, 1, NULL);
    if (testState.coins == state.coins + 2)
    {
        printf(CHECK " ");
        passedTests++;
    }
    else
    {
        printf(FAIL " ");
        printf("%d != %d --> ", testState.coins, state.coins + 2);
        failedTests++;
    }
    printf("Coins increased by two. \n");
    // assert(testState.coins == state.coins);

    /**
     * Statisics reporting
     */
    printf("minion card test results: ");
    printf("Passed: %d. Failed: %d\n", passedTests, failedTests);

    return 0;
}