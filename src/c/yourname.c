#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define BUF_SIZE 255

//#define DEBUG
#ifdef DEBUG
# define DEBUG_PUTS(str) puts(str)
#define DEBUG_PRINTF(fmt, ...)  printf(fmt, ## __VA_ARGS__)
#else
# define DEBUG_PUTS(str)
#define DEBUG_PRINTF(fmt, ...)
#endif

int main(void){
  char buf[BUF_SIZE];
  char *search;
  char my_name_is[] = "masayuki-gondo";
  int num, i;

  printf("your name ?\n");
  scanf("%s", buf);

  printf("input: ");
  num = printf("%s\n", buf);
  search = (char *)malloc(sizeof(char)*num);

  for(i=0;buf[i]!='\0';i++){
    search[i] = buf[i];
  }

  DEBUG_PRINTF("your input: %s\n", search);

  for(i=0;(search[i]!='\0')&&(my_name_is[i] != '\0');i++){
    if(search[i]!=my_name_is[i]){
      break;
    }
  }

  if(search[i]==my_name_is[i] && my_name_is[i]=='\0'){
    printf("output: OK\n");
  }else{
    printf("output: NG\n");
  }

  return 0;
}