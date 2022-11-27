#include "main.h"
using namespace std;

// my sort method
void *mySort(void *arr){
    int *sort_arr=(int*)malloc(sizeof(int)*size);
    for(int i=0;i<size;i++){
        sort_arr[i]= *((int*)arr+i);
    }
    sort(sort_arr, sort_arr+size);
    return sort_arr;
}

//all required methods
void *findMin(void* arg){
    double res=MAX_NUMBER;
    for(int i=0;i<size;i++){
        if(*((int*)arr+i)<res){
            res = ((int*)arr)[i];
        }
    }
    results[0]=res;
    return NULL;
}

void *findMax(void* arg){
    double res=MIN_NUMBER;
    for(int i=0;i<size;i++){
        if(*((int*)arr+i)>res){
            res = ((int*)arr)[i];
        }
    }
    results[1]=res;
    return NULL;
}

void *range(void* arg){
    double res;
    findMax(arg);
    findMin(arg);
    double min=results[0],max=results[1];
    res= max-min;
    results[2]=res;
    return NULL;
}

void *mode(void* arg){
    std::map<int,int> freq;
    for(int i=0;i<size;i++){
        freq[((int*)arr)[i]]++;
    }
    int mostFreq=0,indFreq=0;
    for(auto keyValue:freq){
        if(keyValue.second>mostFreq){
            indFreq=keyValue.first;
            mostFreq=keyValue.second;
        }
    }
    results[3]=indFreq;
    return NULL;
}

void *median(void* arg){
    void *sort_arr=mySort(arr);
    double res=0;
    if(size%2==1){
        res= ((int*)sort_arr)[size/2];
    }
    else{
        res=(((int*)sort_arr)[size/2]*1.0 + ((int*)sort_arr)[size/2]*1.0)/2;
    }
    results[4]=res;
    return NULL;
}

void *sum(void* arg){
    double res=0;
    for(int i=0;i<size;i++){
        res+=*((int*)arr+i);
    }
    results[5]=res;
    return NULL;
}

void *arithmeticMean(void* arg){
    sum(arg);
    double sum=results[5];
    double res= sum/size;
    results[6]=res;
    return NULL;
}

void *harmonicMean(void* arg){
    double res=0;
    for(int i=0;i<size;i++){
        res += 1.0 / *((int*)arr+i);
    }
    results[7]=res;
    return NULL;
}

void *standardDeviation(void* arg){
    arithmeticMean(arg);
    double mean=results[6];
    double res=0;
    for(int i=0;i<size;i++){
        res += ((*((int*)arr+i) - mean)*(*((int*)arr+i) - mean));
    }
    res=sqrt(res/size);
    results[8]=res;
    return NULL;
}

void *interquartileRange(void* arg){
    void *sort_arr=mySort(arr);

    int lowIdx=size/4;
    int highIdx = size-lowIdx-1;
    int lowQ,highQ;
    if(size%4==0 || size%4==1){
        lowQ=(((int*)sort_arr)[lowIdx]*1.0+((int*)sort_arr)[lowIdx-1]*1.0)/2;
        highQ=(((int*)sort_arr)[highIdx]*1.0+((int*)sort_arr)[highIdx+1]*1.0)/2;
    }
    else {
        lowQ=((int*)sort_arr)[size/4]*1.0;
        highQ=((int*)sort_arr)[highIdx]*1.0;
    }
    double res=highQ-lowQ;
    results[9]=res;
    return NULL;
}

//double methods for half thread
void *minAndInterQuartileRange(void* arg){
    findMin(arg);
    interquartileRange(arg);
    return NULL;
}
void *maxAndStandardDeviation(void* arg){
    findMax(arg);
    standardDeviation(arg);
    return NULL;
}
void *rangeAndHarmonicMean(void* arg){
    range(arg);
    harmonicMean(arg);
    return NULL;
}
void *modeAndArithmeticMean(void* arg){
    mode(arg);
    arithmeticMean(arg);
    return NULL;
}
void *medianAndSum(void* arg){
    median(arg);
    sum(arg);
    return NULL;
}