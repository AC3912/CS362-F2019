//randomtestcard1.c tests Baron card

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
    int player = 0;
	int estateSupply;
    struct gameState G;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
	
	printf("RANDOM TEST FOR BARON CARD\n\n");
	
	for(int i =0; i < 200; i++)
	{
		//set game state and initialize new game
		memset(&G, 1, sizeof(struct gameState));
		initializeGame(2, k, seed, &G);
		
		//randomly select card for hand
		r = rand()%27;
		if(r==0)
		{
			G.hand[player][4] = curse;
			
			printf("Card randomly selected: curse\n")
			printf("No testing. Check next random selection.\n\n");
		}
		else if (r==1)
		{
			G.hand[player][4] = estate;
			
			printf("Card randomly selected: estate\n")
			printf("No testing. Check next random selection.\n\n");
		}
		else if (r==2)
		{
			G.hand[player][4] = duchy;
			
			printf("Card randomly selected: duchy\n")
			printf("No testing. Check next random selection.\n\n");
		}
		else if (r==3)
		{
			G.hand[player][4] = province;
			
			printf("Card randomly selected: province\n")
			printf("No testing. Check next random selection.\n\n");
		}
		else if (r==4)
		{
			G.hand[player][4] = copper;
			
			printf("Card randomly selected: copper\n")
			printf("No testing. Check next random selection.\n\n");
		}
		else if (r==5)
		{
			G.hand[player][4] = silver;
			
			printf("Card randomly selected: silver\n")
			printf("No testing. Check next random selection.\n\n");
		}
		else if (r==6)
		{
			G.hand[player][4] = gold;
			
			printf("Card randomly selected: gold\n")
			printf("No testing. Check next random selection.\n\n");
		}
		else if (r==7)
		{
			G.hand[player][4] = adventurer;
			
			printf("Card randomly selected: adventurer\n")
			printf("No testing. Check next random selection.\n\n");
		}
		else if (r==8)
		{
			G.hand[player][4] = council_room;
			
			printf("Card randomly selected: council_room\n")
			printf("No testing. Check next random selection.\n\n");
		}
		else if (r==9)
		{
			G.hand[player][4] = feast;
			
			printf("Card randomly selected: feast\n")
			printf("No testing. Check next random selection.\n\n");
		}
		else if (r==10)
		{
			G.hand[player][4] = gardens;
			
			printf("Card randomly selected: gardens\n")
			printf("No testing. Check next random selection.\n\n");
		}
		else if (r==11)
		{
			G.hand[player][4] = mine;
			
			printf("Card randomly selected: mine\n")
			printf("No testing. Check next random selection.\n\n");
		}
		else if (r==12)
		{
			G.hand[player][4] = remodel;
			
			printf("Card randomly selected: remodel\n")
			printf("No testing. Check next random selection.\n\n");
		}
		else if (r==13)
		{
			G.hand[player][4] = smithy;
			
			printf("Card randomly selected: smithy\n")
			printf("No testing. Check next random selection.\n\n");
		}
		else if (r==14)
		{
			G.hand[player][4] = village;
			
			printf("Card randomly selected: village\n")
			printf("No testing. Check next random selection.\n\n");
		}
		else if (r==15)
		{
			G.hand[player][4] = baron;
			
			srand(time(0));
			
			r2 = rand()%2;
			
			if(r2 = 0)
			{
				G.hand[player][0] = estate;
				
				printf("Test 1: Check if numBuys increased by 1\n");
				
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
				
				printf("Test 2: Check if player gains 4 coins\n");
				
				//set game state and initialize new game
				memset(&G, 2, sizeof(struct gameState));
				initializeGame(2, k, seed, &G);
				
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
			}
			else if
			{
				printf("Test 1: Check if numBuys increased by 1\n");
				
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
				
				printf("Test 2: Check if player gains an Estate card\n");
				
				//set game state and initialize new game
				memset(&G, 3, sizeof(struct gameState));
				initializeGame(2, k, seed, &G);
				
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
						
		}
		else if (r==16)
		{
			G.hand[player][4] = great_hall;
			
			printf("Card randomly selected: great_hall\n")
			printf("No testing. Check next random selection.\n\n");
		}
		else if (r==17)
		{
			G.hand[player][4] = minion;
			
			printf("Card randomly selected: minion\n")
			printf("No testing. Check next random selection.\n\n");
		}
		else if (r==18)
		{
			G.hand[player][4] = steward;
			
			printf("Card randomly selected: steward\n")
			printf("No testing. Check next random selection.\n\n");
		}
		else if (r==19)
		{
			G.hand[player][4] = tribute;
			
			printf("Card randomly selected: tribute\n")
			printf("No testing. Check next random selection.\n\n");
		}
		else if (r==20)
		{
			G.hand[player][4] = ambassador;
			
			printf("Card randomly selected: ambassador\n")
			printf("No testing. Check next random selection.\n\n");
		}
		else if (r==21)
		{
			G.hand[player][4] = cutpurse;
			
			printf("Card randomly selected: cutpurse\n")
			printf("No testing. Check next random selection.\n\n");
		}
		else if (r==22)
		{
			G.hand[player][4] = embargo;
			
			printf("Card randomly selected: embargo\n")
			printf("No testing. Check next random selection.\n\n");
		}
		else if (r==23)
		{
			G.hand[player][4] = outpost;
			
			printf("Card randomly selected: outpost\n")
			printf("No testing. Check next random selection.\n\n");
		}
		else if (r==24)
		{
			G.hand[player][4] = salvager;
			
			printf("Card randomly selected: salvager\n")
			printf("No testing. Check next random selection.\n\n");
		}
		else if (r==25)
		{
			G.hand[player][4] = sea_hag;
			
			printf("Card randomly selected: sea_hag\n")
			printf("No testing. Check next random selection.\n\n");
		}
		else if (r==26)
		{
			G.hand[player][4] = treasure_map;
			
			printf("Card randomly selected: treasure_map\n")
			printf("No testing. Check next random selection.\n\n");
		}