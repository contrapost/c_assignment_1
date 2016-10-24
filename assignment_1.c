#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define LENGTH_OF_LINE 256

char** sort(char **array, int counter);

int main(int argc, char* argv[]){

	// ================== 1. dealing with file ==============================

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
	else 
	{
   	 	printf("%s\n", "There is no file with such name!");
		return -1;
	}
	
	free(filename);
	
	// ================== 2. populating the array ===========================
	
	char **lines; // Pointer to pointers to a number of characters
	int sizeOfArray = 20; // Original number of strings 
	int counter = 0; // Counts number of actual strings
	char line[LENGTH_OF_LINE]; // Default string with default length
	
	// Allocate memory for array of strings
	lines = malloc(sizeOfArray * sizeof(char*));
	
	// Allocate array of chars (representing string) on each index of
	// the original array (lines)
	for(int i = 0; i < sizeOfArray; i++)
	{
		lines[i]=malloc(LENGTH_OF_LINE * sizeof(char));
	}
	
	// Iterates through all lines in file and reallocates memory when necessary
	while (fgets(line, LENGTH_OF_LINE, file)) 
	{
        
        if (sizeOfArray > counter) 
        {
        	strcpy(lines[counter++], line);
		} 
		else // if number of strings is equal to the length of array we double 
		{    // the size of the array
			sizeOfArray++;
			lines = realloc(lines, sizeof(char*)*(sizeOfArray));
			if (lines == NULL) {
				printf("Can't allocate memory\n");
		  		return -1;
			}
			
			for(int i = 0; i < sizeOfArray; i++)
			{
				lines[i]=realloc(lines[i], LENGTH_OF_LINE * sizeof(char));
				if (lines[i] == NULL) {
				printf("Can't allocate memory\n");
		  		return -1;
				}
			}
			strcpy(lines[counter++], line);
		}
    }
	
	// Closes the file
	fclose(file);
	
	// ============ 3. sorting and printing the array =======================
	
	// Calls sort function
	lines = sort(lines, counter);
	
	// Prints the result
	for(int i = 0; i < counter; i++) {
		printf("%d. %s", i + 1, lines[i]);
	}
	
	for(int i = 0; i < sizeOfArray; i++) {
		free(lines[i]);
	}
	
	// Frees allocated memory
	free(lines);
	
	return 0;
} 

char** sort(char **array, int length){
	int cmp;
    char tmpLine[LENGTH_OF_LINE];

    if (length <= 1)
        return array; // Already sorted

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length-1; j++)
        {
            cmp = strcmp(array[j], array[j+1]);

            if (cmp > 0)
            {
                strcpy(tmpLine, array[j+1]);
                strcpy(array[j+1], array[j]);
                strcpy(array[j], tmpLine);
            }
        }
    }

	return array;
}

