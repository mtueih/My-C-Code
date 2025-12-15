/**
 * @file     book-3-pointers-on-c/chapter-8/8-6/main.c
 * @author   mtueih
 * @date     2025-12-15 16:24
 * @brief    多维数组坐标转换为一维数组坐标。
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

    printf("%d\n", array_offset(array_info, 5, 1, -3));

    return EXIT_SUCCESS;
}

int array_offset(int arrayinfo[], ...) {
    va_list args;
    int offset;
    register size_t i;
    int index, min_coordinate, max_coordinate;

    // int min_coordinates[MAX_DIMENSION_NUM], max_coordinates[MAX_DIMENSION_NUM], 
    //     lengths[MAX_DIMENSION_NUM], indexes[MAX_DIMENSION_NUM];

    // 检查维数是否合法
    if (arrayinfo[0] < 1 || arrayinfo[0] > MAX_DIMENSION_NUM)
        return -1;
    

    // // 读取每一维坐标下限和上限，计算每一维长度
    // for (i = 0; i < arrayinfo[0]; ++i) {
    //     min_coordinates[i] = arrayinfo[i * 2 + 1];
    //     max_coordinates[i] = arrayinfo[i * 2 + 2];

    //     if (min_coordinates[i] > max_coordinates[i])
    //         return -1;
        
    //     lengths[i] = max_coordinates[i] - min_coordinates[i] + 1;
    // }

    // // 读取每一维坐标
    va_start(args, arrayinfo);

    // for (i = 0; i < arrayinfo[0]; ++i) {
    //     indexes[i] = va_arg(args, int);
    //     if (indexes[i] < min_coordinates[i] || indexes[i] > max_coordinates[i]) {
    //         va_end(args);
    //         return -1;
    //     }
    // }

    // va_end(args);

    // // 计算偏移量
    // for (i = 0, offset = 0; i < arrayinfo[0]; ++i) {
    //     offset = offset * lengths[i] + (indexes[i] - min_coordinates[i]);
    // }

    for (i = 0, offset = 0; i < arrayinfo[0]; ++i) {
        index = va_arg(args, int);
        min_coordinate = arrayinfo[i * 2 + 1];
        max_coordinate = arrayinfo[i * 2 + 2];

        if (min_coordinate > max_coordinate || index < min_coordinate || index > max_coordinate) {
            va_end(args);
            return -1;
        }

        offset = offset * (max_coordinate - min_coordinate + 1) + index - min_coordinate;
    }

    va_end(args);

    return offset;
}