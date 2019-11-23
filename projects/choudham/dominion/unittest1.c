//unittest1.c tests Baron card

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
	int estateSupply;
    struct gameState G;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };

    printf("FUNCTION TEST FOR BARON CARD\n\n");
	printf("Test 1: Check if Estate card is discarded\n")
	
    //set game state and initialize new game
    memset(&G, 1, sizeof(struct gameState));
    initializeGame(2, k, seed, &G);
	
    // Checks to c if estate card is discarded from hand
    G.hand[player][0] = estate;
    G.hand[player][1] = copper;
    G.hand[player][2] = copper;
    G.hand[player][3] = copper;
    G.hand[player][4] = baron;

    //call function to play Baron card
    caseBaron(1, 1, &G, 4, player);
	
    //assertion - if player has 4 cards = pass, otherwise fail
    if (G.handCount[player] == 4) 
    {
        printf("\tTest passed: Estate card discarded from hand\n\n");
    }
    else
    {
        printf("\tTest failed: Estate card not discarded from hand\n\n");
    }

	printf("Test 2: Check if player gains 4 coins\n")
	//set game state and initialize new game
    memset(&G, 2, sizeof(struct gameState));
    initializeGame(2, k, seed, &G);
	
    //Player has Estate card to discard and will gain 4 coins
    G.hand[player][0] = estate;
    G.hand[player][1] = copper;
    G.hand[player][2] = copper;
    G.hand[player][3] = copper;
    G.hand[player][4] = baron;

    //Call function to play Baron card; set coin count to 0
    G.coins = 0;
    caseBaron(1, 1, &G, 4, player);

	//assertion - if player gains 4 coins = pass, otherwise fail
    if (G.coins == 4)
    {
        printf("\tTest passed: Player gained 4 coins\n\n");
    }
    else
    {
        printf("\tTest failed: Player did not gain 4 coins\n\n");
    }
	
	printf("Test 3: Check if player gains an Estate card\n")
	//set game state and initialize new game
    memset(&G, 3, sizeof(struct gameState));
    initializeGame(2, k, seed, &G);
	
    //Player doesnt have estate card in hand, so they gotta gain estate card
    G.hand[player][0] = copper;
    G.hand[player][1] = copper;
    G.hand[player][2] = copper;
    G.hand[player][3] = copper;
    G.hand[player][4] = baron;
	
    //estate supply count
    estateSupply = G.supplyCount[estate];
	
    //call function to play Baron card
    caseBaron(1, 0, &G, 4, player);

    //assertion - if player gains Estate card = pass, otherwise fail
    if (G.supplyCount[estate] + 1 == estateSupply)
    {
        printf("\tTest passed: Player gained Estate card\n\n");
    }
    else
    {
        printf("\tTest failed: Player did not gain Estate card\n\n");
    }
	
	printf("Test 4: Check if numBuys increased by 1\n")
	//set game state and initialize new game
    memset(&G, 1, sizeof(struct gameState));
    initializeGame(2, k, seed, &G);
	
    // Checks to c if estate card is discarded from hand
    G.hand[player][0] = estate;
    G.hand[player][1] = copper;
    G.hand[player][2] = copper;
    G.hand[player][3] = copper;
    G.hand[player][4] = baron;

    //call function to play Baron card
    caseBaron(1, 0, &G, 4, player);
	
	//assertion - numBuys increased by 1 = pass, otherwise fail
	if (G.numBuys == 2)
    {
        printf("\tTest passed: numBuys incremented by 1\n\n");
    }
    else
    {
        printf("\tTest failed: numBuys did not increment\n\n");
    }
   
    printf("END FUNCTION TEST FOR BARON CARD **");
}