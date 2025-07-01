#ifndef MY_ARRAY_PRINTER_H
#define MY_ARRAY_PRINTER_H

#include <stddef.h>



#define TYPE_NAME_STR(type_name) _Generic(type_name, \
    char: Char,\
    signed char: SChar,\
    unsigned char: UChar,\
    short: Short,\
    unsigned short: UShort,\
    int: Int,\
    unsigned int: UInt,\
    long: Long,\
    unsigned long: ULong,\
    long long: LLong,\
    unsigned long long: ULLong\
)


#define ARRAY_PRINT_FUNCTION_PROTOTYPE(type, name) \
    void printf ## name ## Array(const type * arr, size_t ele_num)

#define printArray(arr, ele_num) _Generic((arr),\
    char*: printCharArray,\
    const char*: printCharArray,\
    signed char*: printSCharArray,\
    const signed char*: printSCharArray,\
    unsigned char*: printUCharArray,\
    const unsigned char*: printUCharArray,\
    short*: printShortArray,\
    const short*: printShortArray,\
    unsigned short*: printUShortArray,\
    const unsigned short*: printUShortArray,\
    int*: printIntArray,\
    const int*: printIntArray,\
    unsigned*: printUIntArray,\
    const unsigned*: printUIntArray,\
    long*: printLongArray,\
    const long*: printLongArray,\
    unsigned long*: printULongArray,\
    const unsigned long*: printULongArray,\
    long long*: printLLongArray,\
    const long long*: printLLongArray,\
    unsigned long long*: printULLongArray,\
    const unsigned long long*: printULLongArray,\
    float*: printFloatArray,\
    const float*: printFloatArray,\
    double*: printDoubleArray,\
    const double*: printDoubleArray,\
    long double*: printLDoubleArray,\
    const long double*: printLDoubleArray\
)(arr, ele_num)

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
ARRAY_PRINT_FUNCTION_PROTOTYPE(long, LDouble);



#endif // MY_ARRAY_PRINTER_H