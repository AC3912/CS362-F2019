//unittest3.c tests Ambassador card

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

    printf("FUNCTION TEST FOR AMBASSADOE CARD\n\n");
	printf("Test 1: Check if copy of revealed gained by other player\n");
	
    //set game state and initialize new game
    memset(&G, 1, sizeof(struct gameState));
    initializeGame(2, k, seed, &G);
	
	G.hand[player][3] = estate;
	G.hand[player][4] = ambassador;
	
	caseAmbassador(0,3,2,&G,4,0);
	
	int estateSupply = G.supplyCount[estate];
	
	if(G.supplyCount[estate] + 1 == estateSupply)
    {
        printf("\tTest passed: Other player gained revealed Estate card\n\n");
    }
    else
    {
        printf("\tTest failed: Other player did not gain revealed Estate card\n\n");
    }
	
	printf("Test 2: Check if choice1 is correct\n");
	
    //set game state and initialize new game
    memset(&G, 1, sizeof(struct gameState));
    initializeGame(2, k, seed, &G);
	
	G.hand[player][3] = silver;
	G.hand[player][4] = ambassador;
	
	int choiceCorrect = caseAmbassador(0,4,2,&G,4,0);
	
	if(choiceCorrect == -2)
	{
		printf("\tTest passed: choice1 is correct\n\n");
	}
	else
	{
		printf("\tTest failed: choice1 is not correct\n\n");
	}
	
	printf("Test 3: Check if choice2 is correct\n");
	
    //set game state and initialize new game
    memset(&G, 1, sizeof(struct gameState));
    initializeGame(2, k, seed, &G);
	
	G.hand[player][2] = silver;
	G.hand[player][3] = silver;
	G.hand[player][4] = ambassador;
	
	int choice = caseAmbassador(0,0,3,&G,4,0);
	
	if(choice == -1)
	{
		printf("\tTest passed: choice2 is correct\n\n");
	}
	else
	{
		printf("\tTest failed: choice2 is not correct\n\n");
	}
	
	printf("Test 4: Check if correct amount of cards discarded from hand\n");
	
    //set game state and initialize new game
    memset(&G, 1, sizeof(struct gameState));
    initializeGame(2, k, seed, &G);
	
	G.hand[player][0] = copper;
	G.hand[player][1] = gold;
	G.hand[player][2] = estate;
	G.hand[player][3] = silver;
	G.hand[player][4] = ambassador;
	
	caseAmbassador(0,0,3,&G,4,0);
	
	if(G.handCount[player] == 3)
	{
		printf("\tTest passed: correct amount of cards discarded from player's hand\n\n");
	}
	else
	{
		printf("\tTest failed: incorrect amount of cardes discarded from player's hand\n\n");
	}
}