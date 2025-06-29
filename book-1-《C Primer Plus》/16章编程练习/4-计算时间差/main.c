#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <math.h>

void testFunction(void);

int main(void) {
    clock_t start_time, end_time;

    start_time = clock();

    testFunction();

    end_time = clock();

    printf("测试函数运行总共用了 %f 秒\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);

    return 0;
}

void testFunction(void) {
    register size_t i;

    for (i = 0; i < 1000000; ++i) {
        printf("\r%zu", i);
        fflush(stdout);
    }
    putchar('\n');
}
