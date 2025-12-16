/**
 * @file     book-3-pointers-on-c/chapter-8/8-8/main.c
 * @author   mtueih
 * @date     2025-12-16 11:25
 * @brief    八皇后问题。
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

// N 皇后问题
#define N 8

// 棋盘（int_fast8_t 类型的二维数组）中：
// 0 表示可以放皇后；
// 1 表示不能放；
// 2 表示此处放置了皇后；
size_t find_solution(int_fast8_t chessboard[N][N]);
// 打印棋盘
void print_chessbord(int_fast8_t chessbord[N][N]);

int main(void)
{
    int_fast8_t chessboard[N][N];
    size_t i, j;
    size_t solution_num;

    // 初始化
    for (i = 0; i < N; ++i)
    {
        for (j = 0; j < N; ++j)
        {
            chessboard[i][j] = 0;
        }
    }

    // 寻找解法
    solution_num = find_solution(chessboard);

    printf("一共寻找到了 %zu 种解法！\n", solution_num);

    return EXIT_SUCCESS;
}

size_t find_solution(int_fast8_t chessboard[N][N])
{
    int_fast8_t chessboard_copy[N][N];

    static size_t current_row;
    size_t current_col;

    static size_t solution_num;
    
    // 在当前行尝试放置皇后
    for (current_col = 0; current_col < N; ++current_col)
    {
        // 如果找到可放置皇后的位置
        if (chessboard[current_row][current_col] == 0)
        {
            // 先拷贝原棋盘，对原棋盘的副本做修改
            size_t i, j;
            for (i = 0; i < N; ++i)
            {
                for (j = 0; j < N; ++j)
                {
                    chessboard_copy[i][j] = chessboard[i][j];
                }
            }

            // 找到可放置位置后，将该位置设置为 2，
            chessboard_copy[current_row][current_col] = 2;

            // 并将八个方向上的所有格子设置为 1，表示这些位置不能再放皇后
            // 在这八个方向上，如果是 1 或 2 则不用改，如果是 0，就改为 1
            register int count_row, count_col;
            int min_temp;
            // 水平方向
            for (j = 0; j < N; ++j)
            {
                if (chessboard_copy[current_row][j] == 0)
                {
                    chessboard_copy[current_row][j] = 1;
                }
            }
            // 垂直方向
            for (i = 0; i < N; ++i)
            {
                if (chessboard_copy[i][current_col] == 0)
                {
                    chessboard_copy[i][current_col] = 1;
                }
            }
            // 正对角线↘
            // 取当前行、列下标中的最小值
            size_t min = current_row > current_col ? current_col : current_row;

            for (i = current_row - min, j = current_col - min; 
                i < N && j < N; ++i, ++j
            )
            {
                if (chessboard_copy[i][j] == 0)
                {
                    chessboard_copy[i][j] = 1;
                }
            }

            // 反对角线↙
            // 取当前行下标，与「当前列下标与棋盘边界之间的距离」的最小值
            min = current_row > (N - current_col - 1) ? (N - current_col - 1) : current_row;

            for (i = current_row - min, j = current_col + min + 1; 
                i < N && j-- > 0; ++i
            )
            {
                if (chessboard_copy[i][j] == 0)
                {
                    chessboard_copy[i][j] = 1;
                }
            }

            // 如果当前行未达到行尾，就递归调用该函数
            // 将当前棋盘状态传递给下一层递归
            // 先递增全局变量 current_row，再递归调用，让下一层递归处理下一行
            if (current_row < N - 1)
            {
                ++current_row;
                find_solution(chessboard_copy);
            }
            else
            { 
                // 表示最后一行皇后已放置，则找到一种解法
                // 打印该解法，并递增解法的数量
                ++solution_num;
                print_chessbord(chessboard_copy);
            }
        }
    }

    // 在当前行都尝试放置过皇后之后
    // 或许是因为没有位置放置皇后，或许是所有放置的结果都尝试过了
    // 此时如果不是第一行，就递减当前行数，以让上一层递归继续处理上一行
    if (current_row > 0)
        --current_row;

    return solution_num;
}

void print_chessbord(int_fast8_t chessbord[N][N])
{
    size_t i, j;

    // 首行
    printf("┏");
    for (i = 0; i < N - 1; ++i)
    {
        printf("━━━┯");
    }
    printf("━━━┓\n");

    // 每行
    for (i = 0; i < N; ++i)
    {
        printf("┃");
        for (j = 0; j < N; ++j)
        {
            chessbord[i][j] == 2 ? printf(" Q ") : printf("   ");
            j == N - 1 ? printf("┃\n") : printf("│");
        }

        if (i != N - 1)
        {
            printf("┠");
            for (j = 0; j < N - 1; ++j)
            {
                printf("───┼");
            }
            printf("───┨\n");
        }
    }

    // 尾行
    printf("┗");
    for (i = 0; i < N - 1; ++i)
    {
        printf("━━━┷");
    }
    printf("━━━┛\n");
}