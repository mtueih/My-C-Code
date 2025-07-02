#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BIT_NUM 8u

// 按位取反
void bitInvert(const char *bin_str);
// 按位与
void bitAnd(const char *bin_str_1, const char *bin_str_2);
// 按位或
void bitOr(const char *bin_str_1, const char *bin_str_2);
// 按位异或
void bitXor(const char *bin_str_1, const char *bin_str_2);

// 接受两个二进制字符串作为参数
int main(int argc, char **argv)
{
    register unsigned i;

    if (argc != 3 || strlen(argv[1]) != BIT_NUM || strlen(argv[2]) != BIT_NUM)
    {
        fprintf(stderr, "参数有误！只接受两个 %u 位二进制字符串！\n", BIT_NUM);
        return EXIT_FAILURE;
    }

    for (i = 0; i < BIT_NUM; ++i)
    {
        if (argv[1][i] != '1' && argv[1][i] != '0' || argv[2][i] != '1' && argv[2][i] != '0')
        {

            fprintf(stderr, "参数有误！只接受两个 %u 位二进制字符串！\n", BIT_NUM);
            return EXIT_FAILURE;
        }
    }

    // 按位取反
    printf("按位取反：\n");
    printf("arg_1: ");
    bitInvert(argv[1]);
    printf("arg_2: ");
    bitInvert(argv[2]);

    // 按位与
    printf("按位与：");
    bitAnd(argv[1], argv[2]);

    // 按位或
    printf("按位或：");
    bitOr(argv[1], argv[2]);

    // 按位异或
    printf("按位异或：");
    bitXor(argv[1], argv[2]);

    return EXIT_SUCCESS;
}

// 按位取反
void bitInvert(const char *bin_str)
{
    register unsigned i;

    for (i = 0; i < BIT_NUM; ++i)
    {
        bin_str[i] == '0'
            ? putchar('1')
            : putchar('0');

        if ((i + 1) % 4 == 0)
            putchar(' ');
    }
    putchar('\n');
}

// 按位与
void bitAnd(const char *bin_str_1, const char *bin_str_2)
{
    register unsigned i;

    for (i = 0; i < BIT_NUM; ++i)
    {
        bin_str_1[i] == '1' && bin_str_2[i] == '1'
            ? putchar('1')
            : putchar('0');

        if ((i + 1) % 4 == 0)
            putchar(' ');
    }

    putchar('\n');
}

// 按位或
void bitOr(const char *bin_str_1, const char *bin_str_2)
{
    register unsigned i;

    for (i = 0; i < BIT_NUM; ++i)
    {
        bin_str_1[i] == '1' || bin_str_2[i] == '1'
            ? putchar('1')
            : putchar('0');

        if ((i + 1) % 4 == 0)
            putchar(' ');
    }

    putchar('\n');
}

// 按位异或
void bitXor(const char *bin_str_1, const char *bin_str_2)
{
    register unsigned i;

    for (i = 0; i < BIT_NUM; ++i)
    {
        bin_str_1[i] != bin_str_2[i]
            ? putchar('1')
            : putchar('0');

        if ((i + 1) % 4 == 0)
            putchar(' ');
    }

    putchar('\n');
}
