#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

void main()
{
  char buff[100];
  char childo[100];
  int fd[2], des, bytes, target;

  pipe(fd);

  if(fork()) {
    
    close(fd[0]);

    
    des = open("input.txt", O_RDONLY);
    bytes = read(des, buff, sizeof(buff));

    
    write(fd[1], buff, bytes);
  } else {
    
    close(fd[1]);

    
    read(fd[0], childo, sizeof(childo));
    close(fd[0]);

   
    printf("\nReceived string is -- %s", childo);
    target = open("copy.txt", O_CREAT |O_WRONLY, 00777);
    write(target, childo, (strlen(childo)-1));
  }
}
