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
    // printf("%s\n", file);
    fileposition(filename);
    
    strcpy(file, filename);

    int newfile;
    char authority[4] = {0,};
    printf("권한을 입력해주세요: ");
    scanf("%s", authority);

    newfile = creat(file, strtol(authority, (char**)NULL, 8));

    if(newfile == -1){
        printf("file create fail: %d", -1);
        return 0;
    }

    close(newfile);

    newfile = open(file, O_RDWR, authority);

    printf("내용을 입력해주세요: \n");
    
    while(1){
        char input[1000] = {0,};
        scanf("%[^\n]", input);
        getchar();
        if(input[0] == ':' && input[1] == 'w' && input[2] == 'q'){
            break;
        }
        write(newfile, input, strlen(input));
        write(newfile, "\n", 2);
    }

    printf("success: filename = %s\n", file);

    
    close(newfile);
    free(file);
    return 0;
}