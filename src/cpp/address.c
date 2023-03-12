#include<stdio.h>
#include<stdlib.h>

int ave(int *num1, int num2);

int main(void){
  char *address_char;
  int num = 15;
  int *address_int;
  void *funcp;
  
  double *address_double;
  int array[8];
  int num1 = 1, num2 = 4;

  char* str1 = "aaaJapanbb";
  char str2;

  address_int = (int *)malloc(sizeof(int));
  *address_int = 10;
  printf("int: %d\n", *address_int);

  str2 = (char*)malloc(sizeof(char)*5);
  strncpy(str2, str1+3, 5);

  // printf("char address: %lx\n", sizeof(*address_char));
  // printf("int address: %lx\n", sizeof(*address_int));
  // printf("num address: %lx\n", sizeof(num));
  // printf("double address: %lx\n", sizeof(*address_double));

  printf("num1: %d, num2: %d\n", num1, num2);
  ave(&num1, num2);
  printf("num1: %d, num2: %d\n", num1, num2);


  return 0;
}

int ave(int *num1, int num2){
  double average;

  average = (*num1+num2)/2;
  num1 = &num2;
  num2 = 20;

  printf("num1: %d, num2: %d\n", *num1, num2);

  return average;
}

int function2(void){

  return 0;
}