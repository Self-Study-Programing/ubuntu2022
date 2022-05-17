#include <stdio.h>         // puts()
#include <string.h>        // strlen()
#include <fcntl.h>         // O_WRONLY
#include <unistd.h>        // write(), close()

#define  BUFF_SIZE   1024

int fileRead(){
    char buff[BUFF_SIZE] = {0,};
    int fd;
    int w;
    char filename[255] = "";
    printf("파일이름을 입력하세요: ");
    scanf("%s", filename);
    // fileposition(filename);
    fd = open(filename, O_RDWR);
    if (fd == -1){
        printf("파일 열기에 실패했습니다.\n");
        return 0;
    }
    int num = read(fd, buff, BUFF_SIZE);

    char ch;

    for(int i = 1; i<num; i++)
    {
        ch = buff[i];
        putchar(ch);
    }

    close(fd);
   return 0;
}