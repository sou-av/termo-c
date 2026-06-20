#include <stdio.h>


#define MAX_TRIES 3


void show_word(int,char*);
void show_guess(int,char*,char*);
int length(char*);
int contains(char,char*);


int
main()
{
	char word[]="printf";
	const int n = length(word);
	char guess[n];
	int tries=0;
	
	show_word(n, word);
	
	for (int i=0; i < MAX_TRIES; ++i) {
		printf("What's your guess? (%d/%d)\n--> ", i+1, MAX_TRIES);
		guess[0] = 0;  // clean guess
		scanf("%s", guess);
		show_guess(n, guess, word);
	}

	return 0;
}


void
show_word(int n, char *word)
{
	const char sub[]="\033[4m", normal[]="\033[m";

	printf("%s", sub);
	for (int i=0; i < n; ++i) {
		putchar(word[i] ? word[i] : ' ');
	}
	printf("%s", normal);
	putchar('\n');
}


void
show_guess(int n, char *guess, char *word)
{
	const char sub[]="\033[4m", normal[]="\033[39;40m", reset[]="\033[m",
	           green[]="\033[30;42m", yellow[]="\033[30;43m";
	int i;

	printf("%s", sub);
	for (i=0; i < n && guess[i]; ++i) {
		printf("%s%c", guess[i] == word[i] ?
		                   green : contains(guess[i],word) ? yellow : normal,
			guess[i]);
	}
	printf("%s", normal);
	for (; i < n; ++i)
		putchar(' ');
	printf("%s", reset);
	putchar('\n');
}


int
length(char *word)
{
	int i;
	for (i=0; word[i]; ++i)
		;
	return i;
}


int
contains(char c, char *word)
{
	for (int i=0; word[i]; ++i)
		if (word[i] == c) return 1;
	return 0;
}

