#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "common_threads.h"

void *getAverage(void *arg) {
    printf("%s", "words");
}

void *getMin(void *arg) {
    
}

void *getMax(void *arg) { 
    
}

int main (int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Error more or less than 1 arg\n");
        exit(1);
    }
    
    
    long val = atof(argv[1]);
    pthread_t p1;
    Pthread_create(&p1, NULL, getAverage, argv);
    Pthread_join(p1, NULL);
    
    return 0;
    
    
}
