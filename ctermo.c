#include <stdio.h>


void show_word(int,char*);
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
	show_word(n, guess);

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


int
length(char *word)
{
	int i;
	for (i=0; word[i]; ++i)
		;
	return i;
}

