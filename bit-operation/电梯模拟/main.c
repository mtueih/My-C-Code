#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


#define MAX_FLOORS_NUM 9
#define MIN_FLOORS_NUM 1



void printBtn(int btn_states) {
    

    register int i;
    int mask = 0x1;
    
    
    for (i = MAX_FLOORS_NUM; i >= MIN_FLOORS_NUM; --i) {
        (btn_states & (mask << i)) ?
            printf("【%d】\t", i)
            : printf("  %d  \t", i);
        if (i % 2 == 0) putchar('\n');
    }
}

int main(void) {

    int btn_states = 0x0;
    int mask = 1;
    
    int c, c_num;

    do
    {
        system("cls");
        printBtn(btn_states);

        printf("\n按 [%d] ~ [%d] 键触发相应楼层按钮，按 [q] 退出。\n",
        MIN_FLOORS_NUM, MAX_FLOORS_NUM);

        c = getch();

        c_num = c - '0';


        if (c_num >= MIN_FLOORS_NUM && c_num <= MAX_FLOORS_NUM) {
            btn_states ^= mask << c_num;
        }
    } while (c != 'q');
    
    // printf("请按下任意键：\n");

    // char c = getch();  // 不需要按回车，立即响应
    // printf("\n你按下的键是：%c\n", c);
    printf("再见\n");

    return 0;
}