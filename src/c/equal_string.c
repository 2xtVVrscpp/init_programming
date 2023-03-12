#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BUF_SIZE 255
#define SAMPLE_TXT_PATH "./sample.txt"

int main(void){
  char *search;
  char buf[BUF_SIZE];
  unsigned char num, i, j=0;
  FILE *fp;
  bool flag = false;

  scanf("%s", buf);
  num = printf("%s\n", buf);
  printf("num: %d\n", num);

  search = (char *)malloc(sizeof(char)*(num));

  for(i=0;buf[i]!='\0';i++){
    search[i] = buf[i];
  }
  search[i] = '\0';

  if((fp = fopen(SAMPLE_TXT_PATH, "r")) == NULL){
    printf("sample.txt is none.\n");
    return -1;
  }

  printf("searching %s...\n", search);

  for(;fgets(buf, BUF_SIZE, fp) != NULL;){
    printf("searching...\n");
    flag = false;
    for(i=0;buf[i]!='\0';i++){
      if(search[j] == buf[i]){
        j++;
      }else{
        j = 0;
      }

      if(j == num-1){
        flag = true;
        break;
      }
    }

    if(flag){
      printf("find key word.\n");
      printf("%s\n", buf);
    }
  }

  //printf("finish search.\n");

  return 0;
}