/**
 * @file     book-3-pointers-on-c/chapter-7/7-11-3/main.c
 * @author   mtueih
 * @date     2025-12-02 21:38
 * @brief    字符串转整数。
 */

#include <stdio.h>
#include <stdlib.h>

#define TEST_STR "1008611"

int ascii_to_interger(char *str);

int main(void) {

    printf("%s -> %d\n", TEST_STR, ascii_to_interger(TEST_STR));

    return EXIT_SUCCESS;
}

int ascii_to_interger(char *str) {
	int n;

	for (n = 0; *str >= '0' && *str <= '9'; ++str) {
		n *= 10;
		n += *str - '0';
	}

	if (*str != '\0') {
		n = 0;
	}

	return n;
}