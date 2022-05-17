#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

void removeFile() {
    char filename[255] = {0,};
    printf("파일의 이름을 입력하세요: ");
    scanf("%s", filename);

    int a = remove(filename);
    if(a == 0){
        printf("파일이 제거되었습니다.\n");
    }else{
        printf("없는 파일입니다.\n");
    }
}