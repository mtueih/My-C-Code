/**
 * @file     book-3-pointers-on-c/chapter-7/7-5-2/main.c
 * @author   mtueih
 * @date     2025-12-02 18:33
 * @brief    用迭代（循环）方法实现斐波那契数列第 n 项的计算。
 */

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

static uintmax_t count = 0;

uintmax_t fibonacci(uintmax_t n);
uintmax_t fibonacci_r(uintmax_t n);

int main(void) {
	uintmax_t n;

	printf("输入 n：");

	scanf("%ju", &n);

	printf("fibonacci( %ju ) = %ju\n", n, fibonacci(n));

	printf("fibonacci_r( %ju ) = %ju\n", n, fibonacci_r(n));
	printf("fibonacci_r 函数一共调用了 %ju 次。\n", count);

	return EXIT_SUCCESS;
}

uintmax_t fibonacci(uintmax_t n) {
	uintmax_t first;
	uintmax_t second;
	uintmax_t temp;

	if (n == 0) {
		return 0;
	}

	for (first = 1, second = 1; n > 2; --n) {
		temp = second;
		second += first;
		first = temp;
	}

	return second;
}

uintmax_t fibonacci_r(uintmax_t n) {
	++count;
	if (n <= 2) {
		return 1;
	} else {
		return fibonacci_r(n - 1) + fibonacci_r(n - 2);
	}
}