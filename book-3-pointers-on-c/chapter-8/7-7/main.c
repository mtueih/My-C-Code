/**
 * @file     book-3-pointers-on-c/chapter-8/7-7/main.c
 * @author   mtueih
 * @date     2025-12-05 10:34
 * @brief    测试执行时间。
 */

#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TEST_FUNC try1

#define SIZE 10000
#define LOOP 1000000
int x[SIZE];
int y[SIZE];
int i;
int *p1, *p2;

void try1(void) {
	for (i = 0; i < SIZE; i++)
		x[i] = y[i];
}

void try2(void) {
	for (p1 = x, p2 = y; p1 - x < SIZE;)
		*p1++ = *p2++;
}

void try3(void) {
	for (i = 0, p1 = x, p2 = y; i < SIZE; i++)
		*p1++ = *p2++;
}

void try4(void) {
	register int *p1, *p2;
	register int i;

	for (i = 0, p1 = x, p2 = y; i < SIZE; i++)
		*p1++ = *p2++;
}

void try5(void) {
	register int *p1, *p2;

	for (p1 = x, p2 = y; p1 < &x[SIZE];)
		*p1++ = *p2++;
}

int main(void) {
	unsigned i;
	
	struct timespec start, end;

	clock_gettime(CLOCK_MONOTONIC, &start);

	// 👇 被测代码

	for (i = 0; i < LOOP; i++) {
		TEST_FUNC();
	}

	

	clock_gettime(CLOCK_MONOTONIC, &end);

	double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

	printf("已用时间：%.6f 秒\n", elapsed);

	return EXIT_SUCCESS;
}
