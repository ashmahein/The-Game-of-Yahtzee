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
#include <stdio.h>
#include<stdlib.h>
#include<time.h>

//Function Definitons.
void game_menu(void);
void roll_die(int *dice, int size);
void determine_count_of_each_die(int dice[], int size_dice, int count[]);
int sum(int total_dice[], int dice);
void score_obtained(int comb[], int comb_used[], int dice_count[], int size, int count_dice_values[]);
void reroll_dice(int *dice);
void print_dice(int *dice, int size);