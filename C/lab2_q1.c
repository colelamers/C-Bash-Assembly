#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]){
  
  if (argc < 2){
    printf("Usage ./temperature_conversion temp_in_F\n");
    exit(1);
  }else{
    double temp_in_F = atof(argv[1]);
    double temp_in_C = (temp_in_F - 32)*5/9;
    printf("Temperature in Fahernheit is: %.2f\n", temp_in_F);
    printf("Temperature in Celsius is: %.2f\n", temp_in_C);
  }

  // Add your code here 
  return 0;
  
}