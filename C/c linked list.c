#include<stdio.h>
#include<stdlib.h>

//https://stackoverflow.com/questions/3536153/c-dynamically-growing-Vector
//https://stackoverflow.com/questions/314401/how-to-read-a-line-from-the-console-in-c

struct Vector{
    char *index;
    struct Vector *next;
    size_t used;
    size_t size;
};

void initVector(struct Vector *a, size_t initialSize) {
    //TODO: --1-- i can likely just ditch the initial size thing. not really needed
   // a = malloc(initialSize * sizeof(struct Vector)); //TODO: --1-- this i am just trying. i don't know how to do this because my free function is not working
    a->index = malloc(initialSize * sizeof(char));
    a->next = malloc(sizeof(struct Vector));
    a->used = 0;
    a->size = initialSize;
}

void insertVector(struct Vector *a, char *element) {
    if (a->used == a->size) {
        a->size *= 2;
        a = realloc(a, a->size * sizeof(struct Vector));
    }
    a->used++;
    a->index = element;
} // Adds an element to the index. If the allocated size is at the cap, it reallocates the current amount multiplied by two

void freeVector(struct Vector *a) {
    free(a);
    a = NULL;
    a->used = a->size = 0;
}

int main(int argc, char* argv[]){     
    
    if (argc == 3){
        //this will read input from a file then spit it back out to another file
    }
    else if (argc == 1){
        //this code will read in input from a text file and spit back out in command line	
        //argv[1]
    }
    else if (argc == 2){
        //this code will take input and display it back to the user
        struct Vector a;
        a = malloc(sizeof(struct Vector));
        char *st = argv[1];
        
        initVector(&a, 5);  // initially 5 elements
        insertVector(&a, st);
        
        printf("%s\n", a.index);
        
        freeVector(&a); //TODO: --1-- segfaults here
        
        
        char *line = NULL;
        size_t len = 0;
        ssize_t read = 0;
        while (1) {
            puts("enter a line");
            read = getline(&line, &len, stdin);
            if (read == -1)
                break;
            printf("line = %s", line);
            printf("line length = %zu\n", read);
            puts("");
        }
        free(line);
        
        
    }
    else{
        /*
         * 
         * This is basically if there is an error or something or too many arguments
         * stderr
         * fprintf(stderr...
         * end
         * exit(1);
         */
    }
    
    return 0;
}
