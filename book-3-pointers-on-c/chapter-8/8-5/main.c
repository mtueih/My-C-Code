/**
 * @file     book-3-pointers-on-c/chapter-8/8-5/main.c
 * @author   mtueih
 * @date     2025-12-15 10:39
 * @brief    矩阵乘法。
 */

#include <stdio.h>
#include <stdlib.h>

#define X 3
#define Y 2
#define Z 4

// m1[x][y] * m2[y][z] = r[x][z]（如果看成是未压扁数组的话）
void matrix_multiply(int *m1, int *m2, int *r, int x, int y, int z);
void print_matrix(int *m, int x, int y);

int main(void) {

    int m1[X][Y] = {
        { 2, -6 },
        { 3, 5 },
        { 1, -1 }
    };
    int m2[Y][Z] = {
        { 4, -2, -4, -5 },
        { -7, -3, 6, 7 }
    };
    int r[X][Z];

    printf("矩阵 m1：\n");
    print_matrix(m1[0], X, Y);
    printf("✖️ 矩阵 m2：\n");
    print_matrix(m2[0], Y, Z);

    printf("结果为矩阵 r：\n");
    matrix_multiply(m1[0], m2[0], r[0], X, Y, Z);
    print_matrix(r[0], X, Z);

    return EXIT_SUCCESS;
}

void matrix_multiply(int *m1, int *m2, int *r, int x, int y, int z) {
    register unsigned ri, rj, k;


    // 外两层循环，遍历矩阵（二维数组）r[x][z]（如果看成是未压扁数组的话）
    for (ri = 0; ri < x; ++ri) {
        for (rj = 0; rj < z; ++rj) {
            // 内层循环，累加 m1 的 ri 行与 m2 的 rj 列各元素乘积
            // m1 每行与 m2 每列都是 y 个元素
            // ⬇️ 初始化表达式相当于 r[ri][rj] = 0（如果看成是未压扁数组的话）
            for (*(r + ri * z + rj) = 0, k = 0; k < y; ++k) {
                // ⬇️ 表达式相当于 r[ri][rj] += m1[ri][k] * m2[k][rj]（如果看成是未压扁数组的话）
                *(r + ri * z + rj) += *(m1 + ri * y + k) * *(m2 + k * z + rj);
            }
        }
    }
}

void print_matrix(int *m, int x, int y) {
    register unsigned mi, mj;

    for (mi = 0; mi < x; ++mi) {
        for (mj = 0; mj < y; ++mj) {
            printf("%d\t", *(m + mi * y + mj));
        }
        printf("\n");
    }
}