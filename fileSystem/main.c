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
    fileAdd();  
    removeFile();
    fileRead();
    modify();
    fileRead();
    ls();
    makeDir();
    rmDir();
    return 0;
}