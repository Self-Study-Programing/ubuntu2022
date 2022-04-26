#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

typedef struct 
{
    char name[24];
    int id;
    int score;
} STUDENT;

int main(){
    int fd;
    fd = open("studentdb", O_RDWR);
    
    if(fd == -1){
        printf("file open fail");
    }

    close(fd);
    return 0;
}