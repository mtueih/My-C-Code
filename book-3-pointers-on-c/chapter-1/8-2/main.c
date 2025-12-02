/**
 * @file     book-3-pointers-on-c/chapter-1/8-2/main.c
 * @author   mtueih
 * @date     2025-11-24 15:59
 * @brief    从标准输出逐行读取文本（直到遇到空行）并依次输出至标准输出。
 * 输出时，每行开头打印行号。
 * 通过逐个读取字符的方式，使得每行输入的长度没有限制。
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
    int c;          // 字符
    unsigned line;  // 行号
    bool lineHead;  // 是否在行首

    line = 0;
    lineHead = true;

    while ((c = getchar()) != EOF) {
        if (lineHead && c == '\n')
            break;

        if (lineHead) {
            lineHead = false;
            printf("%u ", ++line);
        }

        putchar(c);

        if (c == '\n') {
            lineHead = true;
        }
    }

    return EXIT_SUCCESS;
}
