#include "main.h"

using namespace std;

int main(int argc,char *argv[]){
    //initialize random seed
    srand(time(NULL));
    //create array with random values
    int size = atoi(argv[1]);
    int arr[size];
    for(int i=0;i<size;i++){
        arr[i] = rand() % (MAX_NUMBER - MIN_NUMBER +1) + MIN_NUMBER;
    }
    
    return 0;
}