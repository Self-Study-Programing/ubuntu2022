#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int terminal(char *command){
   int child_status;
    pid_t pid = fork();

    if(pid == 0)
    {
            execl("/bin/sh","sh","-c",command,(char *) 0);
    }
    else if(pid == -1)
    {
            perror("fork");
            exit(0);
    }
    else
    {
            wait(&child_status);
            return child_status;
    }
}