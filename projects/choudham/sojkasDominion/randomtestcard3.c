//randomtestcard4.c tests Tribute card

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
	srand(time(0));
    int player1 = 0;
	int player2 = 1;
	int tributeRevealed[2] = {-1,-1};
    struct gameState G;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };

    printf("RANDOM TEST FOR TRIBUTE CARD\n\n");
	
	for(int i =0; i < 200; i++)
	{
		//set game state and initialize new game
		memset(&G, 1, sizeof(struct gameState));
		initializeGame(2, k, rand(), &G);
		
		//randomly select card for hand
		int r = rand()%27;
		if(r==0)
		{
			G.hand[player1][4] = curse;
			
			printf("Card randomly selected: curse\n");
			printf("No testing. Check next random selection.\n\n");
		}
		else if (r==1)
		{
			G.hand[player1][4] = estate;
			
			printf("Card randomly selected: estate\n");
			printf("No testing. Check next random selection.\n\n");
		}
		else if (r==2)
		{
			G.hand[player1][4] = duchy;
			
			printf("Card randomly selected: duchy\n");
			printf("No testing. Check next random selection.\n\n");
		}
		else if (r==3)
		{
			G.hand[player1][4] = province;
			
			printf("Card randomly selected: province\n");
			printf("No testing. Check next random selection.\n\n");
		}
		else if (r==4)
		{
			G.hand[player1][4] = copper;
			
			printf("Card randomly selected: copper\n");
			printf("No testing. Check next random selection.\n\n");
		}
		else if (r==5)
		{
			G.hand[player1][4] = silver;
			
			printf("Card randomly selected: silver\n");
			printf("No testing. Check next random selection.\n\n");
		}
		else if (r==6)
		{
			G.hand[player1][4] = gold;
			
			printf("Card randomly selected: gold\n");
			printf("No testing. Check next random selection.\n\n");
		}
		else if (r==7)
		{
			G.hand[player1][4] = adventurer;
			
			printf("Card randomly selected: adventurer\n");
			printf("No testing. Check next random selection.\n\n");
		}
		else if (r==8)
		{
			G.hand[player1][4] = council_room;
			
			printf("Card randomly selected: council_room\n");
			printf("No testing. Check next random selection.\n\n");
		}
		else if (r==9)
		{
			G.hand[player1][4] = feast;
			
			printf("Card randomly selected: feast\n");
			printf("No testing. Check next random selection.\n\n");
		}
		else if (r==10)
		{
			G.hand[player1][4] = gardens;
			
			printf("Card randomly selected: gardens\n");
			printf("No testing. Check next random selection.\n\n");
		}
		else if (r==11)
		{
			G.hand[player1][4] = mine;
			
			printf("Card randomly selected: mine\n");
			printf("No testing. Check next random selection.\n\n");
		}
		else if (r==12)
		{
			G.hand[player1][4] = remodel;
			
			printf("Card randomly selected: remodel\n");
			printf("No testing. Check next random selection.\n\n");
		}
		else if (r==13)
		{
			G.hand[player1][4] = smithy;
			
			printf("Card randomly selected: smithy\n");
			printf("No testing. Check next random selection.\n\n");
		}
		else if (r==14)
		{
			G.hand[player1][4] = village;
			
			printf("Card randomly selected: village\n");
			printf("No testing. Check next random selection.\n\n");
		}
		else if (r==15)
		{
			G.hand[player1][4] = baron;
			
			printf("Card randomly selected: baron\n");
			printf("No testing. Check next random selection.\n\n");
		}				
		else if (r==16)
		{
			G.hand[player1][4] = great_hall;
			
			printf("Card randomly selected: great_hall\n");
			printf("No testing. Check next random selection.\n\n");
		}
		else if (r==17)
		{
			G.hand[player1][4] = minion;
			
			printf("Card randomly selected: minion\n");
			printf("No testing. Check next random selection.\n\n");
		}
		else if (r==18)
		{
			G.hand[player1][4] = steward;
			
			printf("Card randomly selected: steward\n");
			printf("No testing. Check next random selection.\n\n");
		}
		else if (r==19)
		{
			G.hand[player1][4] = tribute;
			
			printf("Test 1: Check if 2 coins are gained when 2 treasure cards revealed\n");
			
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
			initializeGame(2, k, rand(), &G);
			
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
			
			printf("Test 3: Check if 2 cards are gained when 2 victory cards revealed\n");
			
			//set game state and initialize new game
			memset(&G, 1, sizeof(struct gameState));
			initializeGame(2, k, rand(), &G);
			
			//revealed cards are 2 victory cards
			tributeRevealed[0] = estate;
			tributeRevealed[1] = estate;
			
			//player1's hand
			G.hand[player1][0] = copper;
			G.hand[player1][1] = copper;
			G.hand[player1][2] = copper;
			G.hand[player1][3] = copper;
			G.hand[player1][4] = tribute;
			
			int handCount = G.handCount[player1];
			
			//set deck and discard pile of player2
			G.deckCount[player2] = 2;
			G.discardCount[player2] = 2;
			
			//call function to play Tribute card
			caseTribute(tribute, tributeRevealed, &G, player1, player2);
			
			//assertion - player should only gain 2 cards since duplicate victory cards
			if(G.handCount[player1] == handCount + 2)
			{
				printf("\tTest passed: player gains 2 cards\n\n");
			}
			else
			{
				printf("\tTest failed: player did not gain 2 cards\n\n");
			}
			
			printf("Test 4: Check nextPlayer's discard pile when deck has fewer than 2 cards\n");
			
			//set game state and initialize new game
			memset(&G, 1, sizeof(struct gameState));
			initializeGame(2, k, rand(), &G);
			
			//revealed cards are 2 victory cards
			tributeRevealed[0] = -1;
			tributeRevealed[1] = -1;
			
			//player1's hand
			G.hand[player1][0] = copper;
			G.hand[player1][1] = copper;
			G.hand[player1][2] = copper;
			G.hand[player1][3] = copper;
			G.hand[player1][4] = tribute;
			
			//set deck and discard pile of player2
			G.deckCount[player2] = 0;
			G.discardCount[player2] = 1;
			
			//call function to play Tribute card
			caseTribute(tribute, tributeRevealed, &G, player1, player2);
			
			//assertion - discardCount should decrease for player2
			if(G.discardCount[player2] == 0)
			{
				printf("\tTest passed: player2's deck count decreased\n\n");
			}
			else
			{
				printf("\tTest failed: player2's deck count did not decrease\n\n");
			}
		}
		else if (r==20)
		{
			G.hand[player1][4] = ambassador;
			
			printf("Card randomly selected: ambassador\n");
			printf("No testing. Check next random selection.\n\n");
		}
		else if (r==21)
		{
			G.hand[player1][4] = cutpurse;
			
			printf("Card randomly selected: cutpurse\n");
			printf("No testing. Check next random selection.\n\n");
		}
		else if (r==22)
		{
			G.hand[player1][4] = embargo;
			
			printf("Card randomly selected: embargo\n");
			printf("No testing. Check next random selection.\n\n");
		}
		else if (r==23)
		{
			G.hand[player1][4] = outpost;
			
			printf("Card randomly selected: outpost\n");
			printf("No testing. Check next random selection.\n\n");
		}
		else if (r==24)
		{
			G.hand[player1][4] = salvager;
			
			printf("Card randomly selected: salvager\n");
			printf("No testing. Check next random selection.\n\n");
		}
		else if (r==25)
		{
			G.hand[player1][4] = sea_hag;
			
			printf("Card randomly selected: sea_hag\n");
			printf("No testing. Check next random selection.\n\n");
		}
		else if (r==26)
		{
			G.hand[player1][4] = treasure_map;
			
			printf("Card randomly selected: treasure_map\n");
			printf("No testing. Check next random selection.\n\n");
		}
	}
}