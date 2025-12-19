/**
 * @file     book-3-pointers-on-c/chapter-9/14-14/main.c
 * @author   mtueih
 * @date     2025-12-19 21:08
 * @brief    根据密钥解密信息。
 */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include "mystring.h"

#define STR_ARR_SIZE 100
#define ALPHABET_SIZE 26
#define KEY_ARR_SIZE ((ALPHABET_SIZE) + 1)

int prepare_key(char *key);
void encrypt(char *data, const char *key);
void decrypt(char *data, const char * key);

int main(void)
{
    // 声明
    char data[STR_ARR_SIZE];    // 要加密的信息
    char data_encrpted[STR_ARR_SIZE];    // 加密后的信息
    char data_decrpted[STR_ARR_SIZE];    // 解密后的信息
    char word[KEY_ARR_SIZE];    // 用于生成密钥的单词
    char key[KEY_ARR_SIZE];     // 生成的密钥
    int result;

    // 初始化
    my_strcpy(word, "trailblazers", KEY_ARR_SIZE);
    my_strcpy(data, "attack at dawn", STR_ARR_SIZE);

    // 生成密钥
    my_strcpy(key, word, KEY_ARR_SIZE);
    result = prepare_key(key);

    if (!result)
    {
        fprintf(stderr, "错误：未能成功生成密钥！\n");
        return EXIT_FAILURE;
    }

    printf("从单词「%s」生成密钥：「%s」。\n", word, key);

    // 加密
    my_strcpy(data_encrpted, data, STR_ARR_SIZE);
    encrypt(data_encrpted, key);

    printf("字符串「%s」被加密为：「%s」。\n", data, data_encrpted);

    // 解密
    my_strcpy(data_decrpted, data_encrpted, STR_ARR_SIZE);
    decrypt(data_decrpted, key);

    printf("加密字符串「%s」被解密为：「%s」。\n", data_encrpted, data_decrpted);


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

void encrypt(char *data, const char *key) {
    size_t i;

    for (i = 0; data[i] != '\0'; ++i) {
        data[i] = tolower(data[i]);

        if (islower(data[i])) {
            data[i] = key[data[i] - 'a'];
        }
    }
}

void decrypt(char *data, const char * key) {
    size_t i;

    for (i = 0; data[i] != '\0'; ++i) {
        if (islower(data[i])) {
            data[i] = 'a' + (strchr(key, data[i]) - key);
        }
    }
}