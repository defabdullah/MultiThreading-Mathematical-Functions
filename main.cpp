#include "main.h"
int size;
void** dresults[5];

using namespace std;
using namespace std::chrono;

int main(int argc,char *argv[]){
    //initialize random seed
    srand(time(NULL));
    //create array with random values
    size= atoi(argv[1]);
    int threadNumber = atoi(argv[2]);
    int* arr=(int*)malloc(sizeof(int)*size);
    bool doubleThread=threadNumber==METHOD_NUMBER/2;
    for(int i=0;i<size;i++){
        arr[i] = rand() % (MAX_NUMBER - MIN_NUMBER +1) + MIN_NUMBER;
    }
    auto start = high_resolution_clock::now();

    pthread_t threads[threadNumber];

    met methods[10]={min,max,range,mode,median,sum,arithmeticMean,harmonicMean,standardDeviation,interquartileRange};
    met doubleMethods[5]={minAndInterQuartileRange,maxAndStandardDeviation,rangeAndHarmonicMean,modeAndArithmeticMean,medianAndSum};
    void* results[METHOD_NUMBER];

    if(threadNumber==METHOD_NUMBER){
        for(int i=0;i<threadNumber;i++){
            pthread_create(&threads[i],NULL,methods[i],(void*)arr);
        }

        for(int i=0;i<threadNumber;i++){
            pthread_join(threads[i],&(results[i]));
        }
    }

    else if(doubleThread){
        
        for(int i=0;i<threadNumber;i++){
            dresults[i]=(void**)malloc(sizeof(void*)*2);
            for(int j=0;j<2;j++){
                dresults[i][j]=malloc(sizeof(void*));
            }
        }

        for(int i=0;i<threadNumber;i++){
            pthread_create(&threads[i],NULL,doubleMethods[i],(void*)arr);
        }
        
        for(int i=0;i<threadNumber;i++){
            pthread_join(threads[i],NULL);
        }
        
        for(int i=0;i<threadNumber;i++){
            results[i]=dresults[i][0];
            results[METHOD_NUMBER-i-1]=dresults[i][1];
        }
        
    }

    else{
        for(int i=0;i<METHOD_NUMBER;i++){
            results[i]=methods[i](arr);
        }
    }
    
    FILE *outputFile=fopen("output1.txt","w");
    
    for(int i=0;i<METHOD_NUMBER;i++){
            fprintf(outputFile,"%f\n",*(double*)results[i]);
    }
    
    if(doubleThread){
        for(int i=0;i<threadNumber;i++){
            for(int j=0;j<2;j++){
                free(dresults[i][j]);
            }
            free(dresults[i]);
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;
    
    return 0;
}