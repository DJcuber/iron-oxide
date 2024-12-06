#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"

char* readFile(char *fileName) {
  FILE *filePtr = fopen(fileName, "rb");

  if (filePtr == NULL) {
    printf("Could not read file.\n");

    fclose(filePtr);
    return NULL;
  }

  char *contents = 0;

  fseek(filePtr, 0, SEEK_END); // Sets file pointer to the end
  long len = ftell(filePtr);   // Reads how many characters are before the pointer (length of the file) (I think)
  fseek(filePtr, 0, SEEK_SET); // Sets file pointer to the start
  
  contents = malloc(len + 1);  // Allocates memory to contents
  
  if (contents) {
    fread(contents, 1, len, filePtr);
  }  
  
  contents[len] = '\0';

  fclose(filePtr);
  
  return contents;
}

//argc stores number of arguments, argv stores an array of strings containing the arguments
int main(int argc, char **argv) {
  printf("Funny haha!\n");

  if (argc >= 2) {
    printf("The first command line argument is %s\n", argv[1]);
  }

  char* fileContents = readFile("text-file.txt");

  printf("%s\n", fileContents);

  importTest();

  return 0;
}

/*
Compile by doing:
"gcc -o main.exe *.c"
*/