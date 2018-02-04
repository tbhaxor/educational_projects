#include <stdio.h>
#include <stdlib.h>
#include "config.h"
// ---------------
//  Function prototyping
// ---------------
void info();
int generateRandom();
char menu();
void play();
void rule();
void pause();
void clrscr();
void clearBuffer();


// -------------
//  Main function
// -------------
int main()
{
	// invoking all functions
	info();
	rule();
	play();
	return 0;
}

// -------------
// defining pause function to pause the output screen text
// -------------
void pause()
{
	printf("\n\n[!] Press any key to continue . . .");
	getchar(); // waiting until any character is pressed
}

// -------------
// defining clrscr function to clear the output string
// -------------
void clrscr()
{
	system(CLEAR);
}

// -------------
// defining info function to print the coder info
// -------------
void info()
{
	clrscr();
	printf("-------------------------------\n");
	printf("-                             -\n");
	printf("-         LUCKY 7 GAME        -\n");
	printf("-                             -\n");
	printf("-------------------------------\n\n\n");
	printf("Programmed By : %s\n", CODER);
	printf("Submitted To : %s\n", SUBMITTED_TO);
	printf("Institution : %s\n", INSTITUTION);
	pause();
}

// -------------
// defining play function to start the game
// -------------
void play()
{
	clrscr();
	float bet, total=0;
	int i;
	char ch;
	printf("-------------------------------\n");
	printf("-                             -\n");
	printf("-            GAME             -\n");
	printf("-                             -\n");
	printf("-------------------------------\n\n\n");
	printf("enter bet amount : ");
	scanf("%f", &bet);
	if(bet<100)
	{
		printf("You can't play with this much bet amount\n");
		return;
	}
	for(i = 1 ; i <= TRIES; i++)
	{
		printf("\n\n------ Tries Left : %d------\n", (TRIES - i) + 1);
		ch = menu();
		// validating accourding to rule
		if(ch=='e' || ch=='E' && generateRandom()==7)
			total+=bet*MULTIPLY_ON_7;
		else if((ch=='g' || ch=='G' && generateRandom()>7) || (ch=='L' || ch=='l' && generateRandom()<7))
			total += bet*MULTIPLY_ON_CORRECT;
	}
	printf("You will get %f amount\n", total);
}

// -------------
// defining rule function to print the game rules
// -------------
void rule()
{
	clrscr();
	printf("-------------------------------\n");
	printf("-                             -\n");
	printf("-            RULES            -\n");
	printf("-                             -\n");
	printf("-------------------------------\n\n\n");
	printf("1. You have %d tries\n", TRIES);
	printf("2. Number will be picked from 1 - 12\n");
	printf("3. You have to guess if the number to be generated will be 7 or greater than 7 or lesser than 7\n");
	printf("4. If you guessed 7 and its right, you will get %d times of bet money\n", MULTIPLY_ON_7);
	printf("5. If you guessed other than 7 and its right, you will get %d times of bet money\n", MULTIPLY_ON_CORRECT);
	printf("6. %d is the minimum amount for betting\n", MIN_BET);
	pause();
}

// -------------
// defining generateRandom function to return the random number 
// -------------
int generateRandom()
{
	return rand()%12 +1;  // rand() will generate the number %12 is for limit
}


// -------------
// defining menu function to print user guess selection menu
// -------------
char menu()
{
	printf("[E]qual to 7\t[L]esser than 7\t[G]reater than 7\n> ");
	char ch = getchar();
	clearBuffer();
	return ch;
}

// -------------
// defining clearBuffer function to clear the input stream buffer
// -------------
void clearBuffer()
{
	int c;
	while ( (c = getchar()) != '\n' && c != EOF ) { }
}