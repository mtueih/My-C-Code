/**
 * @file     my-c-tools/mystring/mystring.c
 * @author   mtueih
 * @date     2025-12-19 19:50
 * @brief    mystring 实现文件。
 */

#include "mystring.h"

char *my_strcat(char *dst, const char *src, size_t buf_size) {
    size_t i, len;

    len = my_strlen(dst, buf_size);

    for (i = 0; i < buf_size - len - 1 && src[i] != '\0'; ++i) {
        dst[i + len] = src[i];
    }

    dst[i + len] = '\0';

    return dst;
}

size_t my_strlen(const char *str, size_t buf_size)
{
    size_t len = 0;

    for (len = 0; len < buf_size && str[len] != '\0';)
        ++len;

    return len;
}

char *my_strcpy(char *dst, const char *src, size_t buf_size)
{
    size_t i;

    for (i = 0; i < buf_size - 1 && src[i] != '\0'; ++i)
    {
        dst[i] = src[i];
    }

    dst[i] = '\0';

    return dst;
}