#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define MAX 45

int shuffle(char* ptr);

void swap(char* a, char* b);


int main(void)
{
	/* code */
	char a[20];

	printf("Entrez un mot : ");
	scanf("%s", a);

	printf("A est égal à %s\n", a);

	shuffle(a);

	printf("Le retour est %s\n", a );

	return 0;
}

int shuffle(char* word)
{
	
	int length = strlen(word);

	if (length < 4) {
		return 1;
	}

	srand(time(NULL));


	for (int i = length - 3; i > 0; i--) {
		int j = rand() % (i+1);

		swap(&word[i+1], &word[j+1]);
	}

	printf("the parameter is %s\n", word );

	printf("%d\n", length);

	return 0;

}

void swap(char* a, char* b) {
	char temp = *a;
	*a = *b;
	*b = temp;
}
