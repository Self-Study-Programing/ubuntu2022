#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

void ter(char *command){
    pid_t pid = fork();
    if(pid == 0)
    {
            execl("/bin/sh","sh","-c",command,NULL);
    }
}