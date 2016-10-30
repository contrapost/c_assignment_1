## Assignment 1

### Opening the file
Reading from file is managed in the first part of the program (see respective comment). Inlines 16-20 the program checks if the user forgot to pass any arguments when running the program from command line, i.e. there is no file name at all. User receives an error message if it’s necessary. Further the program checks if it’s possible to open a file with the name entered by user (i.e. if the name/file exists). If there is no such file program terminates and user receives an error message. 

### Reading from the file
The program uses 2D dynamic array to store lines from the file.
When the file is opened the program creates a pointer to char pointers, allocates memory for pointers and iterates through all lines in the file. Original size of allocated memory is sufficient for 20 char pointers (sizeOfArray variable) and each of them points to memory for 256 chars (LENGTH_OF_LINE constant). 
Program uses counter variable to track the number of lines that was written to the allocated memory. When/If sizeOfArray is equal to counter the program double the number of char pointers and reallocate memory. 
When there is no new lines in the file the program closes it and calls the sort function.

### Sorting
Program uses sort method that takes reference to the 2D array and its length as parameters and returns a sorted array. 
Program uses Bubble sort algorithm. First, the program checks if the length of array is less or equal to 1 (i.e. array is empty or contains only one element) and so it’s sorted by default and can be returned.
If the program deals with an array that contains more than one element it uses Bubble sort to sort the lines alphabetically by calling strcmp method. Program stops to iterate through the array if none of the elements were swapped through an iteration (meaning that the array is already sorted). So the program saves some resources. If the array was sorted originally the program will iterate through it only once. 

### Printing and freeing the memory
When the sorted array is returned to the main method the program prints it to console (and adds line number before each line to make it easy to debug or check if all lines were printed). At the end of executing the program frees the used memory (by calling free method for all of the strings and for the array itself at the end). 