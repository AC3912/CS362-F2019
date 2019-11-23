//unittest4.c tests Tribute card

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int main()
{
	int seed = 500;
    int player1 = 0;
	int player2 = 1;
	int tributeRevealed[2] = {-1,-1}
    struct gameState G;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };

    printf("FUNCTION TEST FOR TRIBUTE CARD\n\n");
	
	printf("Test 1: Check if 2 coins are gained when 2 treasure cards revealed\n");
	
	//set game state and initialize new game
    memset(&G, 1, sizeof(struct gameState));
    initializeGame(2, k, seed, &G);
	
	//revealed cards are 2 treasure cards
	tributeRevealed[0] = silver;
	tributeRevealed[1] = silver;
	
	int coinsCount = G.coins;
	
	//player1's hand
	G.hand[player1][0] = copper;
	G.hand[player1][1] = copper;
	G.hand[player1][2] = copper;
	G.hand[player1][3] = copper;
	G.hand[player1][4] = tribute;
	
	//set deck and discard pile of player2
	G.deckCount[player2] = 2;
	G.discardCount[player2] = 2;
	
	//call function to play Tribute card
	caseTribute(tribute, tributeRevealed, &G, player1, player2);
	
	//assertion - player should only gain 2 coins since duplicate treasure cards
	if(G.coins == coinsCount + 2)
	{
		printf("\tTest passed: player gains 2 coins\n\n");
	}
	else
	{
		printf("\tTest failed: player did not gain 2 coins\n\n");
	}
	
	printf("Test 2: Check if 2 actions are gained when 2 action cards revealed\n");
	
	//set game state and initialize new game
    memset(&G, 1, sizeof(struct gameState));
    initializeGame(2, k, seed, &G);
	
	int numActions = G.numActions;
	
	//revealed cards are 2 action cards
	tributeRevealed[0] = baron;
	tributeRevealed[1] = mine;
	
	//player1's hand
	G.hand[player1][0] = copper;
	G.hand[player1][1] = copper;
	G.hand[player1][2] = copper;
	G.hand[player1][3] = copper;
	G.hand[player1][4] = tribute;
	
	//set deck and discard pile of player2
	G.deckCount[player2] = 2;
	G.discardCount[player2] = 2;
	
	//call function to play Tribute card
	caseTribute(tribute, tributeRevealed, &G, player1, player2);
	
	//assertion - player should only gain 2 actions since duplicate action cards
	if(G.numActions == numActions + 2)
	{
		printf("\tTest passed: player gains 2 actions\n\n");
	}
	else
	{
		printf("\tTest failed: player did not gain 2 actions\n\n");
	}
	
	printf("END FUNCTION TEST FOR TRIBUTE CARD");
}