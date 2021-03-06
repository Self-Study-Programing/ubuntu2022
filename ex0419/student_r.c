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
    int fd1;
    fd1 = open("studentdb", O_RDONLY);
    char c = ' ';
    STUDENT student;
    if(fd1 == -1){
        printf("file open fail");
    }
    do{
        printf("몇번째 학번을 검색하시겠습니까?");
        scanf("%d", &student.id);
        lseek(fd1, student.id * sizeof(student), SEEK_SET);
        if(read(fd1, &student, sizeof(student)) > 0 && student.id != 0){
            printf("학번 %d 이름 %s 점수 %d\n", student.id, student.name, student.score);
        }
        printf("계속 하시겠습니까?(Y/N) : ");
        getchar();
        scanf("%c", &c);
    }while(c == 'Y');
} 