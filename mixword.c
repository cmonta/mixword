#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

// to use isalpha
#include <ctype.h>

#define LENGTH 25

int shuffle(char* ptr);

void swap(char* a, char* b);


int main(int argc, char const *argv[])
{

  //check for valid arguments
  if (argc != 2)
    {
      printf("Usage: mixword textfile.txt\n");
      return 1;
    }

  // open file given by argument
  char* text = argv[1];
  FILE* fp = fopen(text, "r");
  if (fp == NULL)
    {
      printf("Could not open %s.\n", text);
      //unload();
      return 1;
    }

  //read each word from text file
  char word[LENGTH+1];
  //init index
  int index = 0;

  for (int c = fgetc(fp); c!= EOF; c = fgetc(fp))
    {
      //printf("%c\n", c);
      if (isalpha(c)) {
      word[index] = c;
      index++;
      }
      else {
      printf("%s\n", word);
      index = 0;
      }
    }

  /*
  for (int i = 0; i<sizeof(fp);i++)
    {
      printf("%s", fp[i]);
      printf("\n");
    }
  */
  fclose(fp);
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
