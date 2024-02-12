#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>  
#include <pthread.h> 

int main (int argc, char *argv[]) {

    char command[100];

    printf("%s\n", argv[0]);

    int pid1, pid2;
    pid1 = atoi(argv[1]);
    pid2 = atoi(argv[2]);

    sprintf(command, "%s %d %d %s", "sudo stap trace.stp ", pid1, pid2, " > calls.log");
    system(command);

   return 0;
} 