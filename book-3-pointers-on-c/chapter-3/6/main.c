/**
 * @file     book-3-pointers-on-c/chapter-3/6/main.c
 * @author   mtueih
 * @date     2025-11-25 10:29
 * @brief    用于「测试」标识符的「链接」属性。
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * 对于函数的声明而言，如果不指定 static，那么默认就是 extern，
 * 即，加于不加 extern，是等价的，因此可以重复声明，
 * 但每次声明的函数原型必须一致。
 */

// static void func(void);    // 函数的声明

extern void func(void);    // 函数的声明

// int func(int);  // 声明冲突（语法错误）

// void func(void);    // 重复声明、无 static（允许）


/**
 * 变量声明
 */

extern int a;

// int a;
// extern int a;
// static int a;

// static int a = 6;
// static int a = 7;

int main(void) {

    // void func(void);    // 重复声明、无 static（允许）

    // extern void func(void);    // 加 extern 的重复声明（允许）

#if 0
    static void func(void);    // 在代码块中声明 static 函数（错误）
    /**
     * 由此可以知道，不论是函数还是变量，在块作用域中，
     * static 关键字的作用都是声明静态存储类型，
     * 而在文件作用域中，其作用都是声明内部链接。
     */
#endif

    
    func();     // 在调用前必须声明

    extern int a;

    a;
    printf("a = %d\n", a);

    return EXIT_SUCCESS;
}

// void func(void) {
//     printf("func 1\n");
// }

// extern void func(void) {
//     printf("func 2\n");
// }

// static void func(void) {
//     printf("static func 1\n");
// }

// int func(int) {
//     printf("func 3\n");
// }



