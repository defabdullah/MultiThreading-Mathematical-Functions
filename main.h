#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <iostream>
#include <chrono>
#include <bits/stdc++.h>
#include <algorithm>
#include <iterator>

#define MAX_NUMBER 10000
#define MIN_NUMBER 1000
#define METHOD_NUMBER 10

typedef void* (*met)(void *);

extern int size;
extern void *min(void *arr);
extern void *range(void *arr);
extern void *mode(void *arr);
extern void *median(void *arr);
extern void *max(void *arr);
extern void *sum(void *arr);
extern void *arithmeticMean(void *arr);
extern void *harmonicMean(void *arr);
extern void *standardDeviation(void *arr);
extern void *interquartileRange(void *arr);

extern void *minAndInterQuartileRange(void *arr);
extern void *maxAndStandardDeviation(void *arr);
extern void *rangeAndHarmonicMean(void *arr);
extern void *modeAndArithmeticMean(void *arr);
extern void *medianAndSum(void *arr);
void *mySort(void *arr);

extern void** dresults[5];

#endif