#include <stdio.h>


void show_word(char*);
int length(char*);


int
main()
{
	char word[]="printf";
	show_word(word);
	return 0;
}


void
show_word(char *word)
{
	const int n = length(word);
	const char sub[]="\033[4m", normal[]="\033[m";

	printf("size %d\n", n);
	printf("%s", sub);
	for (int i=0; i < n; ++i) {
		printf("%c", word[i]);
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

