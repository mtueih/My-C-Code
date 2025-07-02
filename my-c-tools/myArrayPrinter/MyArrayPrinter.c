#include "MyArrayPrinter.h"
#include <stdio.h>

#define ARRAY_PRINT_FUNCTION_DEFINITION(type, name, format)  \
    void print##name##Array(const type *arr, size_t ele_num) \
    {                                                        \
        size_t i;                                            \
        printf("[ ");                                        \
        for (i = 0; i < ele_num; ++i)                        \
        {                                                    \
            printf(format, arr[i]);                          \
            if (i < ele_num - 1)                             \
                printf(", ");                                \
        }                                                    \
        printf(" ]\n");                                      \
    }

ARRAY_PRINT_FUNCTION_DEFINITION(char, Char, "%c");
ARRAY_PRINT_FUNCTION_DEFINITION(signed char, SChar, "%hhd");
ARRAY_PRINT_FUNCTION_DEFINITION(unsigned char, UChar, "%hhu");
ARRAY_PRINT_FUNCTION_DEFINITION(int, Int, "%d");
ARRAY_PRINT_FUNCTION_DEFINITION(unsigned, UInt, "%u");
ARRAY_PRINT_FUNCTION_DEFINITION(short, Short, "%hd");
ARRAY_PRINT_FUNCTION_DEFINITION(unsigned short, UShort, "%hu");
ARRAY_PRINT_FUNCTION_DEFINITION(long, Long, "%ld");
ARRAY_PRINT_FUNCTION_DEFINITION(unsigned long, ULong, "%lu");
ARRAY_PRINT_FUNCTION_DEFINITION(long long, LLong, "%lld");
ARRAY_PRINT_FUNCTION_DEFINITION(unsigned long long, ULLong, "%llu");
ARRAY_PRINT_FUNCTION_DEFINITION(float, Float, "%f");
ARRAY_PRINT_FUNCTION_DEFINITION(double, Double, "%f");
ARRAY_PRINT_FUNCTION_DEFINITION(long double, LDouble, "%Lf");

void printGenericArray(const void *arr, size_t ele_num,
                       size_t size, void (*printFunc)(const void *))
{
    size_t i;
    printf("[ ");
    for (i = 0; i < ele_num; ++i)
    {
        printFunc(arr + i * size);
        if (i < ele_num - 1)
            printf(", ");
    }
    printf(" ]\n");
}