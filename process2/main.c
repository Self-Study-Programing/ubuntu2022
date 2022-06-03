#include <stdio.h>
#include <string.h>
#include "env.c"
#include "upper.c"
#include <sys/types.h>
#include <unistd.h>

int main(){
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
        }
        if(strstr(operator, "ps") != NULL){
            int a = getppid( );
            printf("%d\n", a);
        }
    }

    return 0;
}