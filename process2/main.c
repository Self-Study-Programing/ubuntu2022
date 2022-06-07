#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include "env.c"
#include "upper.c"
#include "terminal.c"

void doA(){
    printf("doA function\n");
}

void doB(){
    printf("doB function\n");
}

int main(){
    atexit(doA);
    atexit(doB);

    char operator[100] = {0,};

    system("clear");

    while(1){
        *operator = "";
        printf("process ~ %% ");

        scanf("%[^\n]", operator);
        getchar();

        if(strstr(operator, "env") != NULL){
            char* ptr = strtok(operator, " ");
            ptr = strtok(NULL, " ");

            if(ptr != NULL){
                strupr(ptr);
            }

            env(ptr);
        }else if(strstr(operator, "exit") != NULL){
            printf("종료\n");
            exit(0);
        }else {
            int status = terminal(operator);
        }
    }

    return 0;
}