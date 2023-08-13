#include<stdio.h>

int main(int argc, char *argv[]){
  
  char data[100];
  fgets(data, 100, stdin); // gets the string
  
  int size = 0;
  while (data[size] != '\0'){
    size++;
  } // gets the actual string size entered

  char actual[size];
  int n=0;
    for ( int i = size - 1; i >= 0; i--){
    actual[n] = data[i];
    n++;
    if (n == size){
      actual[n] = '\0';
      break;
    } // nulls the tail of the string
  } // builds the string backwards
  
  printf("You entered: %s\n", data);
  printf("The reversed string is: %s", actual);

  return 0;
}
