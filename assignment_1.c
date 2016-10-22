#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){

	if(argc < 2) 
	{
		printf("%s\n", "You forgot to write a name of file as argument!");
		return 0;
	}

	char *filename;
	filename = malloc(20*sizeof(char));
	strcpy(filename, argv[1]);
	char line[256];
	
	FILE * file = fopen(filename, "r");
	
	while (fgets(line, sizeof(line), file)) {
        /* note that fgets don't strip the terminating \n, checking its
           presence would allow to handle lines longer that sizeof(line) */
        printf("%s", line); 
    }
	
	fclose(file);
	
	return 0;
} 
