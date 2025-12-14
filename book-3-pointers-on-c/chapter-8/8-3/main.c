/**
 * @file     book-3-pointers-on-c/chapter-8/8-3/main.c
 * @author   mtueih
 * @date     2025-12-14 20:57
 * @brief    判断一个 10x10 的矩阵是否是单位矩阵。
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DEGREE 10

bool identity_matrix(int matrix[][DEGREE]);

int main(void) {
    int matrix[DEGREE][DEGREE] = {
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
    };

    printf("%s\n", identity_matrix(matrix) ? "是单位矩阵" : "不是单位矩阵");


    return EXIT_SUCCESS;
}

bool identity_matrix(int matrix[][DEGREE]) {
    unsigned int i, j;

    for (i = 0; i < DEGREE; ++i) {
        for (j = 0; j < DEGREE; ++j) {
            if (i == j && matrix[i][j] != 1) {
                return false;
            }
            if (i != j && matrix[i][j] != 0) {
                return false;
            }
        }
    }

    return true;
}