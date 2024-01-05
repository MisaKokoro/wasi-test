#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <fcntl.h>
#include <stdint.h>

#define LOOP_CNT 1000
int main() {
    struct timeval start_time;
    struct timeval end_time;
    uint8_t buf[1024] = {0};

    gettimeofday(&start_time, NULL);
    for (int i = 0; i < LOOP_CNT; i++) {
        int fd = open("a.txt", O_WRONLY | O_CREAT, 0644);
        close(fd);
    }
    gettimeofday(&end_time, NULL);

    long cost = (end_time.tv_sec - start_time.tv_sec) * 1000000 + end_time.tv_usec - start_time.tv_usec;
    printf("open_close %d cost %ld us\n", LOOP_CNT, cost);
    return 0;
}