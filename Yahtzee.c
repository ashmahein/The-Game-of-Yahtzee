/*Name: Ash Mahein
* Date: 03/10/16
* Class: CptS 121, Spring 2016; Lab Section 4
* Programming Assignment: Yahtzee
* Collobaration: Connor Wytko.
* Description: This program plays the game of yahtzee by rolling 5 dice and then asking the player if they want to reroll certain dice or store the roll as one of the game combinations.
*
*Constants: None.
*
*Outputs: Dice values, combinations that a player can use, player scores during the game, and the winning players scores.
*
*/
#include "Mahein_Ash_PA5.h"
/*********************************************************************************************
* Programmer: Ash Mahein                                                                     *
* Class: CptS 121; Lab Section 4                                                             *
* Programming Assignment: Yahtzee                                                            *
*                                                                                            *
* Date: 03/10/16                                                                             *
*                                                                                            *
* Description://Function for printing the rules to the player                                *
*                                                                                            *
*                                                                                            *
*                                                                                            *
*                                                                                            *
*********************************************************************************************/
void game_menu(void)
{
	printf("The scorecard used for Yahtzee is composed of two sections. A upper section and a lower section.\n");
	printf("A total of thirteen boxes or thirteen scoring combinations are divided amongst the sections.\n");
	printf("The upper section consists of boxes that are scored by summing the value of the dice matching the faces of the box.\n");
	printf("If a player rolls four 3's, then the score placed in the 3's box is the sum of the dice which is 12.\n");
	printf("Once a player has chosen to score a box, it may not be changed and the combination is no longer in play for future rounds.\n");
	printf("If the sum of the scores in the upper section is greater than or equal to 63, then 35 more points are added to the players overall score as a bonus.\n");
	printf("The lower section contains a number of poker like combinations.\n");
}
/*********************************************************************************************
* Programmer: Ash Mahein                                                                     *
* Class: CptS 121; Lab Section 4                                                             *
* Programming Assignment: Yahtzee                                                            *
*                                                                                            *
* Date: 03/10/16                                                                             *
*                                                                                            *
* Description://Function for rolling dice                                                    *
*                                                                                            *
*                                                                                            *
*                                                                                            *
*                                                                                            *
*********************************************************************************************/
void roll_die(int *dice, int size)
{
	int index = 0;

	for (index = 0; index < size; ++index)
	{
        dice[index] = (rand() % 6 + 1);
	}
	//for (index = 0; index < 5; ++index)
	//{
	//	printf("Your dice rolls are: %d\n", dice[index]);
	//}
}
/*********************************************************************************************
* Programmer: Ash Mahein                                                                     *
* Class: CptS 121; Lab Section 4                                                             *
* Programming Assignment: Yahtzee                                                            *
*                                                                                            *
* Date: 03/10/16                                                                             *
*                                                                                            *
* Description://Function for printing the dice values that have been rolled.                 *
*               This fucntion used pointers.                                                 *
*                                                                                            *
*                                                                                            *
*                                                                                            *
*********************************************************************************************/
void print_dice(int *dice, int size)
{
	int index = 0;
	for (index = 0; index < size; ++index)
	{
		printf("[%d]: %d\n", index + 1, dice[index]);
	}
}
/*********************************************************************************************
* Programmer: Ash Mahein                                                                     *
* Class: CptS 121; Lab Section 4                                                             *
* Programming Assignment: Yahtzee                                                            *
*                                                                                            *
* Date: 03/10/16                                                                             *
*                                                                                            *
* Description://Function for adding up the different numbers that have been rolled. Into an  *
*               an array.                                                                    *
*                                                                                            *
*                                                                                            *
*                                                                                            *
*********************************************************************************************/
void determine_count_of_each_die(int dice[], int size_dice, int count[])
{
	int index = 0;

	for (index = 0; index < size_dice; index++)
	{
		count[dice[index]] += 1;
	}
}
/*********************************************************************************************
* Programmer: Ash Mahein                                                                     *
* Class: CptS 121; Lab Section 4                                                             *
* Programming Assignment: Yahtzee                                                            *
*                                                                                            *
* Date: 03/10/16                                                                             *
*                                                                                            *
* Description://Function for calcualting the sum of the dice.                                *
*                                                                                            *
*                                                                                            *
*                                                                                            *
*                                                                                            *
*********************************************************************************************/
int sum(int total_dice[], int dice)
{
	int sum = 0;

	sum = total_dice[dice] * dice;

	return sum;
}
/*********************************************************************************************
* Programmer: Ash Mahein                                                                     *
* Class: CptS 121; Lab Section 4                                                             *
* Programming Assignment: Yahtzee                                                            *
*                                                                                            *
* Date: 03/10/16                                                                             *
*                                                                                            *
* Description://Function for calcualting the points earned by the dice roll. This function   *
*               asks the user what combinations they want to use and then compares the dice  *
*               rolled before it calcualtes the sum of the combination. It then stores the   *
*               sum of the selected combination into another combination and doesn't allow   *
*               the user to use that combination again.                                      *
*********************************************************************************************/
void score_obtained(int comb[], int comb_used[], int dice_count[], int size, int count_dice_values[])
{
	int player_comb_choice = 0;

	printf("Which combination would you like to use?\n");
	printf(" 1. Sum of 1's\n 2. Sum of 2's\n 3. Sum of 3's\n 4. Sum of 4's\n 5. Sum of 5's\n 6. Sum of 6's\n 7. Three-of-a-kind\n 8. Four-of-a-kind\n 9. Full house\n 10. Small straight\n 11. Large straight\n 12. Yahtzee\n 13.Chance\n");
	scanf("%d", &player_comb_choice);

	if ((player_comb_choice == 1) && (comb_used[0] != 1)) //sum of ones.
	{
		if ((count_dice_values[1] == 1) || (count_dice_values[2] == 1) || (count_dice_values[3] == 1) || (count_dice_values[4] == 1) || (count_dice_values[5] == 1) || (count_dice_values[6] == 1))
		{
			comb[0] = count_dice_values[1];
			comb_used[0] = 1;
			printf("%d\n", comb[0]);
		}
		else
		{
			comb[0] = 0;
			comb_used[0] = 1;
		}
	}

	else if ((player_comb_choice == 2) && (comb_used[1] != 1)) //sum of twos
	{
		if ((count_dice_values[2] == 1) || (count_dice_values[2] == 2) || (count_dice_values[2] == 3) || (count_dice_values[2] == 4) || (count_dice_values[2] == 5) || (count_dice_values[2] == 6))
		{
			comb[1] = count_dice_values[2] * 2;
			comb_used[1] = 1;
			printf("%d\n", comb[1]);
		}
		else
		{
			comb[1] = 0;
			comb_used[1] = 1;
		}
	}

	else if ((player_comb_choice == 3) && (comb_used[2] != 1)) //sum of threes
	{
		if ((count_dice_values[3] == 1) || (count_dice_values[3] == 2) || (count_dice_values[3] == 3) || (count_dice_values[3] == 4) || (count_dice_values[3] == 5) || (count_dice_values[3] == 6))
		{
			comb[2] = count_dice_values[3] * 3;
			comb_used[2] = 1;
			printf("%d\n", comb[2]);
		}
		else
		{
			comb[2] = 0;
			comb_used[2] = 1;
		}
	}

	else if ((player_comb_choice == 4) && (comb_used[3] != 1)) //sum of fours
	{
		if ((count_dice_values[4] == 1) || (count_dice_values[4] == 2) || (count_dice_values[4] == 3) || (count_dice_values[4] == 4) || (count_dice_values[4] == 5) || (count_dice_values[4] == 6))
		{
			comb[3] = count_dice_values[4] * 4;
			comb_used[3] = 1;
			printf("%d\n", comb[3]);
		}
		else
		{
			comb[3] = 0;
			comb_used[3] = 1;
		}
	}

	else if ((player_comb_choice == 5) && (comb_used[4] != 1)) //sum of fives
	{
		if ((count_dice_values[5] == 1) || (count_dice_values[5] == 2) || (count_dice_values[5] == 3) || (count_dice_values[5] == 4) || (count_dice_values[5] == 5) || (count_dice_values[5] == 6))
		{
			comb[4] = count_dice_values[5] * 5;
			comb_used[4] = 1;
			printf("%d\n", comb[4]);
		}
		else
		{
			comb[4] = 0;
			comb_used[4] = 1;
		}
	}

	else if ((player_comb_choice == 6) && (comb_used[5] != 1)) //sum of sixes
	{
		if ((count_dice_values[6] == 1) || (count_dice_values[6] == 2) || (count_dice_values[6] == 3) || (count_dice_values[6] == 4) || (count_dice_values[6] == 5) || (count_dice_values[6] == 6))
		{
			comb[5] = count_dice_values[6] * 6;
			comb_used[5] = 1;
			printf("%d\n", comb[5]);
		}
		else
		{
			comb[5] = 0;
			comb_used[5] = 1;
		}
	}

	else if ((player_comb_choice == 7) && (comb_used[6] != 1)) //three of a kind.
	{
		if ((count_dice_values[1] == 3) || (count_dice_values[2] == 3) || (count_dice_values[3] == 3) || (count_dice_values[4] == 3) || (count_dice_values[5] == 3) || (count_dice_values[6] == 3))
		{
			comb[6] = (count_dice_values[1] + (count_dice_values[2] * 2) + (count_dice_values[3] * 3) + (count_dice_values[4] * 4) + (count_dice_values[5] * 5) + (count_dice_values[6] * 6));
			comb_used[6] = 1;
			printf("%d\n", comb[6]);
		}
	}

	else if ((player_comb_choice == 8) && (comb_used[7] != 1)) //four of a kind
	{
		if ((count_dice_values[1] == 4) || (count_dice_values[2] == 4) || (count_dice_values[3] == 4) || (count_dice_values[4] == 4) || (count_dice_values[5] == 4) || (count_dice_values[6] == 4))
		{
			comb[7] = (count_dice_values[1] + (count_dice_values[2] * 2) + (count_dice_values[3] * 3) + (count_dice_values[4] * 4) + (count_dice_values[5] * 5) + (count_dice_values[6] * 6));
			comb_used[7] = 1;
			printf("%d\n", comb[7]);
		}
	}

	else if ((player_comb_choice == 9) && (comb_used[8] != 1)) //full house
	{
		if ((count_dice_values[1] == 2) || (count_dice_values[2] == 2) || (count_dice_values[3] == 2) || (count_dice_values[4] == 2) || (count_dice_values[5] == 2) || (count_dice_values[6] == 2))
		{ 
			if ((count_dice_values[1] == 3) || (count_dice_values[2] == 3) || (count_dice_values[3] == 3) || (count_dice_values[4] == 3) || (count_dice_values[5] == 3) || (count_dice_values[6] == 3))
			{
				{
					comb[8] = 25;
					comb_used[8] = 1;
					printf("%d\n", comb[8]);
				}
			}
		}
	}

	else if ((player_comb_choice == 10) && (comb_used[9] != 1)) //small straight
	{
		if ((count_dice_values[1] == 1) && (count_dice_values[2] == 1) && (count_dice_values[3] == 1) && (count_dice_values[4] == 1) 
			|| (count_dice_values[2] == 1) && (count_dice_values[3] == 1) && (count_dice_values[4] == 1) && (count_dice_values[5] == 1) 
			|| (count_dice_values[3] == 1) && (count_dice_values[4] == 1) && (count_dice_values[5] == 1) && (count_dice_values[6] == 1))
		{
			comb[9] = 30;
			comb_used[9] = 1;
			printf("%d\n", comb[9]);
		}
	}

	else if ((player_comb_choice == 11) && (comb_used[10] != 1)) //large straight
	{
		if ((count_dice_values[1] == 1) && (count_dice_values[2] == 1) && (count_dice_values[3] == 1) && (count_dice_values[4] == 1) && (count_dice_values[5] == 1)
			|| (count_dice_values[2] == 1) && (count_dice_values[3] == 1) && (count_dice_values[4] == 1) && (count_dice_values[5] == 1) && (count_dice_values[6] == 1))
		{
			comb[10] = 40;
			comb_used[10] = 1;
			printf("%d\n", comb[10]);
		}
	}

	else if ((player_comb_choice == 12) && (comb_used[11] != 1)) //yahtzee
	{
		if ((count_dice_values[1] == 1) || (count_dice_values[2] == 1) || (count_dice_values[3] == 1) || (count_dice_values[4] == 1) || (count_dice_values[5] == 1) || (count_dice_values[6] == 1))
		{
			comb[11] = 50;
			comb_used[11] = 1;
			printf("%d\n", comb[11]);
		}
	}

	else if ((player_comb_choice == 13) && (comb_used[12] != 1)) //chance
	{
		comb[12] = (count_dice_values[1] + (count_dice_values[2] * 2) + (count_dice_values[3] * 3) + (count_dice_values[4] * 4) + (count_dice_values[5] * 5) + (count_dice_values[6] * 6));
		comb_used[12] = 1;
		printf("%d\n", comb[12]);
	}
}
/*********************************************************************************************
* Programmer: Ash Mahein                                                                     *
* Class: CptS 121; Lab Section 4                                                             *
* Programming Assignment: Yahtzee                                                            *
*                                                                                            *
* Date: 03/10/16                                                                             *
*                                                                                            *
* Description://Function for rerolling dice that the user has selected to reroll             *
*                                                                                            *
*                                                                                            *
*                                                                                            *
*                                                                                            *
*********************************************************************************************/
void reroll_dice(int *dice)
{
	int num_reroll = 0, count = 0, reroll_index = 0;

	printf("How many dice would you like to roll? ");
	scanf("%d", &num_reroll);
	for (count = 0; count < num_reroll; ++count)
	{
		printf("How many die would you like to reroll (1 - 5) ");
		scanf("%d", &reroll_index);
		dice[reroll_index - 1] = (rand() % 6 +1);
	}
}