/**
 * @file     book-3-pointers-on-c/chapter-8/7-8/main.c
 * @author   mtueih
 * @date     2025-12-05 11:45
 * @brief    声明定义在其他文件中的变量（数组与指针），用于研究数组与指针的异同。
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	extern int *a;
	extern int b[];
	extern void func(void);

	if (a != NULL) {
		printf("%s\t%s\t:\t%p\n", __FILE__, __func__, a);
		// printf("%s\t%s\t:\t%p\n", __FILE__, __func__, b);
	}
	func();

	return EXIT_SUCCESS;
}
