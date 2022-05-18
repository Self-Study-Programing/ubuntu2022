#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>

void makeDir(){
    printf("디렉토리 이름을 입력하세요: ");
    char filename[255] = "";

    scanf("%s", filename);

    mkdir(filename, 0755);
}

void rmDir(){
    printf("디렉토리 이름을 입력하세요: ");
    char filename[255] = "";

    scanf("%s", filename);

    rmdir(filename);
}