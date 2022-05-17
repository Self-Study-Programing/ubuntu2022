#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"fileAdd.c"
#include"fileRead.c"
#include"removeFile.c"
#include"modify.c"

typedef char* String;

int main(){
    fileAdd();  
    // removeFile();
    fileRead();
    modify();
    fileRead();
    return 0;
}