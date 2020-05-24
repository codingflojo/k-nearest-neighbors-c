#ifndef TABLEHELPER_H
#define TABLEHELPER_H

typedef struct column {
	double value;
	struct column *nextColumn;
} column;

typedef struct line {
	struct column *firstColumn;
	struct line *nextLine;
	char *classification;
} line;

void createList(line* lineHeader, FILE* file, char *code);
void freeList(line* lineHeader);

#endif