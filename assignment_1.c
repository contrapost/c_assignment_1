#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define LENGTH_OF_LINE 256

void sort(char **array, int counter);

int main(int argc, char* argv[]){

	// Checks if there is no arguments (filename isn't mentioned)
	if(argc < 2) 
	{
		printf("%s\n", "You forgot to write a name of file as argument!");
		return -1;
	}

	char *filename;
	filename = malloc(20*sizeof(char));
	strcpy(filename, argv[1]);
	
	FILE * file;
	
	// Checks if the file exists and opens it
	if(access(filename, F_OK ) != -1)
	{
    	file = fopen(filename, "r");
	} 
	else {
   	 	printf("%s\n", "There is no file with such name!");
		return -1;
	}
	
	char **lines;
	int sizeOfArray = 20;
	int counter = 0;
	
	lines = malloc(sizeOfArray * sizeof(char*));
	
	for(int i = 0; i < sizeOfArray; i++)
	{
		lines[i]=malloc(LENGTH_OF_LINE * sizeof(char));
	}
	
	char line[LENGTH_OF_LINE];
	
	while (fgets(line, LENGTH_OF_LINE, file)) {
        /* note that fgets don't strip the terminating \n, checking its
           presence would allow to handle lines longer that sizeof(line) */ 
        
        if (sizeOfArray > counter) {
			lines[counter++] = line;
			printf("%d. %s", counter, lines[counter - 1]);
		} 
		else {
			sizeOfArray *= 2;
			lines = realloc(lines, sizeof(char*)*(sizeOfArray++));
			lines[counter++] = line;
			printf("(from else) %d. %s", counter, lines[counter - 1]);
			if (lines == NULL) {
				printf("Can't allocate memory\n");
		  		return -1;
			}
		}
    }
	
	fclose(file);
	
	for(int i = 0; i < counter; i++) {
		printf("%d. %s", i, lines[i]);
	}
	
	sort(lines, counter);
	
	return 0;
} 

void sort(char **array, int length){
	//int swap = 0;
	
	for(int i = 0; i < length; i++) {
		printf("%d. %s", i, array[i]);
	}
	
	printf("length: %d", length);
	
	free(array);
}

