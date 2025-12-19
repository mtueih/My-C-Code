/**
 * @file     book-3-pointers-on-c/chapter-9/14-9/main.c
 * @author   mtueih
 * @date     2025-12-17 14:02
 * @brief    count_chars 函数：统计一个字符串中包含某些字符的个数。
 */

#include <stdio.h>
#include <stdlib.h>

int count_chars(const char *str, const char *chars);

int main(void) {

    const char *str = "hello, world!";
    const char *chars = ", !";

    printf("%d\n", count_chars(str, chars));

    return EXIT_SUCCESS;
}

int count_chars(const char *str, const char *chars) {
    int count;
    size_t i, j;

    for (i = 0; str[i] != '\0'; ++i) {
        for (j = 0; chars[j] != '\0'; ++j) {
            if (str[i] == chars[j]) {
                ++count;
                break;
            }
        }
    }

    return count;
}