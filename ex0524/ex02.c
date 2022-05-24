#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include"flock.c"

int main(){
    int fd = open("aaa", O_RDWR);

    struct flock lock;

    lock = f(lock);

    fcntl(fd, F_GETLK, &lock);
    if(lock.l_type == F_WRLCK){
        printf("파일이 락걸려있음");
    }else if(lock.l_type == F_UNLCK){
        printf("파일락이 풀려 있음");
    }

    close(fd);

    return 0;
}