#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include "fileMethod.h"
#include "fileposition.h"
typedef char* String;

int fileAdd(){

    char filename[255] = {0,};
    printf("파일의 이름을 입력하세요: ");
    scanf("%s", filename);

    if(strchr(filename, '\\') || strchr(filename, ':') || strchr(filename, '*') || strchr(filename, '?') || strchr(filename, '\"') || strchr(filename, '<') || strchr(filename, '>') || strchr(filename, '|')){
        printf("사용할 수 없는 문자가 존재 합니다.\n");
        return 0;
    }

    String file = (String)malloc(sizeof(char)*(4+strlen(filename)));
    strcpy(file, filename);
    fileposition(file);

    int newfile;
    newfile = creat(file, O_RDWR);

    if(newfile == -1){
        printf("file open fail");
    }

    printf("file create success");
    printf("filename = %s", file);

    free(file);
    return 0;
}