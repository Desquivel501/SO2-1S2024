#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

void main(){

    pid_t pid = getpid();
    printf("%d\n", pid);

    int fd = open("file.txt", O_RDWR | O_CREAT, 0777);

    while(1){
        write(fd, "Hello\n", strlen("Hello\n")); 
        sleep(3);
    }
}