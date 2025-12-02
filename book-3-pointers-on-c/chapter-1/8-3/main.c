/**
 * @file     book-3-pointers-on-c/chapter-1/8-3/main.c
 * @author   mtueih
 * @date     2025-11-24 16:30
 * @brief    从标准输入读取一些字符并打印，计算并打印这些字符的「校验和」。
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int c;
    signed char checksum;   // 「校验和」
    
    checksum = -1;

    while ((c = getchar()) != EOF) {
        putchar(c);
        checksum += (signed char)c;

        if (c == '\n')
            break;
    }

    printf("%hhd\n", checksum);

    return EXIT_SUCCESS;
}
