#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

void modify(){
    char filename[255] = "";
    printf("파일이름을 입력하세요: ");
    scanf("%s", filename);
    int fd;

    printf("덮어 쓰시겠습니까 ? (Y/N) ");
    getchar();
    char A = getchar();

    if(A == 'Y'){
        fd = open(filename, O_WRONLY | O_TRUNC);
    }else if(A == 'N'){
        fd = open(filename, O_WRONLY | O_APPEND);
        lseek(fd, -2, SEEK_END);
    }
    printf("입력해주세요: \n");
    getchar();
    while(1){
        char input[1000] = {0,};
        scanf("%[^\n]", input);
        getchar();
        if(input[0] == ':' && input[1] == 'w' && input[2] == 'q'){
            break;
        }
        write(fd, input, strlen(input));
        write(fd, "\n", 2);
    }
    close(fd);
}