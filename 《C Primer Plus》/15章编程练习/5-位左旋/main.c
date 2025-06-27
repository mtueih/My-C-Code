#include <stdio.h>
#include <limits.h>

// 位左旋：按位向左移动，左边多出的位重新出现在右边
unsigned bitRotateL(unsigned value, unsigned char step);


int main(void) {
    unsigned value;
    unsigned char step;

    printf("请输入一个 unsigned 值：");
    scanf("%u", &value);

    printf("请输入要左旋的步数：");
     scanf("%hhu", &step);

    printf("左旋后的值为：%u。\n", bitRotateL(value, step));

    return 0;
}

// 位左旋：按位向左移动，左边多出的位重新出现在右边
unsigned bitRotateL(unsigned value, unsigned char step) {
    _Bool record;
    unsigned result = value;
    unsigned char valid_step;
    register unsigned char i;


    static const unsigned char uint_bits = sizeof(unsigned) * CHAR_BIT;

    // 步数化简，得到“有效步数”
    valid_step = step % uint_bits;

    // 左旋
    for (i = 0; i < valid_step; ++i) {
        // 记录
            record = (value >> uint_bits - 1u - i) & 0x1u;
        // 左移
            result <<= 1u;
        // 填充
            result |= record;
    }

    return result;
}