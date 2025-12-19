/**
 * @file     book-3-pointers-on-c/chapter-9/14-10/main.c
 * @author   mtueih
 * @date     2025-12-17 14:10
 * @brief    回文判断，忽略非字母字符，忽略大小写。
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int palindrome(char *string);

int main(void) {

    printf("%s回文\n", palindrome("Madam, I'm Adam") ? "是" : "不是");    

    return EXIT_SUCCESS;
}

int palindrome(char *string) {
    size_t i, j;

    for (i = 0, j = strlen(string) - 1; i <= j; ) {
        if (!isalpha(string[i])) {
            ++i;
            continue;
        }

        if (!isalpha(string[j])) {
            --j;
            continue;
        }

        printf("string[%zu] : %c\tstring[%zu] : %c\n", i, string[i], j, string[j]);

        if (tolower(string[i]) != tolower(string[j])) {
            return 0;
        }

        ++i, --j;
    }

    return 1;
}