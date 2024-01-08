#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>
#define LOOP_CNT 10000
int main() {
    struct stat fileStat;
    int fd;
    struct timeval start, end;
    long long elapsedTime;

    // 打开文件
    fd = open("a.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // 获取调用 fstat() 前的时间
    gettimeofday(&start, NULL);
    for (int i = 0; i < LOOP_CNT; i++) {
    // 调用 fstat() 获取文件信息
        if (fstat(fd, &fileStat) == -1) {
            perror("fstat");
            exit(EXIT_FAILURE);
        }
    }

    // 获取调用 fstat() 后的时间
    gettimeofday(&end, NULL);

    // 计算调用耗时
    elapsedTime = (end.tv_sec - start.tv_sec) * 1000000LL + (end.tv_usec - start.tv_usec);

    // 输出文件信息和调用耗时
    printf("File Size: %ld bytes\n", fileStat.st_size);
    printf("File inode: %ld\n", fileStat.st_ino);
    printf("Time elapsed for fstat() call %d cost %lld microseconds\n",LOOP_CNT, elapsedTime);

    // 关闭文件
    close(fd);

    return 0;
}
