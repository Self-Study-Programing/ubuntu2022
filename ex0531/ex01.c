#include <stdio.h>
#include <stdlib.h>

void atexit_handler1(){
    printf("atexit_handler1 함수 호출합니다.");
}
void atexit_handler2(){
    printf("atexit_handler2 함수 호출합니다.");
}

int main(){
    atexit(atexit_handler1);
    atexit(atexit_handler2);
    exit(0);
}