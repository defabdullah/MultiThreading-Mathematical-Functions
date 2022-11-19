#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <iostream>
#include <chrono>
#include <bits/stdc++.h>

#define MAX_NUMBER 10000
#define MIN_NUMBER 1000

typedef void* (*fp)(void *);

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


#endif