#include<stdio.h>
#include <stdbool.h>

int main(void){
  int count, i;
  bool flag = true;

  scanf("%d", &count);

  for (i = 0; i < count; i++)
  {
    if((i+1)%15 == 0){
      printf("FizzBuzz\n");
    }else if((i+1)%5 == 0){
      printf("Buzz\n");
    }else if((i+1)%3 == 0){
      printf("Fizz\n");
    }else{
      printf("%d\n", i+1);
    }
/*
    flag = true;
    if((i+1)%3==0){
      printf("Fizz");
      flag = false;
    }
    if((i+1)%5==0){
      printf("Buzz");
      flag = false;
    }
    if(flag){
      printf("%d", i+1);
    }
    printf("\n");
*/
  }

  return 0;
}
