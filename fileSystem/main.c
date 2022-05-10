#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"fileAdd.c"

typedef char* String;

int main(){
    String filename = "sdf";
    fileAdd();  
    fileRead(filename);
    return 0;
}