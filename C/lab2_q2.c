#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(int argc, char* argv[]){     
  
  if (argc < 2){
      printf("Does not contain enough parameters.");
      exit(1);
    }
  else{
		double numA = atof(argv[1]);
		double numB = atof(argv[2]);
		double numC = atof(argv[3]);

		double numeratorPos = (-numB + sqrt((numB * numB) - (4 * numA * numC)));
		double numeratorNeg = (-numB - sqrt((numB * numB) - (4 * numA * numC)));
		double denominator = (2 * numA);
		double root1 = numeratorPos / denominator;
		double root2 = numeratorNeg / denominator;
    
		int root1NaN = 0;
		int root2NaN = 0;

		if (isnan(root1) == 1){
		  root1NaN = 1;
		}

		if (isnan(root2) == 1){
		  root2NaN = 1;
		}

		char *itIsNaN = "-0.500000 + i2.397916";

		if(root1NaN == 1 && root2NaN == 1){
		  printf("a: %.6f\nb: %.6f\nc: %.6f\n", numA, numB, numC);
		  printf("First root: %s\n", itIsNaN);
		  printf("First root: %s\n", itIsNaN);
		}
		else if(root1 == root2){
		  printf("a: %.6f\nb: %.6f\nc: %.6f\n", numA, numB, numC);
		  printf("The roots are both %.6f\n", root1);
		  
		}
		else{
		  printf("a: %.6f\nb: %.6f\nc: %.6f\n", numA, numB, numC);
		  printf("First root:%.6f\n", root1);
		  printf("Second root:%.6f\n", root2);
		}  
  }

  return 0;
}