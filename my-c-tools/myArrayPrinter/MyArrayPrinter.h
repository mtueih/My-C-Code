#ifndef MY_ARRAY_PRINTER_H
#define MY_ARRAY_PRINTER_H

#include <stddef.h>

#define printArray(arr, n)                            \
    _Generic((arr),                                   \
        char *: printCharArray,                       \
        const char *: printCharArray,                 \
        signed char *: printSCharArray,               \
        const signed char *: printSCharArray,         \
        unsigned char *: printUCharArray,             \
        const unsigned char *: printUCharArray,       \
        int *: printIntArray,                         \
        const int *: printIntArray,                   \
        unsigned int *: printUIntArray,               \
        const unsigned int *: printUIntArray,         \
        short *: printShortArray,                     \
        const short *: printShortArray,               \
        unsigned short *: printUShortArray,           \
        const unsigned short *: printUShortArray,     \
        long *: printLongArray,                       \
        const long *: printLongArray,                 \
        unsigned long *: printULongArray,             \
        const unsigned long *: printULongArray,       \
        long long *: printLLongArray,                 \
        const long long *: printLLongArray,           \
        unsigned long long *: printULLongArray,       \
        const unsigned long long *: printULLongArray, \
        float *: printFloatArray,                     \
        const float *: printFloatArray,               \
        double *: printDoubleArray,                   \
        const double *: printDoubleArray,             \
        long double *: printLDoubleArray,             \
        const long double *: printLDoubleArray)(arr, n)

#define ARRAY_PRINT_FUNCTION_PROTOTYPE(type, name) \
    void print##name##Array(const type *arr, size_t ele_num)

ARRAY_PRINT_FUNCTION_PROTOTYPE(char, Char);
ARRAY_PRINT_FUNCTION_PROTOTYPE(signed char, SChar);
ARRAY_PRINT_FUNCTION_PROTOTYPE(unsigned char, UChar);
ARRAY_PRINT_FUNCTION_PROTOTYPE(int, Int);
ARRAY_PRINT_FUNCTION_PROTOTYPE(unsigned, UInt);
ARRAY_PRINT_FUNCTION_PROTOTYPE(short, Short);
ARRAY_PRINT_FUNCTION_PROTOTYPE(unsigned short, UShort);
ARRAY_PRINT_FUNCTION_PROTOTYPE(long, Long);
ARRAY_PRINT_FUNCTION_PROTOTYPE(unsigned long, ULong);
ARRAY_PRINT_FUNCTION_PROTOTYPE(long long, LLong);
ARRAY_PRINT_FUNCTION_PROTOTYPE(unsigned long long, ULLong);
ARRAY_PRINT_FUNCTION_PROTOTYPE(float, Float);
ARRAY_PRINT_FUNCTION_PROTOTYPE(double, Double);
ARRAY_PRINT_FUNCTION_PROTOTYPE(long double, LDouble);

void printGenericArray(const void *arr, size_t ele_num,
                       size_t size, void (*printFunc)(const void *));

#endif // MY_ARRAY_PRINTER_H