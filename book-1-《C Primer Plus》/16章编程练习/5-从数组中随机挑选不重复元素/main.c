#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <string.h>

// 取两数最小值的类函数宏
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))

// 宏定义数组大小
#define ARR_SIZE 100

// 宏定义选择个数
#define SELECT_NUM 50

// 从一个int数组中，随机挑选指定数量的元素并打印，每个元素只选择一次
void randomSelectFromArr(int * arr, size_t mem_num, size_t select_num);

int main(void) {

    int arr_0[ARR_SIZE];

    register size_t i;

    for (size_t i = 0; i < ARR_SIZE; ++i) {
        arr_0[i] = i + 1;
    }
    

    randomSelectFromArr(arr_0, ARR_SIZE, SELECT_NUM);

    return 0;
}


void randomSelectFromArr(int * arr, size_t mem_num, size_t select_num) {
    register size_t i;  // 用于 for 循环
    unsigned char * select_states;   // 用于存储每个元素是否已被选择
    size_t valid_selet_num;     // 用于存储有效的选择数（数组元素个数和参数的选择个数中的最小值）
    size_t states_size;     // 用于存储元素被选择状态所需的字节数
    size_t temp;        // 用于存储每次随机值
    
    // 计算有效选择数
    valid_selet_num = MIN(select_num, mem_num);

    /*
        使用单独的一个位来存储某一个索引下的元素是否已被选择
        使用位运算来操控这些位
    */
    states_size = mem_num % CHAR_BIT == 0
            ? mem_num / CHAR_BIT
            : mem_num / CHAR_BIT + 1;

    select_states = (unsigned char*)malloc(states_size);
    if (select_states == NULL) {
        fprintf(stderr, "内存分配失败！\n");
        return;
    }
    // 初始化
    memset(select_states, 0, sizeof(unsigned char));
    
    // 初始化随机数种子
    srand((unsigned)time(NULL));
    
    // 开始循环
    printf("随机选择了以下元素：\n");
    for (i = 0; i < valid_selet_num; ++i) {
        do { 
            temp = rand() % mem_num;
            // 检查该元素有没有被选择过
            if ((*(select_states + temp / CHAR_BIT) >> (temp % CHAR_BIT))
                & 0x1u) continue;
            else {
                *(select_states + temp / CHAR_BIT) |= 0x1u << (temp % CHAR_BIT);
                break;
            }
        } while (1);
        
        // 打印选择的值
        printf("%d\t", temp, arr[temp]);

        // 适当换行
        if ((i + 1) % CHAR_BIT == 0) putchar('\n');
    }
}