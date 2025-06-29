#include <stdio.h>
#include <limits.h>

_Bool getBitValueOfIndex(int value, unsigned char index);

int main(void) {
    int value;
    unsigned char index;

    printf("请输入一个 int 值：");
    scanf("%d", &value);

    printf("请输入要检查的位的索引：");
     scanf("%hhu", &index);

    printf("该值的 %hhd 索引处的位的值为：%d。\n", index, getBitValueOfIndex(value, index));

    return 0;
}

_Bool getBitValueOfIndex(int value, unsigned char index) {
    if (index >= sizeof(int) * CHAR_BIT) {
        return 0;
    }

    return (value >> index) & 0x1 ? 1 : 0; 
}