#include "main.h"
int size;

using namespace std;
using namespace std::chrono;

int main(int argc,char *argv[]){
    //initialize random seed
    srand(time(NULL));
    //create array with random values
    size= atoi(argv[1]);
    int* arr=(int*)malloc(sizeof(int)*size);
    
    for(int i=0;i<size;i++){
        arr[i] = rand() % (MAX_NUMBER - MIN_NUMBER +1) + MIN_NUMBER;
    }
    auto start = high_resolution_clock::now();

    //sort array to find some values easily
    std::sort(arr, arr + size);

    //create 10 thread each 1 runs 1 method
    pthread_t threads[10];
    fp methods[10]={min,max,range,mode,median,sum,arithmeticMean,harmonicMean,standardDeviation,interquartileRange};

    void* results[10];

    for(int i=0;i<10;i++){
        pthread_create(&threads[i],NULL,methods[i],(void*)arr);
    }

    for(int i=0;i<10;i++){
        pthread_join(threads[i],&(results[i]));
    }
    
    for(int i=0;i<10;i++){
        printf("%lf\n",*(double*)(results[i]));
        free(results[i]);
    }
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;

    return 0;
}