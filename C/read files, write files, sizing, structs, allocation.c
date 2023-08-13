#include<stdio.h>
#include<stdlib.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

//https://stackoverflow.com/questions/3536153/c-dynamically-growing-Node
//https://stackoverflow.com/questions/314401/how-to-read-a-line-from-the-console-in-c
//https://stackoverflow.com/questions/230062/whats-the-best-way-to-check-if-a-file-exists-in-c

struct Node{
    char *string;
    struct Node *next;
    struct Node *previous;
};

struct Node* initializeNode(char *element){
    struct Node *c = (struct Node*)malloc(sizeof(struct Node));
    if (c != NULL){
      c->string = element;
      c->next = NULL;
      c->previous = NULL;
    }
    else{
      fprintf(stderr, "Malloc() call failed.\n")
    }

    return c;
}

void append(struct Node **mainHead, char *element) {
    struct Node *newNode = initializeNode(element);
    struct Node *currentNode = (*mainHead); //(*mainHead) is a way to case dereference a **pointer

    if ((*mainHead) == NULL){
        (*mainHead) = newNode;
    } // If head is null
    else{
        while (currentNode->next != NULL){
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }
} // Adds an element to the list.

void reverseList(struct Node **mainHead){
    struct Node *nextNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node *currentNode = (*mainHead);
    struct Node *prevNode = NULL;

    if (currentNode != NULL) {
        while (currentNode != NULL) {
            nextNode = currentNode->next;
            currentNode->next = prevNode;
            prevNode = currentNode;
            currentNode = nextNode;
        } // Gets the last node
        (*mainHead) = prevNode;
    }
}

void printList(struct Node **mainHead){
    if((*mainHead) == NULL){
        printf("Empty List");
    }
    struct Node *currentNode = (*mainHead);
    while(currentNode != NULL){
        printf("%s", currentNode->string);
        currentNode = currentNode->next;
    }
}

bool file_exists (char *filename) {
    struct stat   buffer;
    return (stat (filename, &buffer) == 0);
}

void freeNode(struct Node *a) {
    free(a);
    a = NULL;
}

void convertFileToLinkedList(struct Node **list, FILE *file){
    while(!feof(file)){
      char *line = NULL;
      size_t len = 0;
      ssize_t read = 0;
      read = getline(&line, &len, file);
      if (read == EOF){
          break;
      }
      append(&(*list), line); // dereferences the node ** to a single pointer and then passes by reference that
    }
}

int main(int argc, char* argv[]){

    struct Node *list = NULL; //Must make it null first, allocate later

    if (argc == 3){
        //this will read input from a file then spit it back out to another file
        //strcmp(string1, string2) compares strings. returns -1, 0, or 1. 0 means they are the same.
      if(file_exists(argv[1])){
          if (strcmp(argv[1], argv[2]) != 0){
            FILE *readfile;
            FILE *writefile;
            readfile = fopen(argv[1],"r");
            writefile = fopen(argv[2],"w+");

             convertFileToLinkedList(&list, readfile);
             reverseList(&list);

             struct Node *currentNode = list;
             while(currentNode != NULL){
                 fprintf(writefile, currentNode->string);
                 currentNode = currentNode->next;
             }

            fclose(readfile);
            fclose(writefile);
          } else{
            fprintf(stderr, "Input and output file must differ!\n");
            exit(1);
          }
        }
      else{
          fprintf(stderr, "File does not exist.\n");
          exit(1);
      }


    } // Read in a file and print output to another file
    else if (argc == 2){
        //this code will read in input from a text file aputsnd spit back out in command line

        if(file_exists(argv[1])){
            FILE *textfile;
            textfile = fopen(argv[1],"r");

            convertFileToLinkedList(&list, textfile);

            reverseList(&list);
            printList(&list);


            fclose(textfile);
            free(list);
        }
        else{
            fprintf(stderr, "File does not exist\n");
            exit(1);
        }

        //argv[1]
    } // Read in a file and print out list
    else if (argc == 1){
        //this code will take input and display it back to the user

        puts("Enter List Items:");
        while (1) {
            char *line = NULL;
            size_t len = 0;
            ssize_t read = 0;
            read = getline(&line, &len, stdin);
            if (read == EOF){
                printf("\n");
                break;
            }
            append(&list, line);
        }
        reverseList(&list);
        printList(&list); //TODO: --1-- need to find out why the 2nd item prints out at the end
    } // Prints out the list immediately typed in
    else{

        fprintf(stderr, "usage: reverse <input> <output>\n");
        exit(1);
    } // Sends an error for too many arguments

    return 0;
}
