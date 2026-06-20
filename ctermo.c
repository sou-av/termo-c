#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

#define MAX_TRIES 3
#define FILENAME "words.txt"


void show_word(int,char*);
void show_guess(int,char*,char*);
void random_pick(char *word, char *hint);
int length(char*);
int contains(char,char*);
int is_equal(char*,char*);
int count_lines(FILE*);


int
main()
{
	char word[BUFSIZ], guess[BUFSIZ], hint[BUFSIZ];
	int n, i, tries=0;

	srand(time(NULL));
	setlocale(LC_ALL, "Portuguese");
	
	random_pick(word, hint);
	n = length(word);

	show_word(n, word);

	i = 0;
	while (i < MAX_TRIES) {
		printf("What's your guess? (%d/%d)\n--> ", i+1, MAX_TRIES);
		guess[0] = 0;  // clean guess
		scanf("%s", guess);
		++i;

		if (i+1 == MAX_TRIES - 1)
			puts("If you want, you can type '?' to get a hint");

		if (guess[0] == '?')
			printf("Hint: %s\n\n", hint);
		else
			show_guess(n, guess, word);

		if (is_equal(guess, word))
			break;
	}


	if (is_equal(guess, word))
		puts("\nCONGRATULATIONS! You WON!!");
	else
		puts("\nNot this time.. Looser");

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


int
is_equal(char *a, char *b)
{
	for (int i=0; a[i] && b[i]; ++i)
		if (a[i] != b[i]) return 0;
	return 1;
}


int
count_lines(FILE *f)
{
	int lines=0;
	char s[BUFSIZ];
	while (fgets(s, BUFSIZ, f)) ++lines;
	return lines;
}

void
random_pick(char word[], char *hint)
{
	int i;
	FILE *f = fopen(FILENAME, "r");
	const int lines = count_lines(f),
	          pick = rand() % lines;
	
	// sem usar seek
	fclose(f);
	f = fopen("words.txt", "r");
	for (i=0; i < pick; ++i)
		fgets(word, BUFSIZ, f);

	fscanf(f, "%s", word);
	
	fgets(hint, BUFSIZ, f);
	for (i=0; hint[i]; ++i)
		if (hint[i] == '\n')
			hint[i] = 0;

	fclose(f);
}

