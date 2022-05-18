#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"fileAdd.c"
#include"fileRead.c"
#include"removeFile.c"
#include"modify.c"
#include"ls.c"
#include"dir.c"

typedef char* String;

int main(){
    char str[5] = "";

    system("clear");
    
    while(1){
        *str = "";
        printf("fileSystem ~ %% ");
        scanf("%s", str);


        if(strstr(str, "makefile") != NULL){
            fileAdd();
        }else if(strstr(str, "removefile") != NULL){
            removeFile();
        }else if(strstr(str, "readfile") != NULL){
            fileRead();
        }else if(strstr(str, "modify") != NULL){
            modify();
        }else if(strstr(str, "readDir") != NULL){
            ls();
        }else if(strstr(str, "makeDir") != NULL){
            makeDir();
        }else if(strstr(str, "removeDir") != NULL){
            rmDir();
        }else if(strstr(str, "end") != NULL){
            printf("종료");
            return 0;
        }else{
            printf("not an identifier: %s\n", str); 
        }
    }
    return 0;
}