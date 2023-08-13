#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  
  if (argc < 2){
	printf("Does not contain enough parameters.");
	exit(1);
  }
  else{
	double toSquare = atof(argv[1]);
	double guess = atof(argv[2]);
  
	double func = 0;
	double updatedGuess = guess;

	int iter = 0;
	while (iter < 5){
		func = (updatedGuess - (((updatedGuess * updatedGuess) - toSquare)/(2 * updatedGuess)));
		updatedGuess = func;
		iter++;
	} // Newtons method
 
	  printf("Your initial guess is: %.2f\n", guess);
	  printf("Your input number to be square rooted: %.0f\n", toSquare);
	  printf("The approximate square root is: %.5f", updatedGuess);
  }

  return 0; 
}