#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

struct Student
{
    char name[20];
    int id;
    int score;
};

int main(){
    int fd1;
    open("studentdb", O_WRONLY|O_CREAT|O_EXCL);
    printf("학번 이름 점수 입력하세요 ");

    struct Student student;
    
    while(scanf("%d %s %d", &student.id, student.name, &student.score) == 3)
        write(fd1, &student, sizeof(student));
}