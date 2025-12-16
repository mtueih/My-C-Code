/**
 * @file     book-3-pointers-on-c/chapter-9/14-1/main.c
 * @author   mtueih
 * @date     2025-12-16 21:26
 * @brief    使用 ctype.h 中的函数，统计从标准输入输入的各类字符占比。
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void) {

    int c;

    size_t cntrl_num = 0;
    size_t space_num = 0;
    size_t digit_num = 0;
    size_t lower_num = 0;
    size_t upper_num = 0;
    size_t punct_num = 0;
    size_t non_print_num = 0;
    
    size_t sum = 0;

    printf("请输入一些字符，回车结束：\n");
    while (c = getchar(), c != EOF && c != '\n') {
        if (iscntrl(c)) ++cntrl_num;
        if (isspace(c)) ++space_num;
        if (isdigit(c)) ++digit_num;
        if (islower(c)) ++lower_num;
        if (isupper(c)) ++upper_num;
        if (ispunct(c)) ++punct_num;
        if (!isprint(c)) ++non_print_num;
        ++sum;
    }

    printf("字符类型\t所占百分比\n");
    printf("控制字符\t%.2f%%\n", (double)cntrl_num / sum * 100.0);
    printf("空白字符\t%.2f%%\n", (double)space_num / sum * 100.0);
    printf("数字\t%.2f%%\n", (double)digit_num / sum * 100.0);
    printf("小写字母\t%.2f%%\n", (double)lower_num / sum * 100.0);
    printf("大写字母\t%.2f%%\n", (double)upper_num / sum * 100.0);
    printf("标点符号\t%.2f%%\n", (double)punct_num / sum * 100.0);
    printf("不可打印的字符\t%.2f%%\n", (double)non_print_num / sum * 100.0);

    return EXIT_SUCCESS;
}
