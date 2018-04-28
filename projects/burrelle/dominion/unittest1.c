/**
 * Unit Test one for IsGameOver()
 * unittest1.c
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
    struct gameState state;
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

    int isOver;
    int passedTests = 0;
    int failedTests = 0;

    printf("Testing isGameOver function: \n");

    initializeGame(2, kingdom, 2048, &state);

    /**
 	 * Unit test 1
 	 */
    isOver = isGameOver(&state);
    if (!isOver)
    {
        printf(CHECK " ");
        passedTests++;
    }
    else
    {
        printf(FAIL " ");
        failedTests++;
    }
    printf("The game should not be over to start\n");
    assert(!isOver);

    /**
 	 * Unit test 2
 	 */
    state.supplyCount[province] = 0;
    isOver = isGameOver(&state);
    if (isOver)
    {
        printf(CHECK " ");
        passedTests++;
    }
    else
    {
        printf(FAIL " ");
        failedTests++;
    }
    printf("Setting the supplyCount of province cards to zero ends game\n");
    assert(isOver);

    /**
     * Unit test 3
     */
    state.supplyCount[village] = 0;
    state.supplyCount[minion] = 0;
    state.supplyCount[mine] = 0;
    isOver = isGameOver(&state);
    if (isOver)
    {
        printf(CHECK " ");
        passedTests++;
    }
    else
    {
        printf(FAIL " ");
        failedTests++;
    }
    printf("Setting the supplyCount of three kingdom cards to zero ends game\n");
    assert(isOver);

    /**
     * Statisics reporting
     */
    printf("isGameOver function unit test results: ");
    printf("Passed: %d. Failed: %d\n", passedTests, failedTests);

    return 0;
}