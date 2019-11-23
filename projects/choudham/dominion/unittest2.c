//unittest1.c tests Minion card

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int main()
{
    int coins;
	int seed = 500;
    int player = 0;
    struct gameState G;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };

    printf("FUNCTION TEST FOR MINION CARD\n\n");
	
	printf("Test 1: Check if 2 coins are gained\n")
    //set game state and initialize new game
    memset(&G, 1, sizeof(struct gameState));
    initializeGame(2, k, seed, &G);
	
    //Tests if 2 coins are gained 
    G.hand[player][0] = copper;
    G.hand[player][1] = copper;
    G.hand[player][2] = copper;
    G.hand[player][3] = copper;
    G.hand[player][4] = minion;
	
	coins = G.coins;
	
	//call function to play Minion card
	caseMinion(0, 1, 0, &G, 4, player);
	
	if(G.coins >= coins + 2)
	{
		printf("\tTest passed: Player gained 2 coins\n\n");
    }
    else
    {
        printf("\tTest failed: Player did not gain 2 coins\n\n");
    }

	printf("Test 2: Check if Minion card is discarded\n")
    //set game state and initialize new game
    memset(&G, 1, sizeof(struct gameState));
    initializeGame(2, k, seed, &G);
	
    //Checks if minion card is discarded
    G.hand[player][0] = copper;
    G.hand[player][1] = copper;
    G.hand[player][2] = copper;
    G.hand[player][3] = copper;
    G.hand[player][4] = minion;
	
	//call function to play Minion card
	caseMinion(0, 1, 0, &G, 4, player);
	
	if(G.hand[player][4] == -1)
	{
		printf("\tTest passed: Minion card discarded successfully\n\n");
    }
    else
    {
        printf("\tTest failed: Minion card not dicarded successfully\n\n");
    }	

	printf("Test 3: Check if actions is incremented\n")
    //set game state and initialize new game
    memset(&G, 1, sizeof(struct gameState));
    initializeGame(2, k, seed, &G);
	
    //Checks if action is incremented by 1
    G.hand[player][0] = copper;
    G.hand[player][1] = copper;
    G.hand[player][2] = copper;
    G.hand[player][3] = copper;
    G.hand[player][4] = minion;
	
	//call function to play Minion card
	caseMinion(0, 0, 0, &G, 4, player);
	
	if(G.numActions > 1)
	{
		printf("\tTest passed: numActions incremented successfully\n\n");
    }
    else
    {
        printf("\tTest failed: numActions did not increment successfully\n\n");
    }	
	
	printf("Check if player draws 4 card\n")
    //set game state and initialize new game
    memset(&G, 1, sizeof(struct gameState));
    initializeGame(2, k, seed, &G);
	
    //Checks if player draws 4 cards
    G.hand[player][0] = copper;
    G.hand[player][1] = copper;
    G.hand[player][2] = copper;
    G.hand[player][3] = copper;
    G.hand[player][4] = minion;
	int handCount = G.handcount[player];
	
	//hand of player 2
	G.hand[1][0] = silver;
	G.hand[1][1] = silver;
	G.hand[1][2] = silver;
	G.hand[1][3] = silver;
	G.hand[1][4] = silver;
	G.handCount[1] = 5;
	
	//call function to play Minion card
	caseMinion(0, 0, 0, &G, 4, player);
	
	if(G.handCount[player] < handCount)
	{
		printf("\tTest passed: player drew 4 cards successfully\n\n");
	}
	else
    {
        printf("\tTest failed: player did not draw 4 cards successfully\n\n");
    }
	
	printf("END FUNCTION TEST FOR MINION CARD **");
}