/**
 * @file     my-c-tools/mystring/mystring.h
 * @author   mtueih
 * @date     2025-12-19 19:54
 * @brief    mystring 头文件。
 */

#ifndef MYSTRING_H
#define MYSTRING_H

#include <stddef.h>

size_t my_strlen(const char *str, size_t buf_size);
char *my_strcpy(char *dst, const char *src, size_t buf_size);
char *my_strcat(char *dst, const char *src, size_t buf_size);

#endif // MYSTRING_H