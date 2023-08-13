#include<stdio.h>
#include<stdlib.h>

//https://stackoverflow.com/questions/3536153/c-dynamically-growing-Node
//https://stackoverflow.com/questions/314401/how-to-read-a-line-from-the-console-in-c


struct Node{
    char *string;
    struct Node *next;
    struct Node *previous;
};

struct Node* initializeNode(char *element){
  struct Node *c = (struct Node*)malloc(sizeof(struct Node));
  c->string = element;
  c->next = NULL;
  c->previous = NULL;
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
    printf("%s\n", currentNode->string);
    currentNode = currentNode->next;
  }
}

void freeNode(struct Node *a) {
    free(a);
    a = NULL;
}

int main(int argc, char* argv[]){

    if (argc == 3){
        //this will read input from a file then spit it back out to another file
    }
    else if (argc == 2){
        //this code will read in input from a text file and spit back out in command line
        //argv[1]
    }
    else if (argc == 1){
        //this code will take input and display it back to the user
        struct Node *list = NULL; //Must make it null first, allocate later

        char *line = NULL;
        size_t len = 0;
        ssize_t read = 0;

        puts("Enter List Items:\n");
        while (1) {
            read = getline(&line, &len, stdin);
            if (read == "EOF"){
              break;
            }
            append(&list, line);
        }

        reverseList(&list);

        //free(line);

        if (list->string == NULL){
          fprintf(stderr, "head is null.");
        }

        printf("%s\n", list->next->string); //TODO: --1-- segfaults if the string contains nothing. error check for this.

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



/*

*/
