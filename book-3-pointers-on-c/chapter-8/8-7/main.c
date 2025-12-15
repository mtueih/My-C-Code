/**
 * @file     book-3-pointers-on-c/chapter-8/8-7/main.c
 * @author   mtueih
 * @date     2025-12-15 19:38
 * @brief    多维数组坐标转换为一维数组坐标（列主序）。
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define MAX_DIMENSION_NUM 10

int array_offset(int arrayinfo[], ...);

int main(void) {

    int array_info[] = {
        3, 4, 6, 1, 5, -3, 3
    };

    printf("%d\n", array_offset(array_info, 4, 1, -1));

    return EXIT_SUCCESS;
}

// int array_offset(int arrayinfo[], ...) {
//     va_list args;
//     int offset;
//     int i;
//     int min_coordinate, max_coordinate;
//     int *p_indexes;

//     // 检查维数是否合法
//     if (arrayinfo[0] < 1 || arrayinfo[0] > MAX_DIMENSION_NUM)
//         return -1;

//     // 动态分配数组以存储各维度坐标值
//     p_indexes = (int *)malloc(arrayinfo[0] * sizeof(int));
//     if (!p_indexes) return -1;

//     va_start(args, arrayinfo);

//     for (i = 0; i < arrayinfo[0]; ++i) {
//         p_indexes[i] = va_arg(args, int);
//     }

//     va_end(args);


//     for (i = arrayinfo[0] - 1, offset = 0; i >= 0; --i) {
//         min_coordinate = arrayinfo[i * 2 + 1];
//         max_coordinate = arrayinfo[i * 2 + 2];
//         if (min_coordinate > max_coordinate || p_indexes[i] < min_coordinate || p_indexes[i] > max_coordinate) {
//             free(p_indexes);
//             printf("i = %d\n", i);
//             return -1;
//         }

//         offset = offset * (max_coordinate - min_coordinate + 1) + p_indexes[i] - min_coordinate;
//     }


//     // va_end(args);

//     free(p_indexes);
//     return offset;
// }

int array_offset(int arrayinfo[], ...) {
    va_list args;
    int dim = arrayinfo[0];
    if (dim < 1 || dim > 10) return -1;
    
    va_start(args, arrayinfo);
    int offset = 0;
    int weight = 1;  // 当前维度的权重
    
    for (int i = 0; i < dim; ++i) {
        int idx = va_arg(args, int);
        int lo = arrayinfo[i * 2 + 1];
        int hi = arrayinfo[i * 2 + 2];
        int len = hi - lo + 1;
        
        if (lo > hi || idx < lo || idx > hi) {
            va_end(args);
            return -1;
        }
        
        printf("【i = %d】原 offset：%d\tweight：%d\n", i, offset, weight);
        
        offset += (idx - lo) * weight;
        weight *= len;  // 下一维的权重

        printf("【i = %d】现 offset：%d\tweight：%d\n", i, offset, weight);
    }
    
    va_end(args);
    return offset;
}