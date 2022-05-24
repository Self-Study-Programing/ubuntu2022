#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int fd;
    fd = open("aaa", O_RDWR);
    struct flock lock;

    if(fd < 0){
        printf("파일 열기 실패");
    }

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 100;
    fcntl(fd, F_SETLKW, &lock);
    if(lock.l_type == F_WRLCK){
        printf("잠금되어있음\n");
        sleep(20); // 20s동안 멈춤
    }
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLKW, &lock);
    printf("잠금해제됨\n");

    close(fd);
    return 0;
}