#include<stdio.h>

int main(void){
  int height, i, j;

  scanf("%d", &height);

  for (i=0;i<height;i++){
    printf("%d: ", i);

    for(j=0;j<height-i;j++){
      printf(" ");
    }

    for (j=0;j<2*i+1;j++){
      printf("*");
    }
    printf("\n");
  }

  return 0;
}