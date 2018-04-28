/**
 * Unit Test one for getCost()
 * unittest3.c
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

    printf("Testing the gainCard function: \n");

    initializeGame(2, kingdom, 2048, &state);

    int curseReturn = getCost(curse);
    if (curseReturn == 0)
    {
        printf(CHECK " ");
        passedTests++;
    }
    else
    {
        printf(FAIL " ");
        failedTests++;
    }
    printf("Curse = 0\n");
    assert(curseReturn == 0);

    int estateReturn = getCost(estate);
    if (estateReturn == 2)
    {
        printf(CHECK " ");
        passedTests++;
    }
    else
    {
        printf(FAIL " ");
        failedTests++;
    }
    printf("Estate = 2\n");
    assert(estateReturn == 2);

    int duchyReturn = getCost(duchy);
    if (duchyReturn == 5)
    {
        printf(CHECK " ");
        passedTests++;
    }
    else
    {
        printf(FAIL " ");
        failedTests++;
    }
    printf("Duchy = 5\n");
    assert(duchyReturn == 5);

    int provinceReturn = getCost(province);
    if (provinceReturn == 8)
    {
        printf(CHECK " ");
        passedTests++;
    }
    else
    {
        printf(FAIL " ");
        failedTests++;
    }
    printf("Province = 8\n");
    assert(provinceReturn == 8);

    int copperReturn = getCost(copper);
    if (copperReturn == 0)
    {
        printf(CHECK " ");
        passedTests++;
    }
    else
    {
        printf(FAIL " ");
        failedTests++;
    }
    printf("Copper = 0\n");
    assert(copperReturn == 0);

    int silverReturn = getCost(silver);
    if (silverReturn == 3)
    {
        printf(CHECK " ");
        passedTests++;
    }
    else
    {
        printf(FAIL " ");
        failedTests++;
    }
    printf("Silver = 3\n");
    assert(silverReturn == 3);

    int goldReturn = getCost(gold);
    if (goldReturn == 6)
    {
        printf(CHECK " ");
        passedTests++;
    }
    else
    {
        printf(FAIL " ");
        failedTests++;
    }
    printf("Gold = 6\n");
    assert(goldReturn == 6);

    int adventurerReturn = getCost(adventurer);
    if (adventurerReturn == 6)
    {
        printf(CHECK " ");
        passedTests++;
    }
    else
    {
        printf(FAIL " ");
        failedTests++;
    }
    printf("Adventurer = 6\n");
    assert(adventurerReturn == 6);

    int council_roomReturn = getCost(council_room);
    if (council_roomReturn == 5)
    {
        printf(CHECK " ");
        passedTests++;
    }
    else
    {
        printf(FAIL " ");
        failedTests++;
    }
    printf("Council Room = 5\n");
    assert(council_roomReturn == 5);

    int feastReturn = getCost(feast);
    if (feastReturn == 4)
    {
        printf(CHECK " ");
        passedTests++;
    }
    else
    {
        printf(FAIL " ");
        failedTests++;
    }
    printf("Feast = 4\n");
    assert(feastReturn == 4);

    int gardensReturn = getCost(gardens);
    if (gardensReturn == 4)
    {
        printf(CHECK " ");
        passedTests++;
    }
    else
    {
        printf(FAIL " ");
        failedTests++;
    }
    printf("Gardens = 4\n");
    assert(gardensReturn == 4);

    int mineReturn = getCost(mine);
    if (mineReturn == 5)
    {
        printf(CHECK " ");
        passedTests++;
    }
    else
    {
        printf(FAIL " ");
        failedTests++;
    }
    printf("Mine = 5\n");
    assert(mineReturn == 5);

    int remodelReturn = getCost(remodel);
    if (remodelReturn == 4)
    {
        printf(CHECK " ");
        passedTests++;
    }
    else
    {
        printf(FAIL " ");
        failedTests++;
    }
    printf("Remodel = 4\n");
    assert(remodelReturn == 4);

    int smithyReturn = getCost(smithy);
    if (smithyReturn == 4)
    {
        printf(CHECK " ");
        passedTests++;
    }
    else
    {
        printf(FAIL " ");
        failedTests++;
    }
    printf("Smithy = 4\n");
    assert(smithyReturn == 4);

    int villageReturn = getCost(village);
    if (villageReturn == 3)
    {
        printf(CHECK " ");
        passedTests++;
    }
    else
    {
        printf(FAIL " ");
        failedTests++;
    }
    printf("Village = 3\n");
    assert(villageReturn == 3);

    int baronReturn = getCost(baron);
    if (baronReturn == 4)
    {
        printf(CHECK " ");
        passedTests++;
    }
    else
    {
        printf(FAIL " ");
        failedTests++;
    }
    printf("Baron = 4\n");
    assert(baronReturn == 4);

    int great_hallReturn = getCost(great_hall);
    if (great_hallReturn == 3)
    {
        printf(CHECK " ");
        passedTests++;
    }
    else
    {
        printf(FAIL " ");
        failedTests++;
    }
    printf("Great Hall = 3\n");
    assert(great_hallReturn == 3);

    int minionReturn = getCost(minion);
    if (minionReturn == 5)
    {
        printf(CHECK " ");
        passedTests++;
    }
    else
    {
        printf(FAIL " ");
        failedTests++;
    }
    printf("Minion = 5\n");
    assert(minionReturn == 5);

    int stewardReturn = getCost(steward);
    if (stewardReturn == 3)
    {
        printf(CHECK " ");
        passedTests++;
    }
    else
    {
        printf(FAIL " ");
        failedTests++;
    }
    printf("Steward = 3\n");
    assert(stewardReturn == 3);

    int tributeReturn = getCost(tribute);
    if (tributeReturn == 5)
    {
        printf(CHECK " ");
        passedTests++;
    }
    else
    {
        printf(FAIL " ");
        failedTests++;
    }
    printf("Tribute = 5\n");
    assert(tributeReturn == 5);

    int ambassadorReturn = getCost(ambassador);
    if (ambassadorReturn == 3)
    {
        printf(CHECK " ");
        passedTests++;
    }
    else
    {
        printf(FAIL " ");
        failedTests++;
    }
    printf("Ambassador = 3\n");
    assert(ambassadorReturn == 3);

    int cutpurseReturn = getCost(cutpurse);
    if (cutpurseReturn == 4)
    {
        printf(CHECK " ");
        passedTests++;
    }
    else
    {
        printf(FAIL " ");
        failedTests++;
    }
    printf("Cut Purse = 4\n");
    assert(cutpurseReturn == 4);

    int embargoReturn = getCost(embargo);
    if (embargoReturn == 2)
    {
        printf(CHECK " ");
        passedTests++;
    }
    else
    {
        printf(FAIL " ");
        failedTests++;
    }
    printf("Embargo = 2\n");
    assert(embargoReturn == 2);

    int outpostReturn = getCost(outpost);
    if (outpostReturn == 5)
    {
        printf(CHECK " ");
        passedTests++;
    }
    else
    {
        printf(FAIL " ");
        failedTests++;
    }
    printf("Outpost = 5\n");
    assert(outpostReturn == 5);

    int salvagerReturn = getCost(salvager);
    if (salvagerReturn == 4)
    {
        printf(CHECK " ");
        passedTests++;
    }
    else
    {
        printf(FAIL " ");
        failedTests++;
    }
    printf("Salvager = 4\n");
    assert(salvagerReturn == 4);

    int sea_hagReturn = getCost(sea_hag);
    if (sea_hagReturn == 4)
    {
        printf(CHECK " ");
        passedTests++;
    }
    else
    {
        printf(FAIL " ");
        failedTests++;
    }
    printf("Sea Hag = 4\n");
    assert(sea_hagReturn == 4);

    int treasure_mapReturn = getCost(treasure_map);
    if (treasure_mapReturn == 4)
    {
        printf(CHECK " ");
        passedTests++;
    }
    else
    {
        printf(FAIL " ");
        failedTests++;
    }
    printf("Treasure Map = 4\n");
    assert(treasure_mapReturn == 4);

    int failureReturn = getCost("failure");
    if (failureReturn == -1)
    {
        printf(CHECK " ");
        passedTests++;
    }
    else
    {
        printf(FAIL " ");
        failedTests++;
    }
    printf("Failure = -1\n");
    assert(failureReturn == -1);
    /**
     * Statisics reporting
     */
    printf("Get cost function unit test results: ");
    printf("Passed: %d. Failed: %d\n", passedTests, failedTests);

    return 0;
}