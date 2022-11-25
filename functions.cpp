#include "main.h"
using namespace std;

void *mySort(void *arr){
    int *sort_arr=(int*)malloc(sizeof(int)*size);
    for(int i=0;i<size;i++){
        sort_arr[i]= *((int*)arr+i);
    }
    sort(sort_arr, sort_arr+size);
    return sort_arr;
}

void *min(void *arr){
    double *min=(double*)malloc(sizeof(double));
    *min = MAX_NUMBER;
    for(int i=0;i<size;i++){
        if(*((int*)arr+i)<*min){
            *min = (double)(((int*)arr)[i]);
        }
    }
    return (void*)min;
}

void *max(void *arr){
    double *max=(double*)malloc(sizeof(double));
    *max = MIN_NUMBER;
    for(int i=0;i<size;i++){
        if(*((int*)arr+i)>*max){
            *max = ((int*)arr)[i];
        }
    }
    return (void*)max;
}

void *range(void *arr){
    double* res;
    res=(double*)malloc(sizeof(double));
    *res= *(double*)max(arr) - *(double*)min(arr);
    return (void*)res;
}

void *mode(void *arr){
    double* res;
    res=(double*)malloc(sizeof(double));
    std::map<int,int> freq;
    for(int i=0;i<size;i++){
        freq[((int*)arr)[i]]++;
    }
    int mostFreq=0,index=0;
    for(auto keyValue:freq){
        if(keyValue.second>mostFreq){
            index=keyValue.first;
            mostFreq=keyValue.second;
        }
    }
    *res=index;
    return (void*)res;

}

void *median(void *arr){
    void *sort_arr=mySort(arr);
    double* res;
    res=(double*)malloc(sizeof(double));
    
    double med=0;
    if(size%2==1){
        med= ((int*)sort_arr)[size/2];
    }
    else{
        med=(((int*)sort_arr)[size/2]*1.0 + ((int*)sort_arr)[size/2]*1.0)/2;
    }

    *res=med;
    return (void*)res;
}

void *sum(void *arr){
    double* res;
    res=(double*)malloc(sizeof(double));

    double sum=0;
    for(int i=0;i<size;i++){
        sum+=*((int*)arr+i);
    }

    *res=sum;  
    return (void*)res;
}

void *arithmeticMean(void *arr){
    double* res;
    res=(double*)malloc(sizeof(double));
    *res= *(double*)sum(arr)/size;
    return (void*)res;
}

void *harmonicMean(void *arr){
    double* res;
    res=(double*)malloc(sizeof(double));

    double sum=0;
    for(int i=0;i<size;i++){
        sum += 1.0 / *((int*)arr+i);
    }

    *res=size/sum;  
    return (void*)res;
}

void *standardDeviation(void *arr){
    double* res;
    res=(double*)malloc(sizeof(double));
    
    double mean = *(double*)arithmeticMean(arr);
    double sum=0;
    for(int i=0;i<size;i++){
        sum += ((*((int*)arr+i) - mean)*(*((int*)arr+i) - mean));
    }
    *res=sqrt(sum/size);
    return (void*)res;
}

void *interquartileRange(void *arr){
    void *sort_arr=mySort(arr);

    double* res;
    res=(double*)malloc(sizeof(double));
    
    int highIdx = 3*((size+1)/4),lowIdx=(size+1)/4;
    *res = ((int*)sort_arr)[highIdx]*1.0 - ((int*)sort_arr)[lowIdx]*1.0;
    return (void*)res;
}

void *minAndInterQuartileRange(void *arr){
    dresults[0][0]=min(arr);
    dresults[0][1]=interquartileRange(arr);
    pthread_exit(0);
}
void *maxAndStandardDeviation(void *arr){
    dresults[1][0]=max(arr);
    dresults[1][1]=standardDeviation(arr);
    pthread_exit(0);
}
void *rangeAndHarmonicMean(void *arr){
    dresults[2][0]=range(arr);
    dresults[2][1]=harmonicMean(arr);
    pthread_exit(0);
}
void *modeAndArithmeticMean(void *arr){
    dresults[3][0]=mode(arr);
    dresults[3][1]=arithmeticMean(arr);
    pthread_exit(0);
}
void *medianAndSum(void *arr){
    dresults[4][0]=median(arr);
    dresults[4][1]=sum(arr);
    pthread_exit(0);
}