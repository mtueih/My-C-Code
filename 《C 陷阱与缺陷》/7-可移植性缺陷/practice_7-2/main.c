#include <stdio.h>



/* atol 函数：将字符串转换成长整型数 */
long atol(const char *str);

int main(void) {



    return 0;
}

long atol(const char *str) {
    long num = 0;
    _Bool positive;

    if (!str) return 0;

    if (str[0] == '-') positive = 0;
    // else if (str[0] == '+'-) positive = 1;
    
}