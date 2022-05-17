#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"fileAdd.c"
#include"fileRead.c"
#include"removeFile.c"

typedef char* String;

int main(){
    String filename = "sdf";
    fileAdd();  
    removeFile();
    fileRead(filename);
    return 0;
}