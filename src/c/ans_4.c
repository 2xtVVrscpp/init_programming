#include<stdio.h>

int main(void){
  int year;

  scanf("%d", &year);

  if(year%400 == 0){
    printf("uruudishi\n");
  }else if(year%100 == 0){
    printf("hutuu\n");
  }else if(year%4 == 0){
    printf("uruudishi\n");
  }else{
    printf("hutuu\n");
  }

  return 0;
}