#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 128

enum STATUS{
  success,
  open_error,
  create_error,
  read_error,
  write_error,
  close_error
};

int main(void){
  int ret = success;
  int fd;
  char* filename = "./how_to_fd.txt";
  char buf[BUF_SIZE];

  do{
    memset(buf, 0, sizeof(char)*BUF_SIZE);

    if((fd = open(filename, O_RDWR)) < 0){
      printf("open error\n");
      printf("try to create a file\n");

      if((fd = creat(filename, 0755)) < 0){
        printf("create error\n");
        ret = create_error;
        break;
      }

      if((fd = open(filename, O_RDWR)) < 0){
        printf("open error\n");
        ret = open_error;
        break;
      }
    }

    // move a pointer to end of file
    lseek(fd, 0L, 2);
    if((ret = (write(fd, "hello world\n", 12))) < 0){
      printf("write error\n");
      ret = write_error;
      break;
    }

    // move a pointer to start of file
    lseek(fd, 0L, 0);
    if((ret = read(fd, buf, 12)) < 0){
      printf("read error\n");
      ret = read_error;
      break;
    }

    ret = success;
    printf("buf: %s", buf);
  }while(0);

  return 0;
}