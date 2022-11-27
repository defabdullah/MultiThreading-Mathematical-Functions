#include "main.h"

int size;
int *arr,*innerIdxPtr;
double results[10];

using namespace std;
using namespace std::chrono;

int main(int argc,char *argv[]){
    //initialize random seed
    srand(time(NULL));

    //get arguments
    size= atoi(argv[1]);
    int threadNumber = atoi(argv[2]);

    //create array with random values
    arr=(int*)malloc(sizeof(int)*size);
    for(int i=0;i<size;i++){
        arr[i] = rand() % (MAX_NUMBER - MIN_NUMBER +1) + MIN_NUMBER;
    }

    //define threads and time objects
    struct timespec start, stop;
    pthread_t threads[threadNumber];
    
    //define methods for 10 thread or 5 thread;
    met methods[10]={findMin,findMax,range,mode,median,sum,arithmeticMean,harmonicMean,standardDeviation,interquartileRange};
    met doubleMethods[5]={minAndInterQuartileRange,maxAndStandardDeviation,rangeAndHarmonicMean,modeAndArithmeticMean,medianAndSum};
    char fileName[20]="output2.txt";

    //start timer
    clock_gettime(CLOCK_REALTIME,&start);
    
    //execute methods according to given thread number
    if(threadNumber==METHOD_NUMBER){
        for(int i=0;i<threadNumber;i++){
            pthread_create(&threads[i],NULL,methods[i],NULL);
        }
        for(int i=0;i<threadNumber;i++){
            pthread_join(threads[i],NULL);
        }
    }
    else if(threadNumber==METHOD_NUMBER/2){
        for(int i=0;i<threadNumber;i++){
            pthread_create(&threads[i],NULL,doubleMethods[i],NULL);
        }
        
        for(int i=0;i<threadNumber;i++){
            pthread_join(threads[i],NULL);
        }
    }
    else{
        sprintf(fileName,"output1.txt");
        for(int i=0;i<METHOD_NUMBER;i++){
            methods[i](NULL);
        }
    }
    //stop timer
    clock_gettime(CLOCK_REALTIME, &stop);
    
    //measure time in miliseconds
    auto duration = ((double)(stop.tv_nsec - start.tv_nsec)) / 1e6 + ((double)(stop.tv_sec - start.tv_sec)) * 1e3;

    //open output file print results and duration then close
    FILE *outputFile=fopen(fileName,"w");
    for(int i=0;i<METHOD_NUMBER;i++){
            fprintf(outputFile,"%.5f\n",results[i]);
    }
    fprintf(outputFile,"%.5f\n",duration);
    fclose(outputFile);
    //free memory
    free(arr);

    return 0;
}