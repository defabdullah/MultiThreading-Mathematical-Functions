#include "functions.h"


int min(int arr[]){
    int size = sizeof(arr)/sizeof(int);
    return *std::min_element(arr, arr + size);
}

int max(int arr[]){
    int size = sizeof(arr)/sizeof(int);
    return *std::max_element(arr, arr + size);
}

int range(int arr[]){
    return max(arr)-min(arr);
}

int mode(int arr[]){
    return 0;
}

int median(int arr[]){
    
    return 0;
}

int sum(int arr[]){
    
    return 0;
}

int arithmeticMean(int arr[]){
    
    return 0;
}

int harmonicMean(int arr[]){
    
    return 0;
}

int standardDeviation(int arr[]){
    
    return 0;
}

int interquartileRange(int arr[]){
    
    return 0;
}
