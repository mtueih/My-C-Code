/**
 * @file     book-3-pointers-on-c/chapter-8/8-4/main.c
 * @author   mtueih
 * @date     2025-12-14 21:09
 * @brief    判断一个 nxn 的矩阵是否是单位矩阵。
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DEGREE 10

bool identity_matrix(int *matrix, int degree);

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

    printf("%s\n", identity_matrix(&matrix[0][0], DEGREE) ? "是单位矩阵" : "不是单位矩阵");


    return EXIT_SUCCESS;
}

bool identity_matrix(int *matrix, int degree) {
    unsigned int i, j;

    for (i = 0; i < degree; ++i) {
        for (j = 0; j < degree; ++j) {
            if (i == j && *(matrix + i * degree + j) != 1) {
                return false;
            }
            if (i != j && *(matrix + i * degree + j) != 0) {
                return false;
            }
        }
    }

    return true;
}