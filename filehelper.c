#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include "filehelper.h"

void readFile(FILE** file, char** code) {
	*file = fopen("input.txt", "r");
	long fSize = 0;

	if (*file == NULL) {
		return;
	}
	fseek(*file, 0, SEEK_END); // Put Cursor to end of File
	fSize = ftell(*file); // Get the Position of the Cursor in File
	fseek(*file, 0, SEEK_SET); // Put the Cursor to the beginning of the File 
	*code = malloc(fSize); // Allocate space for the File
}