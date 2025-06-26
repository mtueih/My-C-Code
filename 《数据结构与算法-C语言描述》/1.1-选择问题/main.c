/*
有 N 个数，要确定其中第 k 个最大者
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#define N 10000    // 数的个数
#define K 6666     // 最大值的序号

#define USED_METHOD 1  // 定义使用哪个思路的代码，用于条件编译

// 对 intmax_t 数组进行排序的函数，第三个参数用于指定是按顺序排序
void sort(intmax_t * p_arr, size_t arr_size, bool isASC);

int main(void) {
    register size_t i, j, z;
    intmax_t temp, result, arr_1[N], arr_2[K];
    FILE * p_file;

    // printf("请输入 %zd 个整数：\n", N);

    p_file = fopen("randomNumber.txt", "r");
    if (p_file == NULL)
        return EXIT_FAILURE;

#if USED_METHOD == 1
    /*
        思路 1：
        将 N 个数读入一个 N 元数组;
        使用冒泡排序法对数组进行排序;
        读出位置为 k（下标应为 k - 1）的元素。
    */ 
    
    for (i = 0; i < N; ++i) {
        fscanf(p_file, "%jd", &arr_1[i]);
    }

    // ⭐冒牌排序法⭐（降序）
    sort(arr_1, N, false);

    result = arr_1[K - 1];

#elif USED_METHOD == 2
    /*
        思路 2：
        先将前 k 个数读入数组（一个 k 元数组）并以递减的顺序对其排序；
        之后的数依次读取并与当前数组中第 k 个元素比较，
            如果前者大于后者，就将其放入数组中正确的位置，
            否则忽略；
        读取完毕后，数组中第 k 个元素即是结果。
    */

    // 读取前 k 个数到数组中，并使用冒泡排序对其进行降序排列
    for (i = 0; i < K; ++i) {
        fscanf(p_file, "%jd", &arr_2[i]);
    }

    sort(arr_2, K, false);

    // 逐个读取后面的数，并根据情况“插入”数组
    for (i = K; i < N; ++i) {
        fscanf(p_file, "%jd", &temp);
        // 如果其小于等于第 k 个数，则忽略
        if (temp <= arr_2[K - 1])
            continue;
        
        // 在原数组中寻找其正确位置
        for (j = 0; j < K; ++j) {
            if (temp > arr_2[j])
                break;
        }

        // 后面元素依次“右移”
        for (z = K - 1; z > j; --z) {
            arr_2[z] = arr_2[z - 1];
        }
        
        arr_2[j] = temp;
    }

    result = arr_2[K - 1];

#endif

    printf("第 %zd 个最大值为：%jd\n", K, result);

    fclose(p_file);
    return 0;
}

void sort(intmax_t * p_arr, size_t arr_size, bool isASC) {
    register size_t i, j;
    intmax_t temp;

    if (p_arr == NULL) return;

    for (i = 0; i < arr_size - 1; ++i) {
        for (j = 0; j < arr_size - 1 - i; ++j) {
            if (isASC 
                ? p_arr[j] > p_arr[j + 1] 
                : p_arr[j] < p_arr[j + 1]
            ) {
                temp = p_arr[j];
                p_arr[j] = p_arr[j + 1];
                p_arr[j + 1] = temp;
            }
        }
    }
}