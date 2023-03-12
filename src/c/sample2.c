#include<stdio.h>

int main(void){
  char *sample = "string";
  printf("%s", sample);

  sample[1] = 'a';
  printf("%s", sample);

  return 0;
}