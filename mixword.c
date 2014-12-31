#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

// to use isalpha
#include <ctype.h>

#define LENGTH 25

char EXTENSION[] = "mix_";

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

  char* ofpname = EXTENSION;

  //todo create an output filename
  strcat(ofpname, text);


  FILE* fp = fopen(text, "r");
  if (fp == NULL)
    {
      printf("Could not open %s.\n", text);
      return 1;
    }

  // open outputfile to write mixed text
  FILE* ofp = fopen(ofpname, "w");
  if (ofp == NULL)
    {
      printf("Could not open outputfile");
      return 1;
    }

  //read each word from text file
  char word[LENGTH+1];
  //init index
  int index = 0;

  for (int c = fgetc(fp); c!= EOF; c = fgetc(fp))
    {
      if (isalpha(c)) {
      word[index] = c;
      index++;
      }
      else {
      shuffle(word);
      printf("%s", word);
      fprintf(ofp, "%s", word);
      printf("%c", c);
      fprintf(ofp, "%c", c);
      index = 0;
      memset(word, 0, sizeof(word));
      }
    }
  printf("\n");
  fprintf(ofp, "\n");

  fclose(fp);
  fclose(ofp);
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

	return 0;

}

void swap(char* a, char* b) {
	char temp = *a;
	*a = *b;
	*b = temp;
}
