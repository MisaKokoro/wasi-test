#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <fcntl.h>
#define LOOP_CNT 10000
int main() {
    int fd = open("write.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    struct timeval start_time;
    struct timeval end_time;

    gettimeofday(&start_time, NULL);
    for (int i = 0; i < LOOP_CNT; i++) {
        write(fd, "a", 1);
    }
    gettimeofday(&end_time, NULL);

    long cost = (end_time.tv_sec - start_time.tv_sec) * 1000000 + end_time.tv_usec - start_time.tv_usec;
    printf("write %d cost %ld us\n", LOOP_CNT, cost);
    return 0;
}