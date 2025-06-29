#include <stdio.h>
#include <limits.h>

unsigned char getOpenBitNum(int value);

int main(void) {
    int value;

    printf("请输入一个 int 值：");
    scanf("%d", &value);

    printf("该值中打开的位的个数为：%hhu。\n", getOpenBitNum(value));

    return 0;
}

unsigned char getOpenBitNum(int value) {
    int mask = 0x1;
    unsigned char count = 0;
    register unsigned char i;

    for (i = 0; i < sizeof(int) * CHAR_BIT; ++i) {
        if ((value >> i) & mask == 1)
            ++count; 
    }

    return count;
}