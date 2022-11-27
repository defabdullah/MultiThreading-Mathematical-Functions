#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <pthread.h>
#include <bits/stdc++.h>

#define MAX_NUMBER 10000
#define MIN_NUMBER 1000
#define METHOD_NUMBER 10

typedef void* (*met)(void*);

extern double results[10];
extern int* arr;
extern int size;

extern void *findMin(void* arg);
extern void *findMax(void* arg);
extern void *range(void* arg);
extern void *mode(void* arg);
extern void *median(void* arg);
extern void *sum(void* arg);
extern void *arithmeticMean(void* arg);
extern void *harmonicMean(void* arg);
extern void *standardDeviation(void* arg);
extern void *interquartileRange(void* arg);

extern void *minAndInterQuartileRange(void* arg);
extern void *maxAndStandardDeviation(void* arg);
extern void *rangeAndHarmonicMean(void* arg);
extern void *modeAndArithmeticMean(void* arg);
extern void *medianAndSum(void* arg);

#endif