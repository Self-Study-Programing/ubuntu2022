#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include "k.c"

void doA(){
    printf("doA\n");
}

void doB(){
    printf("doB\n");
}

int main(){
    atexit(doA);
    atexit(doB);

    char operator[100] = {0,};

    while(1){
        *operator = "";
        scanf("%[^\n]", operator);
        getchar();
        if(strstr(operator, "exit") != NULL){
            exit(0);
        }else {
            ter(operator);
        }
    }
}