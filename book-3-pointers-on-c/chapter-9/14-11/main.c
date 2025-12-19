/**
 * @file     book-3-pointers-on-c/chapter-9/14-11/main.c
 * @author   mtueih
 * @date     2025-12-17 16:07
 * @brief    统计标准输入单词 the 出现次数。
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_MAX 100
#define COUNTED_WORD "the"
#define SPACE_CHARS " \t\f\r\v\n"

int main(void)
{
    char str[STR_MAX];
    char *word;
    size_t i;
    size_t num;

    for (i = 0; str[i] = getchar(), str[i] != EOF && str[i] != '\n'; ++i)
        ;

    str[i] = '\0';

    // for (num = 0, i = 0; i < STR_MAX && str[i] != '\0'; ++i) {
    //     if (str[i] != COUNTED_WORD[0]) continue;

    //     if (strncmp(str + i, COUNTED_WORD, strlen(COUNTED_WORD)) == 0) {
    //         ++num;
    //         i += strlen(COUNTED_WORD) - 1;
    //     }
    // }

    for (num = 0, word = strtok(str, SPACE_CHARS); word != NULL; word = strtok(NULL, SPACE_CHARS)) {
        if (strcmp(word, COUNTED_WORD) == 0) {
            ++num;
        }
    }


    printf("%s 单词一共出现了 %zu 次。\n", COUNTED_WORD, num);

    return EXIT_SUCCESS;
}
