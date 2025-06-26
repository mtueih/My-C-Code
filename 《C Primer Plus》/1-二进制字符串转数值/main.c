#include <stdio.h>
#include <limits.h>

/*
    函数使用 sizeof(int) * CHAR_BIT + 1 来确定字符串长度。
*/
int binaryStringToInteger(const char * binary_string);


int main(void) {
    char brnary_str[sizeof(int) * CHAR_BIT + 1] = 
        "11111111"
        "11110000"
        "11000011"
        "10001000";
    
    printf("二进制【%s】\n对应数值（int）为：%d\n", brnary_str, binaryStringToInteger(brnary_str));

    return 0;
}

int binaryStringToInteger(const char * binary_string) {
    int value = 0;
    register unsigned char i;
    static const unsigned char int_bits = sizeof(int) * CHAR_BIT;

    for (i = 1; i < int_bits; ++i) {

        if (binary_string[0] == '0' && binary_string[i] == '1'
            ||
            binary_string[0] == '1' && binary_string[i] == '0') {
            
            /*
                0 1 0 0 1 0 0 1
                7 6 5 4 3 2 1 0
            */
            value |= (1 << (int_bits - i - 1));
        }
    }

    if (binary_string[0] == '1')
        value = ~value;

    return value;
}