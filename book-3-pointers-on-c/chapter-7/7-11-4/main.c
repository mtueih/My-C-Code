/**
 * @file     book-3-pointers-on-c/chapter-7/7-11-4/main.c
 * @author   mtueih
 * @date     2025-12-02 21:53
 * @brief    计算任意数量的整数的最大值。
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int max(int n, ...);

int main(void) {

    printf("%d\n", max(1, 2, 3, 4, 15, 6, 7, 14, 19, -1));

    return EXIT_SUCCESS;
}

int max(int n, ...) {
	va_list args;
	int max;
	int temp;

	va_start(args, n);

	for(max = n;;) {
		temp = va_arg(args, int);
		if (temp > max) {
			max = temp;
		}
		
		if (temp < 0) {
			break;
		}
	}

	va_end(args);

	return max;
}