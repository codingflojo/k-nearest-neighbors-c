#ifndef EUCLIDEANHELPER_H
#define EUCLIDEANHELPER_H

typedef struct rank {
	struct line* linePointer;
	double distance;
} rank;

double euclideanDistance(column* currColumn, column* currColumnClassification);
void ranking(line* lineHeader, line* classificationHeader, rank* distanceRank, int k);

#endif
