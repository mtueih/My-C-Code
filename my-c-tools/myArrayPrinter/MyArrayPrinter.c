#include "MyArrayPrinter.h"

#define ARRAY_PRINT_FUNCTION_DEFINITION(type, name, format)\
    void print##name##Array(const type * arr, size_t ele_num) {\
        register size_t i;                                    \
        for (i = 0; i < ele_num; ++i) {                        \
            printf(format "\t", arr[i]);                      \
        }                                                     \
        putchar('\n');                                        \
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
ARRAY_PRINT_FUNCTION_DEFINITION(long, LDouble, "%lf");