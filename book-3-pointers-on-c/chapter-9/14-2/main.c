/**
 * @file     book-3-pointers-on-c/chapter-9/14-2/main.c
 * @author   mtueih
 * @date     2025-12-16 21:48
 * @brief    my_strlen —— strnlen 的确保目标字符串以 NUL 结尾的版本。
 */

#include <stdio.h>
#include <stdlib.h>

char *my_strcpy(char *dst, const char *src, size_t buf_size);

int main(void) {

    

    return EXIT_SUCCESS;
}

char *my_strcpy(char *dst, const char *src, size_t buf_size) {
    size_t i;

    for (i = 0; i < buf_size - 1 && src; ++i)
}