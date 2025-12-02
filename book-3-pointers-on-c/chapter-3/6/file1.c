/**
 * @file     book-3-pointers-on-c/chapter-3/6/file1.c
 * @author   mtueih
 * @date     2025-11-25 11:24
 * @brief    定义外部链接函数，用于「测试」标识符的「链接」属性。
 */

#include <stdio.h>
#include <stdlib.h>

int a;



void func(void) {
    extern int a;

    printf("%s in %s : a = %d\n", __func__, __FILE__, a);
}