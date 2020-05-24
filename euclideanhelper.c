#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include "tablehelper.h"
#include "euclideanhelper.h"


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