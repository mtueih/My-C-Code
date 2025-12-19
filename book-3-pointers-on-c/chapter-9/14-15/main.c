/**
 * @file     book-3-pointers-on-c/chapter-9/14-15/main.c
 * @author   mtueih
 * @date     2025-12-19 21:21
 * @brief    将数字字符串转换为逗号、小数点分隔形式。
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dollars(char *dest, const char *src);

int main(void) {

    

    return EXIT_SUCCESS;
}

void dollars(char *dest, const char *src) {
    size_t i, j, k, len;

    len = strlen(src);

    k = len;

    for (i = 0, j = 0; j < 5; ++j) {
        
    }

    if (len < 3) {
        if (len == 0) {
            strcpy(dest, "$0.00");
            return;
        }

        for (i = 0, j = 0; j < 3; j++) {
            if (j == 0) {
                dest[j] = '$';
                ++j;
            }
        }

    }

    for (i = 0, j = 0, k = len - 2; src[i] != '\0'; ++i){
        if (i != 0 && k % 3 == 0) {
            dest[j] = k == 0 ? '.' : ',';
            ++j;
        }
        dest[j] = src[i];
        ++j;
    }
}