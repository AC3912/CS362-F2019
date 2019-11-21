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

    printf("FUNCTION TEST FOR BARON CARD\n");

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
	
    //should be 4, player has 5 cards
    if (G.handCount[player] == 4) 
    {
        printf("\tTest passed: Estate card discarded from hand\n");
    }
    else
    {
        printf("\tTest failed: Estate card not discarded from hand\n");
    }

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

    if (G.coins == 4)
    {
        printf("\tTest passed: Player gained 4 coins\n");
    }
    else
    {
        printf("\tTest failed: Player did not gain 4 coins\n");
    }
	

	//initialize game
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

    //result < original estate supply count by 1. 
    if (G.supplyCount[estate] + 1 == estateSupply)
    {
        printf("\tTest passed: Player gained Estate card\n");
    }
    else
    {
        printf("\tTest failed: Player did not gain Estate card\n");
    }
   
    printf("END FUNCTION TEST FOR BARON CARD **");
}