/**
 * randomtestcard1.c
 * Embargo Random Testing
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));
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
	int passedTests1 = 0;
	int failedTests1 = 0;
	int passedTests2 = 0;
	int failedTests2 = 0;
	int passedTests3 = 0;
	int failedTests3 = 0;
	int passedTests4 = 0;
	int failedTests4 = 0;
	int numberOfTests = 10000;

	printf("Testing embargo card: \n");

	for (int i = 0; i < numberOfTests; ++i)
	{
		int numberOfPlayers = (rand() % 7) + 2; // 2 - 8 players
		int handPosition = rand() % 5;			// 0 - 5 hand position
		int seed = rand();						// Any random number to seed the game
		int currentPlayer = rand() % numberOfPlayers;
		// Start the game
		initializeGame(numberOfPlayers, kingdom, seed, &state);
		// Set the adventure to a random value
		state.hand[currentPlayer][handPosition] = embargo;
		// create a test state to test against
		memcpy(&testState, &state, sizeof(struct gameState));
		// Play the embargo card
		cardEffect(embargo, -1, -1, -1, &testState, 1, NULL);

		/**
	 	* Test One
	 	*/
		if (testState.handCount[currentPlayer] == state.handCount[currentPlayer] - 1)
		{
			passedTests1++;
		}
		else
		{
			failedTests1++;
		}

		/**
	 	* Test Two
	 	*/
		if (testState.deckCount[currentPlayer] == state.deckCount[currentPlayer])
		{
			passedTests2++;
		}
		else
		{
			failedTests2++;
		}

		/**
	 	* Test Three
	 	*/
		if (testState.discardCount[currentPlayer] == state.discardCount[currentPlayer])
		{
			passedTests3++;
		}
		else
		{
			failedTests3++;
		}

		/**
	 	* Test Four
	 	*/
		if (testState.coins == state.coins + 2)
		{
			passedTests4++;
		}
		else
		{
			failedTests4++;
		}
	}

	printf("Embargo card test results: ");
	printf("Test 1: Passed: %d. Failed: %d\n", passedTests1, failedTests1);
	printf("Test 2: Passed: %d. Failed: %d\n", passedTests2, failedTests2);
	printf("Test 3: Passed: %d. Failed: %d\n", passedTests3, failedTests3);
	printf("Test 4: Passed: %d. Failed: %d\n\n", passedTests4, failedTests4);

	return 0;
}