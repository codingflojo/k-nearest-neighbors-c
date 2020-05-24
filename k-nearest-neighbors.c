/* k_nearest_neigbhours */
/*flomagnific*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include "tablehelper.h"
#include "filehelper.h"
#include "euclideanhelper.h"

void readUserInput(line* classificationHeader);
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

void printResult(rank* distanceRank, int k) {
	printf("%s", "\n############################\n");
	for (int i = 0; i < k; i++) {
		printf("%s %s %s %f\n", "Classification: ", distanceRank[i].linePointer->classification, "distance: ", distanceRank[i].distance);
	}
	printf("%s", "############################\n");
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

void readK(int* k) {
	printf("%s", "Please Enter a Value for K: ");
	scanf("%d", k);
}