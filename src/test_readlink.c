#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#define LOOP_CNT 10000

int main() {
    char buffer[1024]; // 用于存储符号链接目标路径的缓冲区
    ssize_t linkSize;   // 存储读取到的符号链接大小

    struct timeval start_time;
    struct timeval end_time;

    gettimeofday(&start_time, NULL);
    for (int i = 0; i < LOOP_CNT; i++) {
        // 读取符号链接目标路径
        linkSize = readlink("a.symbol", buffer, sizeof(buffer) - 1);
        if (linkSize == -1) {
            perror("readlink");
            exit(EXIT_FAILURE);
        }
    }
    gettimeofday(&end_time, NULL);
    long cost = (end_time.tv_sec - start_time.tv_sec) * 1000000 + end_time.tv_usec - start_time.tv_usec;
    printf("readlink %d cost %ld us\n", LOOP_CNT, cost);


    // // 添加字符串结束符
    // buffer[linkSize] = '\0';

    // // 输出符号链接目标路径
    // printf("Symbolic link points to: %s\n", buffer);

    return 0;
}
