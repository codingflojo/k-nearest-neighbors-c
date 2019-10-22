/* k_nearest_neigbhours */
/*codingflojo*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct column {
	double value;
	struct column *nextColumn;
} column;

typedef struct line {
	struct column *firstColumn;
	struct line *nextLine;
	char *classification;
} line;

typedef struct rank {
	struct line* linePointer;
	double distance;
} rank;

void readFile(FILE** file, char** code);
void createList(line* lineHeader, FILE* file, char *code);
void freeList(line* lineHeader);
void euclideanDistance(line* lineHeader, rank* distanceRank, int k);

int main() {
	FILE* file = NULL;
	char* code = NULL;
	printf("%s","K:");
	int k = 0;
    scanf("%d", &k);
	rank* distanceRank = malloc(k * sizeof(rank));

	readFile(&file, &code);
	line *lineHeader = (line*)malloc(sizeof(line));
	createList(lineHeader, file, code);
	euclideanDistance(lineHeader, distanceRank, k);
	freeList(lineHeader);
	return 0;
}

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

void createList(line* lineHeader, FILE* file, char *code) {
	size_t n = 0;
	int c = 0;
	int isAlpha = 0;
	column *columnptr = NULL;
	column *columnptrPrevious = NULL;
	line *lineListPointer = lineHeader;
	lineListPointer->firstColumn = NULL;
	lineListPointer->classification = NULL;
	// Read Character after Character till End of File
	while (c = fgetc(file)) {
		if ((c > 47 && c < 58) || c == 46) {
			code[n++] = (char)c;
		}
		else if (isalpha(c)) {
			isAlpha = 1;
			code[n++] = (char)c;
		}
		else {
			code[n++] = '\0';
			if (isAlpha) {
				lineListPointer->classification = malloc(n);
				strncpy(lineListPointer->classification, code, n);
				isAlpha = 0;
			}
			else {
				if (lineListPointer->firstColumn == NULL) {
					columnptr = (column*)malloc(sizeof(column));
					lineListPointer->firstColumn = columnptr;
				}
				else {
					columnptr->nextColumn = (column*)malloc(sizeof(column));
					columnptrPrevious = columnptr;
					columnptr = columnptr->nextColumn;
				}
				columnptr->value = atof(code);
			}
			if (c == EOF) {
				if (lineListPointer->classification == NULL) {
					lineListPointer->classification = malloc(n);
					strncpy(lineListPointer->classification, code, n);
					columnptrPrevious->nextColumn = NULL;
					free(columnptr);
					columnptr = NULL;
				}
				else {
					columnptr->nextColumn = NULL;
				}
				lineListPointer->nextLine = NULL;
				break;
			} else if (c == '\n') {
				if (lineListPointer->classification == NULL) {
					lineListPointer->classification = malloc(n);
					strncpy(lineListPointer->classification, code, n);
					columnptrPrevious->nextColumn = NULL;
					free(columnptr);
					columnptr = NULL;
				}
				else {
					columnptr->nextColumn = NULL;
				}
				line *newLine = (line*)malloc(sizeof(line));
				lineListPointer->nextLine = newLine;
				lineListPointer = lineListPointer->nextLine;
				lineListPointer->classification = NULL;
				lineListPointer->firstColumn = NULL;
			}
			n = 0;
		}
	}
}

void freeList(line* lineHeader) {
	while (lineHeader != NULL) {
		column* currColumn = lineHeader->firstColumn;
		while (currColumn != NULL) {
			column* temp = currColumn;
			currColumn = currColumn->nextColumn;
			free(temp);
		}
		line* currLine = lineHeader;
		lineHeader = lineHeader->nextLine;
		free(currLine);
	}
}

void euclideanDistance(line* lineHeader, rank* distanceRank, int k) {

}