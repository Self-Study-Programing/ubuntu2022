#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void env(char* option){
    char **ptr;
    extern char **environ;
    char* p;

    if(option == NULL){
        for(ptr = environ; *ptr != 0; ptr++){
            printf("%s \n", *ptr);
        }
        return;
    }

    p = getenv(option);
    if(p == NULL){
        printf("없는 환경변수: %s\n", option);
        return;
    }

    printf("%s=%s \n", option,p);
}