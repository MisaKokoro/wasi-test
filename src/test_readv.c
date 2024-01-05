#include <stdio.h>
#include <stdlib.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>
#define LOOP_CNT 10000

int main() {
    int fd;
    struct iovec iov[1];
    ssize_t numRead;
    char buf1[1];

    // 打开文件
    fd = open("read.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // 设置两个缓冲区
    iov[0].iov_base = buf1;
    iov[0].iov_len = sizeof(buf1);

    // 从文件中读取数据到多个缓冲区
    struct timeval start_time;
    struct timeval end_time;

    gettimeofday(&start_time, NULL);
    for (int i = 0; i < LOOP_CNT; i++) {
        numRead = readv(fd, iov, 1);
        if (numRead == -1) {
            perror("readv");
            exit(EXIT_FAILURE);
        }
    }
    gettimeofday(&end_time, NULL);
    long cost = (end_time.tv_sec - start_time.tv_sec) * 1000000 + end_time.tv_usec - start_time.tv_usec;


    // 输出读取的数据
    // printf("Read %ld bytes\n", (long)numRead);
    printf("readv %d cost %ld us\n", LOOP_CNT, cost);
    // if (numRead > 0) {
    //     printf("Contents of buf1: %s\n", buf1);
    // }

    // 关闭文件
    close(fd);

    return 0;
}
