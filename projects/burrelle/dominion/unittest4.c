/**
 * Unit Test one for supplyCount()
 * unittest4.c
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

    int passedTests = 0;
    int failedTests = 0;

    printf("Testing the supply count function: \n");

    initializeGame(2, kingdom, 2048, &state);

    /**
     * Unit test 1
     */
    if (supplyCount(embargo, &state) == state.supplyCount[embargo])
    {
        printf(CHECK " ");
        passedTests++;
    }
    else
    {
        printf(FAIL " ");
        failedTests++;
    }
    printf("Initalize the supply count\n");

    /**
     * Unit test 2
     */
    state.supplyCount[embargo]++;
    if (supplyCount(embargo, &state) == state.supplyCount[embargo])
    {
        printf(CHECK " ");
        passedTests++;
    }
    else
    {
        printf(FAIL " ");
        failedTests++;
    }
    printf("Increment the supply count\n");

    /**
     * Unit test 3
     */
    state.supplyCount[embargo]--;
    if (supplyCount(embargo, &state) == state.supplyCount[embargo])
    {
        printf(CHECK " ");
        passedTests++;
    }
    else
    {
        printf(FAIL " ");
        failedTests++;
    }
    printf("Decrement the supply count\n");

    /**
     * Statisics reporting
     */
    printf("Supply count function unit test results: ");
    printf("Passed: %d. Failed: %d\n", passedTests, failedTests);

    return 0;
}