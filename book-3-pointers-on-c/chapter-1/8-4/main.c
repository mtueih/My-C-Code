/**
 * @file     book-3-pointers-on-c/chapter-1/8-4/main.c
 * @author   mtueih
 * @date     2025-11-24 16:47
 * @brief    从标准输入逐行读取文本（直到文件结尾）并打印最长的那一行。
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1000

int main(void) {
    char str[MAX_STR_LEN];
    char longestStr[MAX_STR_LEN];
    unsigned len;
    unsigned maxLen;

    maxLen = 0;
    longestStr[0] = '\0';

    while (fgets(str, MAX_STR_LEN, stdin) != NULL) {
        len = strlen(str);
        if (len > maxLen) {
            maxLen = len;
            strncpy(longestStr, str, len + 1);  
        }
    }
    
    fputs(longestStr, stdout);

    return EXIT_SUCCESS;
}
