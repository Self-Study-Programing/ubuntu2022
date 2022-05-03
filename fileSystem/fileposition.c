#include "fileposition.h"
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
typedef char* String;

void fileposition(String file){
    String ptr = (String)malloc(sizeof(char)*(4+strlen(file)));

    strcpy(ptr, "src/");
 
    char *ptr2 = strtok(file, "/");    //구분자는 콤마(,)입니다.
 
    while (ptr2 != NULL)
    {
        strcpy(ptr[strlen(ptr)], ptr2);     //자른 문자 출력
        ptr2 = strtok(NULL, "/");
    }

    chdir(ptr); 

    // strcpy(file, ptr);

    // printf("file = %s\n", file);
    // printf("ptr = %s\n", ptr);

    // free(ptr);
}