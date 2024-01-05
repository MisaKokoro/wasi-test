#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <fcntl.h>
#include <stdint.h>
#include <sys/stat.h>

#define LOOP_CNT 10000
int main() {
    struct timeval start_time;
    struct timeval end_time;
    uint8_t buf[1024] = {0};

    gettimeofday(&start_time, NULL);
    for (int i = 0; i < LOOP_CNT; i++) {
        const char* filename = "a.txt"; // 文件名
        struct stat fileStat; // 创建一个结构体来存储文件状态信息

        // 使用 stat 函数获取文件状态信息
        if(stat(filename, &fileStat) == -1) {
            perror("Error"); // 如果发生错误，输出错误信息
            return -1;
        }
    }
    gettimeofday(&end_time, NULL);

    long cost = (end_time.tv_sec - start_time.tv_sec) * 1000000 + end_time.tv_usec - start_time.tv_usec;
    printf("stat %d cost %ld us\n", LOOP_CNT, cost);
    return 0;
}