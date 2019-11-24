//unittest5.c tests Mine card

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
    int player = 0;
    struct gameState G;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };

    printf("FUNCTION TEST FOR MINE CARD\n\n");
	printf("Test 1: Trash and gain same treasure card\n");
	
    //set game state and initialize new game
    memset(&G, 1, sizeof(struct gameState));
    initializeGame(2, k, seed, &G);
	
	G.hand[player][0] = estate;
	G.hand[player][1] = silver;
	G.hand[player][2] = silver;
	G.hand[player][3] = silver;
	G.hand[player][4] = mine;
	
	int choice = caseMine(1, silver, &G, 4, player);
	
	if(choice == 0)
	{
		printf("\tTest passed: Silver trashed and silver gained\n\n");
	}
	else
	{
		printf("\tTest failed: Either silver not trashed nor gained\n\n");
	}
	
	printf("Test 2: Trash and gain different treasure card\n");
	
    //set game state and initialize new game
    memset(&G, 1, sizeof(struct gameState));
    initializeGame(2, k, seed, &G);
	
	G.hand[player][0] = estate;
	G.hand[player][1] = copper;
	G.hand[player][2] = copper;
	G.hand[player][3] = copper;
	G.hand[player][4] = mine;
	
	caseMine(1, silver, &G, 4, player);
	
	int silverCardCount = 0;
	for(int i = 0; i < G.handCount[player; i++])
	{
		if(G.hand[player][i] == silver)
		{
			silverCardCount++;
		}
	}
	
	if(silverCardCount == 1)
	{
		printf("\tTest passed: Copper trashed and silver gained\n\n");
	}
	else
	{
		printf("\tTest failed: Either copper not trashed or silver not gained\n\n");
	}
}
	