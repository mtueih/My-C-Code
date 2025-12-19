/**
 * @file     book-3-pointers-on-c/chapter-9/14-2/main.c
 * @author   mtueih
 * @date     2025-12-16 21:48
 * @brief    my_strlen —— strlen 的防止字符串未以 NUL 结尾的版本。
 */

#include <stdio.h>
#include <stdlib.h>

#define STR_LENTH 10

size_t my_strlen(const char *str, size_t buf_size);

int main(void)
{

    char str[STR_LENTH] = {
        'h', 'e', 'l', 'l', 'o',
        ' ', 'w', 'o', 'r', 'l'};

    printf("%zu\n", my_strlen(str, STR_LENTH));

    return EXIT_SUCCESS;
}

size_t my_strlen(const char *str, size_t buf_size)
{
    size_t len = 0;

    for (len = 0; len < buf_size && str[len] != '\0';)
        ++len;

    return len;
}