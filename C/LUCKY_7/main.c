// including header files and libs
#include <stdio.h>
#include <stdlib.h>
#include "config.h"
#include <ctype.h>

// function prototype
void aboutGame();
void menu();
void pause();
int randomNumber();
void info();
void clrscr();
void play();
void clearBuffer();

/*
 *  MAIN FUNCTION
 */
int main()
{
	info();
	aboutGame();
	play();
	return 0;
}

/*
 *  ----------------------------
 *	 Defining all the functions
 *  ----------------------------
 */

/*
 * Defining function to generate a random number b/w 1 - 12
 */
int randomNumber()
{

	return 1 + rand() % 12;  // getting a random number from 1 - 12
}

/*
 *  Defining function to pause the output
 */
void pause()
{
	printf("Press Any Key To Continue...");
	getchar();   // getchar() is defined in stdio.h for pausing the O/P screen
}

/*
 * Defining function to print coder info and the banner
 */
void info()
{
	clrscr();
	printf("\t\t\t===========================================\n");
	printf("\t\t\t=                                         =\n");
	printf("\t\t\t=          LUCKY SEVEN GAME IN C          =\n");
	printf("\t\t\t=                                         =\n");
	printf("\t\t\t===========================================\n");
	printf("Coded By : %s\n", CODER);
	printf("Submitted To : %s\n", SUBMITTED_TO);
	printf("Institution : %s\n\n\n", INSTITUTION);
	pause();  // calling pause function
}

/*
 * Defining function to clear the output screen
 */
void clrscr()
{
	system(CLEAR);   // clearing the output screen
}

/*
 * Defining function to print game rules and etd
 */
void aboutGame()
{
	clrscr();
	printf("\t\t\t===========================================\n");
	printf("\t\t\t=                                         =\n");
	printf("\t\t\t=        RULES and ABOUT THE GAME         =\n");
	printf("\t\t\t=                                         =\n");
	printf("\t\t\t===========================================\n\n");
	printf("You have to bet atleast %d rupees and you will be given %d tries. For each try you have to guess the following\n1. Will the number generated be less than 7\n2. Will the number generated be greater than 7\n3. Will the number generated be equal than 7\n\nIn case of right guess for first two guesses you will be rewarded with %d times of the bet amount. If you guess the number 7 and your guess is right, you will be rewarded with %d times of your bet amount. Also you won't be rewarded if you guess wrong\n\n", PRICE, TRIES, MONEY_ON_GUESS, MONEY_ON_7);
	pause();
}

/*
 * Defining the play function to play the game
 */
void play()
{
	clrscr();
	float bet, total=0;
	int tries = TRIES, count = 0;
	char opt;
	int rn;
	printf("\t\t\t===========================================\n");
	printf("\t\t\t=                                         =\n");
	printf("\t\t\t=              GAME STARTED               =\n");
	printf("\t\t\t=                                         =\n");
	printf("\t\t\t===========================================\n\n");
	printf("enter the bet amount : ");
	scanf("%f", &bet);
	printf("\n\n");

	if(bet<PRICE)
	{
		printf("Please bet more than %d\n", PRICE);
		return;
	}
	while(tries--)
	{
		rn = randomNumber();
		printf("--------- TRY %d ---------\n", TRIES - tries);
		menu();   // invoking menu function
		clearBuffer();   // invoking clearBuffer function
		opt = getchar();
		opt = toupper(opt);   // converting input case to upper

		// checking on the basis of the rule ;)
		if((opt == 'G' && rn > 7) || (opt == 'L' && rn < 7))
		{
			total += bet * MONEY_ON_GUESS;  // adding to the total
			count++;
		}
		else if(opt == 'E' && rn == 7)
		{
			total += bet * MONEY_ON_7;  // adding to the total
			count++;
		}
	}
	printf("\nYou won %d / %d tries\nYou got %f amount\n", count, TRIES, total );  // printing the wins and reward amount
}

/*
 * Defining the menu function to print the choice for the player
 */
void menu()
{
	printf("[L]ess than 7\n");
	printf("[G]reater than 7\n");
	printf("[E]qual to 7\n");
	printf("> ");
}

/*
 * Defining the function to flush input stream buffer
 */
void clearBuffer()
{
	char c;
	while ((c = getchar()) != '\n' && c != EOF); // flushing the input stream 
}