#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

using namespace std;

enum ERR_STATUS{
  success,
  failed
};

struct fd_structure{
  int fd_in;
  int fd_out;
};

enum ERR_STATUS fd_open(char* filename, struct fd_structure *fd){
  enum ERR_STATUS ret = success;
  
  do{
    fd->fd_in = open(filename, O_RDONLY);
    if (fd->fd_in < 0) {
     ret = failed;
     printf("open() failed.");
     break;
    }

    fd->fd_out = open(filename, O_WRONLY);
    if (fd->fd_out < 0) {
      ret = failed;
      close(fd->fd_in);
      printf("open() failed.");
      break;
    }
  }while(0);

  if(ret == success){
    printf("stdin: %d, stdout: %d\n", fd->fd_in, fd->fd_out);
  }

  return ret;
}

enum ERR_STATUS fd_close(struct fd_structure *fd){
  enum ERR_STATUS status = success;

  close(fd->fd_in);
  close(fd->fd_out);

  return status;
}

int main(void){
  struct fd_structure fd_sample;
  int backup_in, backup_out;
  char* filename = "./sample.txt";
  char buf_char[1024];
  enum ERR_STATUS ret=success;

  memset(buf_char, 0, sizeof(char)*1024);

  ret = fd_open(filename, &fd_sample);
  if(ret != success){
    printf("open error\n");
    return ret;
  }

  backup_in = dup(STDIN_FILENO);
  backup_out = dup(STDOUT_FILENO);

  if(dup2(fd_sample.fd_in, STDIN_FILENO) == -1){
    printf("dup2 stdin error");
    return 1;
  }

  if(dup2(fd_sample.fd_out, STDOUT_FILENO) == -1){
    printf("dup2 stdout error");
    return 1;
  }

  int size = printf("Hello world\n");
  printf("size: %d\n", size);

  dup2(backup_in, STDIN_FILENO);
  dup2(backup_out, STDOUT_FILENO);

  ssize_t read_status = read(fd_sample.fd_in, buf_char, sizeof(buf_char));
  if(read_status < 0){
    printf("read error\n");
    return 0;
  }
  printf("buf: %s", buf_char);

  return 0;
}