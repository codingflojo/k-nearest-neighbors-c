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
void readUserInput(line* classificationHeader);
void freeList(line* lineHeader);
void ranking(line* lineHeader, line* classificationHeader, rank* distanceRank, int k);
double euclideanDistance(column* currColumn, column* currColumnClassification);
void readK(int * k);
void printResult(rank* distanceRank, int k);

int main() {
	FILE* file = NULL;
	char* code = NULL;
	char c = 'y';
	readFile(&file, &code);
	line *lineHeader = (line*)malloc(sizeof(line));
	createList(lineHeader, file, code);
	
	do {
		int k = 0;
		readK(&k);
		line *classificationHeader = (line*)malloc(sizeof(line));
		readUserInput(classificationHeader);
		rank* distanceRank = malloc(k * sizeof(rank));
		ranking(lineHeader, classificationHeader, distanceRank, k);
		printResult(distanceRank, k);
		printf("%s", "\ndo you want to classify a new Entry y/n: ");
		scanf(" %c", &c);
	} while (c != 'n' && c != 'N');
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

void printResult(rank* distanceRank, int k) {
	printf("%s", "\n############################\n");
	for (int i = 0; i < k; i++) {
		printf("%s %s %s %f\n", "Classification: ", distanceRank[i].linePointer->classification, "distance: ", distanceRank[i].distance);
	}
	printf("%s", "############################\n");
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

void readUserInput(line* classificationHeader) {
	char str[1024];
	char c = 'y';
	column *columnptrPrevious = NULL;
	line *lineListPointer = classificationHeader;
	column *columnptr = (column*)malloc(sizeof(column));
	lineListPointer->firstColumn = columnptr;
	lineListPointer->classification = NULL;
	while (c != 'n' && c != 'N') {
		printf("%s", "Please Enter a Value: ");
		scanf("%lf", &columnptr->value);
		printf("%s", "do you want to add a new dimension y/n: ");
		scanf(" %c", &c);
		if (c != 'n' && c != 'N') {
			columnptr->nextColumn = (column*)malloc(sizeof(column));
			columnptr = columnptr->nextColumn;
		}
	}
	columnptr->nextColumn = NULL;
}

void ranking(line* lineHeader, line* classificationHeader, rank* distanceRank, int k) {
	int round = 0;
	while (lineHeader != NULL) {
		rank *newRank = (rank*)malloc(sizeof(rank));
		newRank->distance = sqrt(euclideanDistance(lineHeader->firstColumn, classificationHeader->firstColumn));
		newRank->linePointer = lineHeader; 
		if (round < k) {
			distanceRank[round++] = *newRank;
		}
		else {
			for (int i = 0; i < k; i++) {
				if (distanceRank[i].distance > newRank->distance) {
					rank rankHelper = distanceRank[i];
					distanceRank[i] = *newRank;
					newRank = &rankHelper;
				}
			}
		}
		lineHeader = lineHeader->nextLine;
	}
}


double euclideanDistance(column* currColumn, column* currColumnClassification) {
	double sum = 0;
	while (currColumn != NULL || currColumnClassification != NULL) {
		sum += pow((currColumnClassification != NULL ? currColumnClassification->value : 0) - (currColumn != NULL ? currColumn->value : 0), 2.0);
		if (currColumn != NULL) {
			currColumn = currColumn->nextColumn;
		}
		if (currColumnClassification != NULL) {
			currColumnClassification = currColumnClassification->nextColumn;
		}
	}
	return sum;
}

void readK(int* k) {
	printf("%s", "Please Enter a Value for K: ");
	scanf("%d", k);
}