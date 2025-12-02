/**
 * @file     book-3-pointers-on-c/chapter-7/7-6-1/main.c
 * @author   mtueih
 * @date     2025-12-02 20:06
 * @brief    可变参数列表。
 */

#include <inttypes.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

intmax_t sum(size_t n_values, ...);

int main(void) {

	printf("%jd\n", sum(5, 13, 14, 1, 6, 7));

	return EXIT_SUCCESS;
}

intmax_t sum(size_t n_values, ...) {
	va_list args;
	register size_t i;
	intmax_t sum;

	va_start(args, n_values);

	for (i = 0, sum = 0; i < n_values; ++i) {
		sum += va_arg(args, int);
	}

	va_end(args);

	return sum;
}