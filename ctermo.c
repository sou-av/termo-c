#include <stdio.h>


void show_word(int,char*);
void show_guess(int,char*,char*);
int length(char*);


int
main()
{
	char word[]="printf";
	const int n = length(word);
	char guess[n]={};
	
	show_word(n, word);
	show_word(n, guess);
	
	printf("What's your guess?\n--> ");
	scanf("%s", guess);
	show_guess(n, guess, word);

	return 0;
}


void
show_word(int n, char *word)
{
	const char sub[]="\033[4m", normal[]="\033[m";

	printf("size %d\n", n);
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
	const char sub[]="\033[4m", normal[]="\033[40;39m", 
	           green[]="\033[30;42m", yellow[]="\033[33m";

	printf("size %d\n", n);
	printf("%s", sub);
	for (int i=0; i < n; ++i) {
		printf("%s%c", guess[i] == word[i] ? green : normal,
			guess[i] ? guess[i] : ' ');
	}
	printf("%s", normal);
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

