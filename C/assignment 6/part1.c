#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "common_threads.h"

void *mythread(void *arg) { 
    for(int i = 2; i < (long)arg; i++){
        bool isItPrime = true;
        for(int j = 2; j < i ; j++){
            
            if(i % j == 0){
                isItPrime = false;
                break;
            }
        }
        if(isItPrime)
            printf("%d ", i);
    }
    printf("\n");
    return NULL;
} // what the thread does

int main (int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Error more or less than 1 arg\n");
        exit(1);
    }
    
    long val = atof(argv[1]);
    pthread_t p1;
    Pthread_create(&p1, NULL, mythread, (void *) (long long) val);
    Pthread_join(p1, NULL);
    
    return 0;
    
    
}
