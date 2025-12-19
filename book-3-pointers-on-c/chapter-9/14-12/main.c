/**
 * @file     book-3-pointers-on-c/chapter-9/14-12/main.c
 * @author   mtueih
 * @date     2025-12-19 19:43
 * @brief    密钥生成——根据单词生成密钥。
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "mystring.h"

#define ALPHABET_SIZE 26
#define KEY_ARR_SIZE ((ALPHABET_SIZE) + 1)

int prepare_key(char *key);

int main(void)
{

    char key[KEY_ARR_SIZE];
    int result;

    my_strcpy(key, "trailblazers", KEY_ARR_SIZE);

    result = prepare_key(key);

    if (result)
    {
        printf("%s\n", key);
    }

    return EXIT_SUCCESS;
}

int prepare_key(char *key)
{
    size_t i, j;
    bool mark[ALPHABET_SIZE];

    if (key == NULL)
        return 0;

    for (i = 0; i < ALPHABET_SIZE; ++i)
    {
        mark[i] = false;
    }

    // 全部转换为小写
    for (i = 0; key[i] != '\0'; ++i)
    {
        if (!isalpha(key[i]))
            return 0;

        key[i] = tolower(key[i]);
    }

    // 去除重复字母
    for (i = 0; key[i] != '\0';)
    {
        if (!mark[key[i] - 'a'])
        {
            mark[key[i] - 'a'] = true;
            ++i;
            continue;
        }

        for (j = i; key[j] != '\0'; ++j)
        {
            key[j] = key[j + 1];
        }
    }

    // 补全密钥
    for (j = 0; j < ALPHABET_SIZE; ++j)
    {
        if (!mark[j])
        {
            key[i++] = 'a' + j;
        }
    }
    key[i] = '\0';

    return 1;
}