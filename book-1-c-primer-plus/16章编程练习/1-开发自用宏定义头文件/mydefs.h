#ifndef MYDEFS_H
#define MYDEFS_H

// 处理换行符及可能剩余的其他字符
#define EAT_LINE              \
    while (getchar() != '\n') \
        ;

// 布尔值
#define TRUE 1
#define FALSE 0

#endif