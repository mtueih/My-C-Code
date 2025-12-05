/**
 * @file     book-3-pointers-on-c/chapter-8/7-8/file.c
 * @author   mtueih
 * @date     2025-12-05 11:46
 * @brief    声明外部链接变量（数组与指针）。
 */

#include <stdio.h>

int a[10];
int *b = a;


void func(void) {
	printf("%s\t%s\t:\t%p\n", __FILE__, __func__, a);
	// printf("%s\t%s\t:\t%p\n", __FILE__, __func__, b);
}