#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <fcntl.h>
#include <stdint.h>

#define LOOP_CNT 10000
int main() {
    int fd = open("read.txt", O_RDONLY | O_CREAT, 0644);
    struct timeval start_time;
    struct timeval end_time;
    uint8_t buf[1024] = {0};

    gettimeofday(&start_time, NULL);
    for (int i = 0; i < LOOP_CNT; i++) {
        read(fd, buf, 1);
    }
    gettimeofday(&end_time, NULL);

    long cost = (end_time.tv_sec - start_time.tv_sec) * 1000000 + end_time.tv_usec - start_time.tv_usec;
    // printf("buf[0] = %c\n", buf[0]);
    printf("read %d cost %ld us\n", LOOP_CNT, cost);
    return 0;
}