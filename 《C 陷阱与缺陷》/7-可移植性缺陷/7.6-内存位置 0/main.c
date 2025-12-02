#include <stdio.h>

int main(void) {

    char *p = NULL;

    // 对内存位置 0 的读操作 —— 未定义行为
    printf("指向内存位置 0 的内容：%d\n", *p);

    printf("Hello, world!\n");

    return 0;
}
