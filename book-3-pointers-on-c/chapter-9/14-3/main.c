/**
 * @file     book-3-pointers-on-c/chapter-9/14-3/main.c
 * @author   mtueih
 * @date     2025-12-17 13:25
 * @brief    my_strlen —— strlen 的确保「以 NUL 字符结尾」和「不会溢出目标数组」的版本。
 */

#include <stdio.h>
#include <stdlib.h>

#define STR_LENTH 10

char *my_strcpy(char *dst, const char *src, size_t buf_size);

int main(void)
{

    char str[STR_LENTH];

    size_t i;

    my_strcpy(str, "hello world", STR_LENTH);

    printf("{");
    for (i = 0; i < STR_LENTH; ++i)
    {
        switch (str[i])
        {
        case '\0':
            printf("\'\\0\'");
            break;
        default:
            printf(" \'%c\'", str[i]);
            break;
        }
        i == STR_LENTH - 1 ? 0 : printf(",");
    }
    printf(" }\n");

    return EXIT_SUCCESS;
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