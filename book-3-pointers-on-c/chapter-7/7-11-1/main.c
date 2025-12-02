/**
 * @file     book-3-pointers-on-c/chapter-7/7-11-1/main.c
 * @author   mtueih
 * @date     2025-12-02 21:19
 * @brief    厄密多项式，递归实现。
 */

#include <stdio.h>
#include <stdlib.h>

int hermite(int n, int x);

int main(void) {
	int n, x;

	printf("输入 n，x：");

	scanf("%d %d", &n, &x);

	printf("hermite(%d, %d) = %d\n", n, x, hermite(n, x));

	return EXIT_SUCCESS;
}

int hermite(int n, int x) {
	if (n <= 0) {
		return 1;
	} else if (n == 1) {
		return 2 * x;
	} else {
		return 2 * x * hermite(n - 1, x) - 2 * (n - 1) * hermite(n - 2, x);
	}
}
