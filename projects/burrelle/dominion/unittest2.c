/**
 * Unit Test one for shuffle()
 * unittest2.c
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>

#define CHECK "\u2713"
#define FAIL "\u274C"

enum boolean
{
  false = 0,
  true = 1
};

typedef enum boolean Bool;

int compare(const int *a, const int *b);

Bool compareTwoDecks(struct gameState *G)
{
  int i;
  for (i = 0; i < G->deckCount[0]; i++)
  {
    if (G->deck[1][i] != G->deck[0][i])
    {
      return false;
    }
  }
  return true;
}

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

  printf("Testing the shuffle function: \n");

  initializeGame(2, kingdom, 2048, &state);

  /**
 	 * Unit test 1
 	 */
  // Shuffle player 1
  shuffle(0, &state);
  // Shuffle player 2
  shuffle(1, &state);
  if (state.deckCount[1] == 10)
  {
    printf(CHECK " ");
    passedTests++;
  }
  else
  {
    printf(FAIL " ");
    failedTests++;
  }
  printf("There should be the same number of cards in both decks after shuffle\n");
  assert(state.deckCount[1] == 10);

  /**
 	 * Unit test 2
 	 * The shuffled cards have different cards
 	 */
  // Shuffle player 1
  shuffle(0, &state);
  // Shuffle player 2
  shuffle(1, &state);
  if (compareTwoDecks(&state) != true)
  {
    printf(CHECK " ");
    passedTests++;
  }
  else
  {
    printf(FAIL " ");
    failedTests++;
  }
  printf("The cards should be shuffled independently\n");
  assert(compareTwoDecks(&state) != true);

  /**
 * Unit test 3
 * The shuffled cards have different cards
 */
  qsort((void *)(state.deck[0]), state.deckCount[0], sizeof(int), compare);
  qsort((void *)(state.deck[1]), state.deckCount[1], sizeof(int), compare);

  if (compareTwoDecks(&state) != false)
  {
    printf(CHECK " ");
    passedTests++;
  }
  else
  {
    printf(FAIL " ");
    failedTests++;
  }
  printf("After sorting the cards should be the same\n");
  assert(compareTwoDecks(&state) != false);

  /**
     * Statisics reporting
     */
  printf("Shuffle function unit test results: ");
  printf("Passed: %d. Failed: %d\n", passedTests, failedTests);

  return 0;
}