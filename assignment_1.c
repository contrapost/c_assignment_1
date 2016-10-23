#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char* argv[]){

	// Checks if there is no arguments (filename isn't mentioned)
	if(argc < 2) 
	{
		printf("%s\n", "You forgot to write a name of file as argument!");
		return 0;
	}

	char *filename;
	filename = malloc(20*sizeof(char));
	strcpy(filename, argv[1]);
	char line[256];
	
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
	
	while (fgets(line, sizeof(line), file)) {
        /* note that fgets don't strip the terminating \n, checking its
           presence would allow to handle lines longer that sizeof(line) */
        printf("%s", line); 
    }
	
	fclose(file);
	
	return 0;
} 

