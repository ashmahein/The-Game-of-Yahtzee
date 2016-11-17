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

int main(void)
{
	//Variable declartion.
	srand((int)time(NULL));
	int dice_roll = 0, total_dice = 0, sum_of_each_die = 0, dice[5] = {0}, dice_tally = 0, index = 0, count_dice_values[7] = { 0 };
	int player_choice = 0, player_one_total = 0, player_two_total = 0;
	int comb[13] = { 0 }, comb_used[13] = { 0 }, dice_count[7] = { 0 };
	char player_1_input = '\0', player_2_input = '\0', game_combination_choice = '\0';
	int total_rolls = 0, total_rounds = 0;
	char game_play = 'y';
	//If the rounds played is less than 14 and game play is YES then the game executes.
	if ((game_play == 'y') && (total_rounds != 14))
	{
		//Asks player 1 if they want to play yahtzee.
		printf("Players 1 would you both like to play yahtzee?<Y/N>\n");

		scanf(" %c", &player_1_input);

		//If player 1 doesn't want to play yahtzee then the game exits with a message.
		if (player_1_input == 'n')
		{
			printf("Hope you play next time!\n");
		}
		//If player input is YES then the game will give the user a menu.
		while (player_1_input == 'y')
		{
			do
			{
				//Menu options for printing game rules, playing game or exiting.
				printf("Welcome to Yahtzee!\n");

				printf("Please choose one option.\n");

				printf("1. Game Rules.\n2. Play Yahtzee\n3. Exit Game.\n");

				scanf("%d", &player_choice);

				system("pause");
				system("cls");

			} while ((player_choice < 1) || (player_choice > 3));
			//Prints game rules.
			if (player_choice == 1)
			{
				game_menu();
				system("pause");
				system("cls");
			}
			//Game play begins.
			while ((player_choice == 2) && (total_rounds != 14))
			{	
				//Sets everything to zero before player 1 begins their rounds.
				dice_roll = 0;
				total_dice = 0;
				sum_of_each_die = 0;
				for (index = 0; index < 13; index++)
					comb[index] = 0;
				for (index = 0; index < 13; index++)
					comb_used[index] = 0;
				for (index = 0; index < 7; index++)
					dice_count[index] = 0;
				for (index = 0; index < 5; index++)
					dice[index] = 0;
				dice_tally = 0;
				for (index = 0; index < 7; index++)
					count_dice_values[index] = 0;
				index = 0;
				//Player has to hit a button in order to roll.
				printf("Player 1's turn.\n");
				printf("Hit any button to roll dice.\n");

				system("pause");
				system("cls");
				//rolls dice.
				roll_die(dice, 5);
				//total rolls for player 1s turn is set to zero for each round.
				total_rolls = 0;
				//total rolls gets added up.
				total_rolls += 1;
				//prints out the dice rolls.
				print_dice(dice, 5);
				//Count up the number of times each number is rolled.
				determine_count_of_each_die(dice, 5, count_dice_values, 7);
				//Tally's up the numbers displayed on each die.
				for (dice_tally = 1; dice_tally < 7; dice_tally++)
				{
					sum_of_each_die = sum(count_dice_values, dice_tally);
				}
				//While total rolls is not 3 then player is prompted to either reroll or enter a game combination.
				while (total_rolls != 3)
				{
					printf("Would you like to use this roll as a game combination?<Y/N>\n");
					scanf(" %c", &game_combination_choice);
					//If player chooses a to use a game combination then conditonal statement is entered.
					if (game_combination_choice == 'y')
					{
						//Calculates score.
						score_obtained(comb, comb_used, count_dice_values, 13, count_dice_values);
					}
					//If player wants to reroll the below conditonal is entered.
					if (game_combination_choice == 'n')
					{
						//Sets the counting dice values to zero before reroll.
						for (index = 0; index < 7; index++)
							count_dice_values[index] = 0;
						//reroll of dice
						reroll_dice(dice);
						total_rolls += 1;
						determine_count_of_each_die(dice, 5, count_dice_values, 7);
						print_dice(dice, 5);
						//Prompts user if they would like to store their new dice values.
						printf("Would you like to use this roll as a game combination?<Y/N>\n");
						scanf(" %c", &game_combination_choice);
						if (game_combination_choice == 'y')
						{
							//If player wants to store their new dice values then they can.
							score_obtained(comb, comb_used, count_dice_values, 13, count_dice_values);
						}
						//If player wants to reroll they enter the conditional below.
						else if (game_combination_choice == 'n')
						{
							for (index = 0; index < 7; index++)
								count_dice_values[index] = 0;
							reroll_dice(dice);
							total_rolls += 1;
							determine_count_of_each_die(dice, 5, count_dice_values, 7);
							print_dice(dice, 5);
							printf("Would you like to use this roll as a game combination?<Y/N>\n");
							scanf(" %c", &game_combination_choice);
							score_obtained(comb, comb_used, count_dice_values, 13, count_dice_values);
						}
						//Increments total rolls after reroll loop has been exited.
						total_rolls += 1;
					}
					//Computer player ones score and prints it to the screen when rolls have been made or a combination has been choosen.
					if ((total_rolls == 3) || (comb_used[0] == 1) || (comb_used[1] == 1) || (comb_used[2] == 1) || (comb_used[3] == 1) || (comb_used[4] == 1) || (comb_used[5] == 1) || (comb_used[6] == 1) || (comb_used[7] == 1) || (comb_used[8] == 1) || (comb_used[9] == 1) || (comb_used[10] == 1) || (comb_used[11] == 1) || (comb_used[12] == 1))
					{
						player_one_total = comb[0] + comb[1] + comb[2] + comb[3] + comb[4] + comb[5] + comb[6] + comb[7] + comb[8] + comb[9] + comb[10] + comb[11] + comb[12] + player_one_total;
						printf("Player 1 total is %d\n", player_one_total);
						system("pause");
						system("cls");
						break;
					}
				}
				//Sets all combinations used and dice values to zero.
				for (index = 0; index < 13; index++)
					comb[index] = 0;
				for (index = 0; index < 13; index++)
					comb_used[index] = 0;
				for (index = 0; index < 7; index++)
					dice_count[index] = 0;
				dice_roll = 0;
				total_dice = 0;
				sum_of_each_die = 0;
				for (index = 0; index < 5; index++)
					dice[index] = 0;
				dice_tally = 0;
				for (index = 0; index < 7; index++)
					count_dice_values[index] = 0;
				index = 0; 
				//Asks player two if they would like to play yahtzee.
				printf("Player 2 it's your turn. Players 2 would you both like to play/keep playing yahtzee? <Y/N>\n");

				scanf(" %c", &player_2_input);

				system("pause");
				system("cls");
				//If player two says NO then game exits.
				if (player_2_input == 'n')
				{
					printf("Player 1 wins. Hope you play next time!\n");
					break;
				}
				//If player two wants to play then game continues.
				if (player_2_input == 'y')
				{
					//Total rolls are set to zero again.
					total_rolls = 0;
					printf("Hit any button to roll dice.\n");
					system("pause");
					system("cls");
					//Rolls dice
					roll_die(dice, 5);
					//Prints dice 
					print_dice(dice, 5);
					//Total rolls is incremented.
					total_rolls += 1;
					//Calculates the number of times each dice is rolled
					determine_count_of_each_die(dice, 5, count_dice_values, 7);

					for (dice_tally = 1; dice_tally < 7; dice_tally++)
					{
						sum_of_each_die = sum(count_dice_values, dice_tally);
					}
					//While the total rolls isn't 3 the player is asked to either reroll or choose a game combinations.
					while (total_rolls != 3)
					{
						//Asks user if they would like to use a game combination.
						printf("Would you like to use this roll as a game combination?<Y/N>\n");
						scanf(" %c", &game_combination_choice);
						//If player wants to use their dice rolls for a game combination then they can.
						if (game_combination_choice == 'y')
						{
							score_obtained(comb, comb_used, count_dice_values, 13, count_dice_values);
						}
						//If the player wants to reroll certain dice they can with the conditional statement below.
						if (game_combination_choice == 'n')
						{
							//Set the dice values to zero.
							for (index = 0; index < 7; index++)
								count_dice_values[index] = 0;
							reroll_dice(dice);
							determine_count_of_each_die(dice, 5, count_dice_values, 7); 
							print_dice(dice, 5);
							printf("Would you like to use this roll as a game combination?<Y/N>\n");
							scanf(" %c", &game_combination_choice);
							//If the player wants to store their dice values they can below.
							if (game_combination_choice == 'y')
							{
								score_obtained(comb, comb_used, count_dice_values, 13, count_dice_values);
							}
							//If player wants to reroll they can below.
							else if (game_combination_choice == 'n')
							{
								//Sets dice values back to zero before the reroll.
								for (index = 0; index < 7; index++)
									count_dice_values[index] = 0;
								//Rerolls dice.
								reroll_dice(dice);
								total_rolls += 1;
								determine_count_of_each_die(dice, 5, count_dice_values, 7);
								print_dice(dice, 5);
								printf("Would you like to use this roll as a game combination?<Y/N>\n");
								scanf(" %c", &game_combination_choice);
								score_obtained(comb, comb_used, count_dice_values, 13, count_dice_values);
							}
							//Increments the total rolls.
							total_rolls += 1;
						}
						//When player 2s had choosen a combination to use or have rolled 3 times the sum will be calculated.
						if ((total_rolls == 3) || (comb_used[0] == 1) || (comb_used[1] == 1) || (comb_used[2] == 1) || (comb_used[3] == 1) || (comb_used[4] == 1) || (comb_used[5] == 1) || (comb_used[6] == 1) || (comb_used[7] == 1) || (comb_used[8] == 1) || (comb_used[9] == 1) || (comb_used[10] == 1) || (comb_used[11] == 1) || (comb_used[12] == 1))
						{
							player_two_total = comb[0] + comb[1] + comb[2] + comb[3] + comb[4] + comb[5] + comb[6] + comb[7] + comb[8] + comb[9] + comb[10] + comb[11] + comb[12] + player_two_total;
							printf("Player 2 total is %d\n", player_two_total);
							system("pause");
							system("cls");
							break;
						}
					}
					//The total round played is incremented.
					total_rounds += 1;
				}
			}
			//If all rounds have been played by both players then the winner is announced.
			if (total_rounds == 14)
			{
				printf("Game over.\n");
				//If player one wins then the below conditonal is entered.
				if (player_one_total > player_two_total)
				{
					//If player 1's upper combination total is greater than 63 then 35 gets added to their total score.
					if ((comb[0] + comb[1] + comb[2] + comb[3] + comb[4] + comb[5]) >= 63)
					{
						player_one_total += 35;
						printf("Player one wins.\n");
						printf("Player one total: %d\n", player_one_total);
						printf("Player two total: %d\n", player_two_total);
						printf("Thanks for playing.\n");
						break;
					}
				}
				//If player one wins then the below conditonal is entered.
				else
				{
					//If player 2's upper combination total is greater than 63 then 35 gets added to their total score.
					if ((comb[0] + comb[1] + comb[2] + comb[3] + comb[4] + comb[5]) >= 63)
					{
						player_two_total += 35;
						printf("Player two wins.\n");
						printf("Player one total: %d\n", player_one_total);
						printf("Player two total: %d\n", player_two_total);
						printf("Thanks for playing.\n");
						break;
					}
				}
			}
			if (player_choice == 3)
			{
				printf("Thanks for playing.\n");
				break;
			}
		}
	}
	system("pause");

	return 0;
}