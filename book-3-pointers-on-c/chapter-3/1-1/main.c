/**
 * @file     book-3-pointers-on-c/chapter-3/1-1/main.c
 * @author   mtueih
 * @date     2025-11-24 20:42
 * @brief    打印 limits.h 中的一些值。
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void) {

    printf("char 位数：%hhu\n", CHAR_BIT);

    printf("char 最小值-最大值：[%hhd, %hhd]\n", CHAR_MIN, CHAR_MAX);

    printf("signed char 最小值-最大值：[%hhd, %hhd]\n", SCHAR_MIN, SCHAR_MAX);
    printf("unsigned char 最大值：%hhu\n", UCHAR_MAX);

    printf("signed short 最小值-最大值：[%hd, %hd]\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short 最大值：%hu\n", USHRT_MAX);

    printf("signed int 最小值-最大值：[%d, %d]\n", INT_MIN, INT_MAX);
    printf("unsigned int 最大值：%u\n", UINT_MAX);

    printf("signed long 最小值-最大值：[%ld, %ld]\n", LONG_MIN, LONG_MAX);
    printf("unsigned long 最大值：%lu\n", ULONG_MAX);

    return EXIT_SUCCESS;
}
