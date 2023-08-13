#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "common_threads.h"

// Cole Lamers CS452

int size = 0;

void *getAvg(void *argv) {
    
    int* arrayInts = (int*) argv; // converts void* to int array
    int sizeOfArray = size; // makes a local size in this scope
    int total = 0;
    
    for (int i = 0; i < sizeOfArray; i++){
        total += arrayInts[i];
    }
    printf("The average value: %d\n", (total / size));
    
    return NULL;
}

void *getMin(void *argv) {

    int* arrayInts = (int*) argv; // converts void* to int array
    int sizeOfArray = size; // makes a local size in this scope
    int total = 0;
    int min = arrayInts[0]; //sets first instance as value
    
    for (int i = 0; i < sizeOfArray; i++){
        if (arrayInts[i] < min){
            min = arrayInts[i];
        }        
    }
    printf("The minimum value: %d\n", min);
    
    return NULL;
}

void *getMax(void *argv) {
    int* arrayInts = (int*) argv; // converts void* to int array
    int sizeOfArray = size; // makes a local size in this scope
    int total = 0;
    int max = arrayInts[0]; //sets first instance as value
    
    for (int i = 0; i < sizeOfArray; i++){
        if (arrayInts[i] > max){
            max = arrayInts[i];
        }        
    }
    printf("The maximum value: %d\n", max);
    
    return NULL;

}

int main (int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Error more or less than 1 arg\n");
        exit(1);
    }
    
    size = argc - 1; // global size of args less arg[0]

    pthread_t thread1, thread2, thread3;
    int num = argc - 1; // I think doing this arithmetic in my declaration was causing an issue
    int allArgs[num];
    
    for (int i = 1; i < argc; i++){
        allArgs[i-1] = atoi(argv[i]);
    } // converts the args to an int array
    
    Pthread_create(&thread1, NULL, getMax, (void*) allArgs);

    Pthread_create(&thread2, NULL, getMin, (void*) allArgs);
    Pthread_create(&thread3, NULL, getAvg, (void*) allArgs);
    
    Pthread_join(thread1, NULL);
    Pthread_join(thread2, NULL);
    Pthread_join(thread3, NULL);


    return 0;
}
